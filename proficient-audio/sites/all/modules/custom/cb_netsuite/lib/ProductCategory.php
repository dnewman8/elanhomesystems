<?php


class ProductCategory extends BaseController {
    protected $dbTable = 'ns_product_categories';


    /**
     * Get all product brands.
     * @return false, if empty and array of results, if successful.
     */
    public function getBrands() {
        try {
            $postData = [
                'func' => 'getBrandCategoriesIds'
            ];

            $response = $this->request($postData);
            return $response->custitem_brand;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'ProductCategory::getBrands: ' . $e->getMessage(), [], WATCHDOG_ERROR);
        }
    }

    /**
     * Get all product categories.
     * @return false, if empty and array of results, if successful.
     */
    public function getCategories($debug = false) {
        try {
            $postData = [
                'func' => 'getBrandCategoriesIds'
            ];

            $response = $this->request($postData, $debug);

            if ($debug) {
                return $response;
            }

            return $response->custitem_category;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'ProductCategory::getCategories: ' . $e->getMessage(), [], WATCHDOG_ERROR);
        }
    }

    /**
     * Get all product sub categories.
     * @return false, if empty and array of results, if successful.
     */
    public function getSubCategories() {
        try {
            $postData = [
                'func' => 'getBrandCategoriesIds'
            ];

            $response = $this->request($postData);
            return $response->custitem_subcategory;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'ProductCategory::getSubCategories: ' . $e->getMessage(), [], WATCHDOG_ERROR);
        }
    }

    /**
     * Get all product sub types.
     * @return false, if empty and array of results, if successful.
     */
    public function getSubTypes() {
        try {
            $postData = [
                'func' => 'getBrandCategoriesIds'
            ];

            $response = $this->request($postData);
            return $response->custitem_subtype;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'ProductCategory::getSubTypes: ' . $e->getMessage(), [], WATCHDOG_ERROR);
        }
    }

    /**
     * Get all product categories in its raw form.
     * @return false, if empty and array of results, if successful.
     */
    public function getCategoriesRaw() {
        try {
            $postData = [
                'func' => 'getBrandCategoriesIds'
            ];

            $response = $this->request($postData);

            if ($response->success) {
                return $response;
            }
            else {
                watchdog('cb_netsuite', 'ProductCategory::getCategoriesRaw: ' . $response->error, [], WATCHDOG_ERROR);
                return null;
            }
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'ProductCategory::getCategoriesRaw: ' . $e->getMessage(), [], WATCHDOG_ERROR);
        }
    }


    /**
     * General test function for the API.
     */
    public function testAPI() {
        $timeTotal = 0;

        $functions = [
            [
                'name'=> 'getCategoriesRaw',
                'params' => []
            ],

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

        $categoryTypes = [
            'brand',
            'category',
            'subcategory',
            'subtype',
            'web_family'
        ];

        // Get the latest dealers for this brand from Netsuite.
        if ($categoriesRaw = $this->getCategoriesRaw()) {
            // Clear the cache table.
            db_truncate($this->dbTable)->execute();

            // Write those records to the database.
            foreach ($categoryTypes as $type) {
                $propName = 'custitem_' . $type;

                foreach ($categoriesRaw->$propName as $item) {
                    db_merge($this->dbTable)
                        ->key(['category_id' => $item->id, 'type' => $type])
                        ->fields([
                            'name' => $item->text,
                            'created_at' => time()
                        ])
                        ->execute();

                    $stats['count']++;
                }
            }

            $stats['time'] = time() - $startTime;

            watchdog('cb_netsuite', 'Cached !catCount product categories locally in !timeElapsed seconds.',
                ['!catCount' => $stats['count'], '!timeElapsed' => $stats['time']], WATCHDOG_INFO);
        }
        
        return $stats;
    }
}