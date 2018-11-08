<?php


class Dealer extends BaseController {
    protected $dbTable = 'ns_dealers';


    public function getDealers($debug = false) {
        try {
            $postData = [
                'func' => 'getDealer',
                'brands' => [$this->brand]
            ];

            $response = $this->request($postData,$debug);

            if ($debug) {
                return $response;
            }

            if ($response->success) {
                return $response->results;
            }
            else {
                watchdog('cb_netsuite', 'Dealer::getDealers: ' . $response->error, [], WATCHDOG_ERROR);
                return null;
            }
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Dealer::getDealers: ' . $e->getMessage(), [], WATCHDOG_ERROR);
        }
    }

    public function getDealerById($id) {
        try {
            $postData = [
                'func' => 'getDealer',
                'internalid' => [$id],
                'brands' => [$this->brand]
            ];

            $response = $this->request($postData);
            return $response;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Dealer::getDealerById (dealer :id): ' . $e->getMessage(), [':id' => $id], WATCHDOG_ERROR);
        }
    }

    public function getDealersByCategory($categoryId) {
        try {
            $postData = [
                'func' => 'getDealer',
                'brands' => [$this->brand],
                'category' => $categoryId
            ];

            $response = $this->request($postData);
            return $response;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Dealer::getDealersByBrand (category :category): ' . $e->getMessage(),
                [':category' => $categoryId], WATCHDOG_ERROR);
        }
    }


    /**
     * General test function for the API.
     */
    public function testAPI() {
        $dealerId = '207223'; // JMS
        $category = 1; // Dealer

        $timeTotal = 0;


        $functions = [
            [
                'name'=> 'getDealers',
                'params' => []
            ],
            [
                'name'=> 'getDealerById',
                'params' => [$dealerId]
            ],
            [
                'name'=> 'getDealersByCategory',
                'params' => [$category]
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
     * Import the dealers from Netsuite into a Drupal cache table.
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
        if ($dealers = $this->getDealers()) {
            // Clear the cache table.
            db_truncate($this->dbTable)->execute();

            // Write those records to the database.
            foreach ($dealers as $d) {
                $elite_sort = 0;

                if (!empty($d->brands)) {
                    if (property_exists($d->brands[0], 'sort')) {
                        $elite_sort = $d->brands[0]->sort;
                    }
                }

                db_insert($this->dbTable)
                    ->fields([
                        'dealer_id' => $d->internalid,
                        'company' => $d->companyname,
                        'email' => $d->email,
                        'address1' => $d->shipaddress1,
                        'address2' => $d->shipaddress2,
                        'city' => $d->shipcity,
                        'country_code' => !empty($d->shipcountry) ? $d->shipcountry->value : '',
                        'country_name' => !empty($d->shipcountry) ? $d->shipcountry->text : '',
                        'phone' => $d->phone,
                        'state' => $d->shipstate,
                        'zipcode' => $d->shipzip,
                        'type' => !empty($d->category) ? $d->category->value : 0,
                        'elite' => !empty($d->custentity_elite_program) ? $d->custentity_elite_program->value : 10,
                        'elite_sort' => $elite_sort,
                        'created_at' => time()
                    ])
                    ->execute();
            }

            $stats['time'] = time() - $startTime;
            $stats['count'] = count($dealers);

            watchdog('cb_netsuite', 'Cached !imgCount dealers locally in !timeElapsed seconds.',
                ['!imgCount' => $stats['count'], '!timeElapsed' => $stats['time']], WATCHDOG_INFO);
        }
        
        return $stats;
    }
}