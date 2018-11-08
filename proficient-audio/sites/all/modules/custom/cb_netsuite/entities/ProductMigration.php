<?php


class ProductMigration extends Migration {



    public function __construct($arguments) {
        parent::__construct($arguments);


        $this->description = t('Handles the migration of the products from the cached Netsuite data.');

        // Define the source.
        $query = db_select('ns_products', 'np')
            ->fields('np', [
                'product_id',
                'title',
                'model_number',
                'item_id',
                'category',
                'sub_category',
                'sub_type',
                'web_family',
                'introduction',
                'description',
                'features',
                'specifications',
                'warranty',
                'weight'
            ]);

        $this->source = new MigrateSourceSQL($query);

        // Define the destination.
        $this->destination = new MigrateDestinationNode('cb_product');

        // Save the orignal user id as reference.
        $this->map = new MigrateSQLMap($this->machineName,
            array(
                'product_id' => array(
                    'type' => 'int',
                    'not null' => true,
                    'description' => 'Netsuite internal id.'
                ),
            ),
            MigrateDestinationNode::getKeySchema()
        );

        // Map the fields.
        $this->addFieldMapping('title', 'title');
        $this->addFieldMapping('status')
            ->defaultValue(NODE_PUBLISHED);
        $this->addFieldMapping('uid')
            ->defaultValue(1);

        $this->addFieldMapping('field_product_model', 'model_number');
        $this->addFieldMapping('field_product_item_id', 'item_id');

        $this->addFieldMapping('field_product_introduction', 'introduction');
        $this->addFieldMapping('field_product_introduction:format')->defaultValue('full_html');
        $this->addFieldMapping('field_product_description', 'description');
        $this->addFieldMapping('field_product_description:format')->defaultValue('full_html');
        $this->addFieldMapping('field_product_features', 'features');
        $this->addFieldMapping('field_product_features:format')->defaultValue('full_html');
        $this->addFieldMapping('field_product_specs', 'specifications');
        $this->addFieldMapping('field_product_specs:format')->defaultValue('full_html');
        $this->addFieldMapping('field_product_resources', 'resources');
        $this->addFieldMapping('field_product_resources:format')->defaultValue('full_html');
        $this->addFieldMapping('field_product_warranty', 'warranty');
        $this->addFieldMapping('field_product_warranty:format')->defaultValue('full_html');
        $this->addFieldMapping('field_product_sort', 'weight');

        $this->addFieldMapping('field_product_category', 'category')
            ->sourceMigration('ProductCategory');
        $this->addFieldMapping('field_product_category:source_type')
            ->defaultValue('tid');

        $this->addFieldMapping('field_prod_sub_category', 'sub_category')
            ->sourceMigration('ProductSubCategory');
        $this->addFieldMapping('field_prod_sub_category:source_type')
            ->defaultValue('tid');

        $this->addFieldMapping('field_prod_sub_type', 'sub_type')
            ->sourceMigration('ProductSubType');
        $this->addFieldMapping('field_prod_sub_type:source_type')
            ->defaultValue('tid');

        $this->addFieldMapping('field_prod_web_family', 'web_family')
            ->sourceMigration('ProductWebFamily');
        $this->addFieldMapping('field_prod_web_family:source_type')
            ->defaultValue('tid');
    }

    /**
     * Make changes to the source data before processing. Used to skip rows.
     * @param  object $row current row
     * @return boolean             TRUE to process. FALSE to skip.
     */
    public function prepareRow($row) {
        if (empty($row->title) || empty($row->weight)) {
            return false;
        }
    }

    /**
     * Make changes to the user entity after the row was imported.
     * @param  stdClass $resource resource object
     * @param  stdClass $row     original source row
     */
    public function prepare(stdClass $resource, stdClass $row) {
        global $user;

        // Attach the images.
        $image_query = db_select('ns_product_images', 'npi');
        $image_query->join('ns_prod_img', 'pi', 'pi.image_id = npi.image_id');
        $image_query->fields('npi')
            ->fields('pi', ['product_id'])
            ->condition('product_id', $row->product_id)
            ->orderBy('npi.name', 'ASC');

        $image_result = $image_query->execute();

        $resource->field_product_image = [];

        while ($img = $image_result->fetchObject()) {

            // Check, if the file already exists.
            $destination_uri = 'public://_/products/' . $img->name;

            $existing_files = file_load_multiple(array(), array('uri' => $destination_uri));
            if (count($existing_files)) {
                $existing_image = reset($existing_files);
                $resource->field_product_image[LANGUAGE_NONE][] = [
                    'fid' => $existing_image->fid,
                    'display' => 1
                ];

            }
            else {
                // Check, if the remote file exists
                $header_response = get_headers($img->url, 1);

                if ( strpos( $header_response[0], "200" )) {
                    // Download the file to the proper destination and add.
                    $destination_filepath = DRUPAL_ROOT . '/' . variable_get('file_public_path', conf_path() . '/files') . '/_/products/' . $img->name;

                    try {
                        file_put_contents($destination_filepath, fopen($img->url, 'r'));
                        global $user;

                        $image = new stdClass();
                        $image->fid = NULL;
                        $image->uri = $destination_uri;
                        $image->filename = drupal_basename($destination_uri);
                        $image->filemime = file_get_mimetype($destination_filepath);
                        $image->uid      = $user->uid;
                        $image->status   = FILE_STATUS_PERMANENT;

                        if ($image = file_save($image)) {
                            // Attach the image to the product.
                            $resource->field_product_image[LANGUAGE_NONE][] = [
                                'fid' => $image->fid,
                                'display' => 1
                            ];
                        }
                    }
                    catch (Exception $e) {
                        watchdog('cb_netsuite', 'Cannot load remote image (:image). Error: ' . $e->getMessage(), [':image' => $img->url], WATCHDOG_ERROR);
                    }
                }
                else {
                    print_r($header_response);
                    watchdog('cb_netsuite', 'Remote image can not be loaded: :image ', [':image' => $img->url], WATCHDOG_ERROR);
                }
            }
        }

        // Attach the resources.
        $resource_query = db_select('ns_product_resources', 'npr');
        $resource_query->join('ns_prod_res', 'pr', 'pr.resource_id = npr.resource_id');
        $resource_query->fields('npr')
            ->fields('pr', ['product_id'])
            ->condition('product_id', $row->product_id)
            ->orderBy('npr.title', 'ASC');

        $resource_result = $resource_query->execute();
        $resource->field_product_resources = [];
        $resource_list = '';

        // Right now it's a simple text area. In the future we might switch it to a link field.
        while ($res = $resource_result->fetchObject()) {
            $resource_list .= '<li><a href="' . $res->url . '">' . $res->title . '</a></li>';
        }

        if ($resource_list) {
            $resource->field_product_resources[LANGUAGE_NONE][0]['value'] = '<ul>' . $resource_list . '</ul>';
            $resource->field_product_resources[LANGUAGE_NONE][0]['format'] = 'full_html';
        }

        // Make sure to clear the related products as this will be filled up
        // in the post import step.
        $resource->field_product_related = [];
    }

    /**
     * Remove items that were deleted in the source.
     */
    public function postImport() {

        self::displayMessage(t("\nSet product relations..."), 'status');
        // Relate the products according to the lookup table.
        $related = db_query('SELECT rel.product_id, mmp.destid1 as product_nid, rel.related_id, p.destid1 as related_nid
                FROM {migrate_map_product} mmp
                INNER JOIN {ns_prod_rel} rel ON rel.product_id = mmp.sourceid1
                INNER JOIN {migrate_map_product} p ON rel.related_id = p.sourceid1
                WHERE mmp.destid1 IS NOT NULL');

        foreach ($related as $rec) {
            // Load the product node.
            if ($product = node_load($rec->product_nid)) {
                if (!empty($rec->related_nid)) {
                    $product->field_product_related[LANGUAGE_NONE][]['target_id'] = $rec->related_nid;
                    node_save($product);
                }
            }
        }

        self::displayMessage(t("\nRemove Products that no longer exist in Netsuite..."), 'status');

        // Find the items that were deleted in the netsuite table.
        $nids = db_select('migrate_map_product', 'mmp')
            ->fields('mmp', array('sourceid1', 'destid1'))
            ->condition('needs_update', 1)
            ->execute()
            ->fetchAllKeyed(0, 1);

        foreach ($nids as $source => $dest) {
            // Double-check, if the item doesn't exist any more.
            $exists = db_select('ns_products', 'np')
                ->fields('np', array('product_id'))
                ->condition('product_id', $source)
                ->execute()
                ->fetchAll();

            // Delete the node and the mapping record.
            if (empty($exists)) {
                if (!empty($dest)) {
                    node_delete($dest);
                }

                if (!empty($source)) {
                    $this->getMap()->delete(array($source));
                }
            }
        }

        self::displayMessage(t("\nDone removing items..."), 'status');
    }
}
