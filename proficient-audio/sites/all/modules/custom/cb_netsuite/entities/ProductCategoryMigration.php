<?php


class ProductCategoryMigration extends Migration {

    public function __construct($arguments) {
        parent::__construct($arguments);


        $this->description = t('Handles the migration of the product categories from the cached Netsuite data.');

        // Define the source.
        $query = db_select('ns_product_categories', 'np')
            ->fields('np', [
                'category_id',
                'type',
                'name'
            ])
            ->condition('type', 'category', '=');

        $this->source = new MigrateSourceSQL($query);

        // Define the destination.
        $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');
        $term_options = MigrateDestinationTerm::options(LANGUAGE_NONE, 'full_html');
        $this->destination = new MigrateDestinationTerm('product_category', $term_options);

        // Save the original category id as reference.
        $this->map = new MigrateSQLMap($this->machineName,
            array(
                'category_id' => array(
                    'type' => 'int',
                    'not null' => true,
                    'description' => 'Netsuite internal id.'
                ),
            ),
            MigrateDestinationTerm::getKeySchema()
        );


        // Map the fields.
        $this->addFieldMapping('name', 'name');
    }

    /**
     * Cache items from Netsuite locally.
     */
    public function preImport() {
//        self::displayMessage(t("\nReceiving latest categories from Netsuite..."), 'status');
//
//        $controller = cb_netsuite_controller('ProductCategory');
//        $controller->import();
    }

    /**
     * Remove items that were deleted in the source.
     */
    public function postImport() {

        // Find the items that were deleted in the netsuite table.
        $nids = db_select('migrate_map_productcategory', 'mmp')
            ->fields('mmp', array('sourceid1', 'destid1'))
            ->condition('needs_update', 1)
            ->execute()
            ->fetchAllKeyed(0, 1);

        foreach ($nids as $source => $dest) {
            // Double-check, if the item doesn't exist any more.
            $exists = db_select('ns_product_categories', 'npc')
                ->fields('npc', array('category_id'))
                ->condition('category_id', $source)
                ->condition('type', 'category', '=')
                ->execute()
                ->fetchAll();

            // Delete the node and the mapping record.
            if (empty($exists)) {
                node_delete($dest);
                $this->getMap()->delete(array($source));
            }
        }
    }

    /**
     * Make changes to the source data before processing. Used to skip rows.
     * @param  object $row current row
     * @return boolean             TRUE to process. FALSE to skip.
     */
    public function prepareRow($row) {
        // Removed unwanted characters from the name.
        $row->name = str_replace('/', '', $row->name);
    }

    /**
     * Make changes to the entity after the row was imported.
     * @param  stdClass $resource resource object
     * @param  stdClass $row     original source row
     */
    public function prepare(stdClass $resource, stdClass $row) {

    }

}