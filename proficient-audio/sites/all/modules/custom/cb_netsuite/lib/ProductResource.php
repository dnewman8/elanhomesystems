<?php


class ProductResource extends BaseController {
    protected $dbTable = 'ns_product_resources';


    /**
     * Get all resources for the given brand.
     * @return false, if empty and array of results, if successful.
     */
    public function getResources($debug = false) {
        try {
            $postData = [
                'func' => 'getResources',
                'custrecord_reporting_brand' => $this->brand
            ];

            // Due to the Netsuite structure, some brands need to give here 2 brand ids
            // for a proper query.
            if (defined('NETSUITE_RESOURCE_BRAND')) {
                $postData['custrecord_reporting_brand'] = [$this->brand, NETSUITE_RESOURCE_BRAND];
            }

            $response = $this->request($postData, $debug);

            if ($debug) {
                return $response;
            }

            if ($response->success) {
                return $response->results;
            }
            else {
                watchdog('cb_netsuite', 'Resource::getResources: ' . $response->error, [], WATCHDOG_ERROR);
                return null;
            }
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Resource::getResources: ' . $e->getMessage(), [], WATCHDOG_ERROR);
        }
    }


    /**
     * General test function for the API.
     */
    public function testAPI() {
        $timeTotal = 0;


        $functions = [
            [
                'name'=> 'getResources',
                'params' => []
            ]
        ];


        foreach ($functions as $f) {
            drupal_set_message('Testing ' . $f['name'] . '...');
            $startTime = time();
            $response = call_user_func_array([$this, $f['name']], $f['params']);

            if ($response) {
                $timeElapsed = time() - $startTime;
                drupal_set_message('OK (' . $timeElapsed . ' seconds)');
                $timeTotal += $timeElapsed;
            }
            else {
                drupal_set_message('FAIL');
            }
        }

        drupal_set_message('Total time elapsed: ' . $timeTotal . ' seconds.');
    }


    /**
     * Import the resources from Netsuite into a Drupal cache table.
     *
     * @return array Statistics.
     */
    public function import() {
        $startTime = time();
        $stats = [
            'count' => 0,
            'time' => 0
        ];

        // Get the latest dealers for this brand from Netsuite.
        if ($resources = $this->getResources()) {
            // Clear the cache table.
            db_truncate($this->dbTable)->execute();

            // Write those records to the database.
            foreach ($resources as $r) {
                db_insert($this->dbTable)
                    ->fields([
                        'resource_id' => $r->internalid,
                        'title' => $r->title,
                        'filename' => $r->filename,
                        'type' => $r->type,
                        'typeid' => $r->typeid,
                        'url' => $r->url,
                        'created_at' => time()
                    ])
                    ->execute();

                $stats['count']++;
            }

            $stats['time'] = time() - $startTime;

            watchdog('cb_netsuite', 'Cached !imgCount product resources locally in !timeElapsed seconds.',
                ['!imgCount' => $stats['count'], '!timeElapsed' => $stats['time']], WATCHDOG_INFO);
        }

        return $stats;
    }
}
