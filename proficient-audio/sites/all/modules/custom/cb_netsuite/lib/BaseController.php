<?php

use GuzzleHttp\Client;
use GuzzleHttp\Psr7\Request;


abstract class BaseController
{
    protected $brand;
    protected $accountNumber;
    protected $host;
    protected $path;
    protected $consumerKey;
    protected $consumerSecret;
    protected $tokenId;
    protected $tokenSecret;


    public function __construct($params)
    {
        $this->brand = $params['brand'];
        $this->accountNumber = $params['accountNumber'];
        $this->host = $params['host'];
        $this->path = $params['path'];
        $this->consumerKey = $params['consumerKey'];
        $this->consumerSecret = $params['consumerSecret'];
        $this->tokenId = $params['tokenId'];
        $this->tokenSecret = $params['tokenSecret'];
    }

    /**
     * Request function to Netsuite. Every request is a POST request.
     *
     * @param array $body   Contains all the data to make a proper POST request.
     * @return mixed
     */
    protected function request($body, $debug = false)
    {
        // Generate the authentication string. This is taken from the sample code provided by David.
        // Netsuite doesn't have a clean OAuth 1.0 implementation. Therefore, we use the sample code, but
        // use Guzzle to send the request over.
        $consumer = new OAuthConsumer($this->consumerKey, $this->consumerSecret);
        $token = new OAuthToken($this->tokenId, $this->tokenSecret);
        $sig = new OAuthSignatureMethod_HMAC_SHA1(); //Signature
        $params = array(
            'oauth_nonce' => cb_netsuite_random_string(),
            'oauth_timestamp' => idate('U'),
            'oauth_version' => '1.0',
            'oauth_token' => $this->tokenId,
            'oauth_consumer_key' => $this->consumerKey,
            'oauth_signature_method' => $sig->get_name()
        );

        $url = 'https://' . $this->host . $this->path;

        $req = new OAuthRequest('POST', $url, $params);
        $req->set_parameter('oauth_signature', $req->build_signature($sig, $consumer, $token));
        $req->set_parameter('realm', $this->accountNumber);



        $auth_string = $req->to_header($this->accountNumber);
        // Clean up identifier.
        $auth_string = str_replace('Authorization: ', '', $auth_string);

        // Build the headers.
        $headers = [
            'Content-Type' => 'application/json',
            'Authorization' => $auth_string,
            'Host' => $this->host
        ];

        // Send the request and digest the response.
        $client = new Client();
        $request = new Request('POST', $url, $headers, json_encode($body));
        $response = $client->send($request);



        if ($debug) {
            $data['request'] = json_encode([
              'url' => $url,
              'headers' => $headers,
              'body' => $body
            ], JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES);

            $data_raw = json_decode($response->getBody());
            $data['response'] = json_encode($data_raw, JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES);
//            watchdog('cb_netsuite', '<h4>Headers:</h4><pre>:headers</pre><h4>Body:</h4><pre>:body</pre><h4>Request:</h4><pre>:request</pre><h4>Response:</h4><pre>:response</pre>', [
//                ':headers' => print_r($headers, TRUE),
//                ':body' => print_r($body, TRUE),
//                ':request' => print_r($request, TRUE),
//                ':response' => print_r($response, TRUE),
//            ], WATCHDOG_DEBUG);
        }
        else {
            $data = json_decode($response->getBody());
        }

        return $data;
    }

    /**
     * General test function for the connection.
     */
    public function connectionTest() {
        $postData = ['func' => 'connectionTest'];

        try {
            $response = $this->request($postData);
            return $response;
        }
        catch (Exception $e) {
            if ($e instanceof GuzzleHttp\Exception\ClientException) {
                $request = $e->getRequest();
                $response = $e->getResponse();
                watchdog('cb_netsuite', $response->getStatusCode() . ': ' . $response->getReasonPhrase(), [], WATCHDOG_ERROR);
                watchdog('cb_netsuite', '<h4>Request:</h4><pre>:request</pre><h4>Response:</h4><pre>:response</pre>', [
                  ':request' => print_r($request, TRUE),
                  ':response' => print_r($response, TRUE),
                ], WATCHDOG_DEBUG);
            }

            drupal_set_message($e->getMessage(), 'error');
        }
    }

    /**
     * Test the API basic functionality. Should be overridden in the child class
     * to make it specific for that resource.
     */
    public function testAPI() {
        $functions = [
            [
                'name'=> 'connectionTest',
                'params' => []
            ]
        ];

        foreach ($functions as $f) {
            drupal_set_message('Testing ' . $f['name'] . '...');
            $response = call_user_func_array([$this, $f['name']], $f['params']);

            if ($response) {
                drupal_set_message('OK');
            }
            else {
                drupal_set_message('FAIL');
            }
        }
    }

    /**
     * Import the items from the Netsuite backend into the Drupal table.
     */
    abstract public function import();


}
