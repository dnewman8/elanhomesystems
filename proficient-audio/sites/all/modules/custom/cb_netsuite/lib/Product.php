<?php

/**
 * Class Product
 *
 * Handles product specific requests to Netsuite.
 */
class Product extends BaseController {
    protected $productsTable = 'ns_products';
    protected $relatedTable = 'ns_prod_rel';
    protected $imageTable = 'ns_prod_img';
    protected $resourceTable = 'ns_prod_res';


    /**
     * Get products by brand
     * @param $brandId Netsuite internal brand id.
     * @return false, if empty and array of results, if successful.
     */
    public function getProducts($debug = false) {
        try {
            $postData = [
                'func' => 'getItems',
                'custrecord_reporting_brand' => $this->brand,
                'relateditems' => true,
                'resources' => true
            ];

            $response = $this->request($postData, $debug);

            if ($debug) {
                return $response;
            }

            if ($response->success) {
                return $response->results;
            }
            else {
                watchdog('cb_netsuite', 'Product::getProducts: ' . $response->error, [], WATCHDOG_ERROR);
                return null;
            }
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Product::getProducts: ' . $e->getMessage(), [], WATCHDOG_ERROR);
        }
    }

    /**
     * Get products by brand
     * @param $id Netsuite internal brand id.
     * @return false, if empty and array of results, if successful.
     */
    public function getProductsByBrand($id)
    {
        try {
            $postData = [
                'func' => 'getItems',
                'custitem_brand' => $id,
                'relateditems' => true,
                'resources' => true
            ];

            $response = $this->request($postData);
            return $response;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Product::getProductByBrand (brand :id): ' . $e->getMessage(),
                [':id' => $id], WATCHDOG_ERROR);
        }
    }

    /**
     * Get product by id
     * @param $id Netsuite internal product id.
     * @return false, if empty and array of results, if successful.
     */
    public function getProductById($id) {
        try {
            $postData = [
                'func' => 'getItems',
                'items' => [$id],
                'custrecord_reporting_brand' => $this->brand,
                'relateditems' => true,
                'resources' => true
            ];

            $response = $this->request($postData);
            return $response;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Product::getProductById (product :id): ' . $e->getMessage(),
                [':id' => $id], WATCHDOG_ERROR);
        }
    }

    /**
     * Get products by category
     * @param $categoryId Netsuite internal category id.
     * @param $brandId Netsuite internal brand id.
     * @return false, if empty and array of results, if successful.
     */
    public function getProductsByCategory($categoryId) {
        try {
            $postData = [
                'func' => 'getItems',
                'custitem_category' => [$categoryId],
                'custrecord_reporting_brand' => $this->brand,
                'relateditems' => true,
                'resources' => true
            ];

            $response = $this->request($postData);
            return $response;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Product::getProductsByCategory (category :category): ' . $e->getMessage(),
                [':category' => $categoryId], WATCHDOG_ERROR);
        }
    }

    /**
     * Get products by sub category
     * @param $subCategoryId Netsuite internal sub category id.
     * @param $brandId Netsuite internal brand id.
     * @return false, if empty and array of results, if successful.
     */
    public function getProductsBySubCategory($subCategoryId) {
        try {
            $postData = [
                'func' => 'getItems',
                'custitem_subcategory' => [$subCategoryId],
                'custrecord_reporting_brand' => $this->brand,
                'relateditems' => true,
                'resources' => true
            ];

            $response = $this->request($postData);
            return $response;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Product::getProductsBySubCategory (sub category :category): ' . $e->getMessage(),
                [':category' => $subCategoryId], WATCHDOG_ERROR);
        }
    }

    /**
     * Get products by sub type
     * @param $subTypeId Netsuite internal sub type id.
     * @param $brandId Netsuite internal brand id.
     * @return false, if empty and array of results, if successful.
     */
    public function getProductsBySubType($subTypeId) {
        try {
            $postData = [
                'func' => 'getItems',
                'custitem_subtype' => [$subTypeId],
                'custrecord_reporting_brand' => $this->brand,
                'relateditems' => true,
                'resources' => true
            ];

            $response = $this->request($postData);
            return $response;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Product::getProductsBySubType (sub type :category): ' . $e->getMessage(),
                [':category' => $subTypeId], WATCHDOG_ERROR);
        }
    }

    /**
     * Get all product categories, brands, sub categories, sub types and web families.
     * @return false, if empty and array of results, if successful.
     */
    public function getProductCategories() {
        try {
            $postData = [
                'func' => 'getBrandCategoriesIds',
                'custrecord_reporting_brand' => $this->brand
            ];

            $response = $this->request($postData);
            return $response;
        }
        catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
            watchdog('cb_netsuite', 'Product::getProductCategories: ' . $e->getMessage(),
                [], WATCHDOG_ERROR);
        }
    }

    /**
     * General test function for the API.
     */
    public function testAPI() {
        $productId = 2146; // GTS2B
        $category = 1; // Control
        $subCategory = 2; // System Controllers
        $subType = 6; // Software

        $timeTotal = 0;


        $functions = [
            [
                'name'=> 'getProductCategories',
                'params' => []
            ],
            [
                'name'=> 'getProducts',
                'params' => []
            ],
            [
                'name'=> 'getProductById',
                'params' => [$productId]
            ],
            [
                'name'=> 'getProductsByCategory',
                'params' => [$category]
            ],
            [
                'name'=> 'getProductsBySubCategory',
                'params' => [$subCategory]
            ],
            [
                'name'=> 'getProductsBySubType',
                'params' => [$subType]
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


    public function import() {
        $startTime = time();
        $stats = [
            'count' => 0,
            'time' => 0
        ];

        // Get the latest dealers for this brand from Netsuite.
        if ($products = $this->getProducts()) {
            // Clear the cache tables.
            db_truncate($this->productsTable)->execute();
            db_truncate($this->relatedTable)->execute();
            db_truncate($this->imageTable)->execute();
            db_truncate($this->resourceTable)->execute();

            // Write those records to the database.
            foreach ($products as $p) {

                // Import the product properties
                db_merge($this->productsTable)
                    ->key(['product_id' => $p->internalid])
                    ->fields([
                        'title' => $p->storedisplayname,
                        'model_number' => $p->custitemmodel_number,
                        'item_id' => $p->itemid,
                        'category' => !empty($p->custitem_category) ? $p->custitem_category->value : 0,
                        'sub_category' => !empty($p->custitem_subcategory) ? $p->custitem_subcategory->value : 0,
                        'sub_type' => !empty($p->custitem_subtype) ? $p->custitem_subtype->value : 0,
                        'web_family' => !empty($p->custitem_web_family) ? $p->custitem_web_family->value : 0,
                        'introduction' => $p->storedescription,
                        'description' => $p->storedetaileddescription,
                        'features' => $p->featureddescription,
                        'specifications' => $p->custitem_html_specifications,
                        'warranty' => $p->custitem_web_warranty,
                        'weight' => !empty($p->custitem_sort_order) ? $p->custitem_sort_order : 0,
                        'created_at' => time()
                    ])
                    ->execute();

                // Add the product image associations.
                if (!empty($p->images)) {
                    foreach($p->images as $img) {
                        db_insert($this->imageTable)
                            ->fields([
                                'product_id' => $p->internalid,
                                'image_id' => $img->internalid
                            ])
                            ->execute();
                    }
                }

                // Add the product resource associations.
                if (!empty($p->resources)) {
                    foreach($p->resources as $r) {
                        db_merge($this->resourceTable)
                            ->key(['product_id' => $p->internalid, 'resource_id' => $r->internalid])
                            ->fields([
                                'product_id' => $p->internalid,
                                'resource_id' => $r->internalid
                            ])
                            ->execute();
                    }
                }

                // Add the product related products.
                if (!empty($p->relateditems)) {
                    foreach($p->relateditems as $rel) {
                        db_insert($this->relatedTable)
                            ->fields([
                                'product_id' => $p->internalid,
                                'related_id' => $rel->internalid
                            ])
                            ->execute();
                    }
                }
            }

            $stats['time'] = time() - $startTime;
            $stats['count'] = count($products);

            watchdog('cb_netsuite', 'Cached !imgCount products locally in !timeElapsed seconds.',
                ['!imgCount' => $stats['count'], '!timeElapsed' => $stats['time']], WATCHDOG_INFO);
        }
        
        return $stats;
    }
}