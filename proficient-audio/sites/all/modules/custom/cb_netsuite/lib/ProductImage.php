<?php


class ProductImage extends BaseController {
    protected $dbTable = 'ns_product_images';


    /**
     * Get all image for the given brand.
     * @return false, if empty and array of results, if successful.
     */
    public function getImages($debug = false) {
        try {
            $postData = [
                'func' => 'getImages',
                'custrecord_reporting_brand' => $this->brand
            ];

            $response = $this->request($postData, $debug);

            if ($debug) {
                return $response;
            }

            if ($response->success) {
                return $response->results;
            }
            else {
                watchdog('cb_netsuite', 'Image::getImages: ' . $response->error, [], WATCHDOG_ERROR);
                return null;
            }

        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Image::getImages: ' . $e->getMessage(), [], WATCHDOG_ERROR);
        }
    }

    /**
     * Get an image by its id.
     *
     * @param $id Netsuite internal id.
     * @return false, if empty and array of results, if successful.
     */
    public function getImageById($id) {
        try {
            $postData = [
                'func' => 'getImages',
                'items' => [$id],
                'custrecord_reporting_brand' => $this->brand
            ];

            $response = $this->request($postData);
            return $response->results;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Image::getImageById (image :id): ' . $e->getMessage(), [':id' => $id], WATCHDOG_ERROR);
        }
    }

    /**
     * Get all image for a product category.
     *
     * @param $categoryId Netsuite internal id.
     * @return false, if empty and array of results, if successful.
     */
    public function getImagesByCategory($categoryId) {
        try {
            $postData = [
                'func' => 'getImages',
                'custrecord_reporting_brand' => $this->brand,
                'custitem_category' => $categoryId
            ];

            $response = $this->request($postData);
            return $response;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Image::getImagesByCategory (category :category): ' . $e->getMessage(),
                [':category' => $categoryId], WATCHDOG_ERROR);
        }
    }


    /**
     * General test function for the API.
     */
    public function testAPI() {
        $image = 12999; // JMS
        $category = 1; // Dealer

        $timeTotal = 0;


        $functions = [
            [
                'name'=> 'getImages',
                'params' => []
            ],
            [
                'name'=> 'getImageById',
                'params' => [$image]
            ],
            [
                'name'=> 'getImagesByCategory',
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
     * Import the images from Netsuite into a Drupal cache table.
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
        if ($images = $this->getImages()) {
            // Clear the cache table.
            db_truncate($this->dbTable)->execute();

            // Write those records to the database.
            foreach ($images as $img) {
                db_insert($this->dbTable)
                    ->fields([
                        'image_id' => $img->internalid,
                        'name' => $img->name,
                        'url' => $img->url,
                        'created_at' => time()
                    ])
                    ->execute();

                $stats['count']++;
            }

            $stats['time'] = time() - $startTime;

            watchdog('cb_netsuite', 'Cached !imgCount product images locally in !timeElapsed seconds.',
                ['!imgCount' => $stats['count'], '!timeElapsed' => $stats['time']], WATCHDOG_INFO);
        }

        return $stats;
    }
}