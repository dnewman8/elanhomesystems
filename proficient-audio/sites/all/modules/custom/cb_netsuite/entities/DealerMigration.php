<?php


class DealerMigration extends Migration {



    public function __construct($arguments) {
        parent::__construct($arguments);


        $this->description = t('Handles the migration of the dealers from the cached Netsuite data.');

        // Define the source.
        $query = db_select('ns_dealers', 'nd')
            ->fields('nd', [
                'dealer_id',
                'company',
                'email',
                'address1',
                'address2',
                'city',
                'country_code',
                'country_name',
                'phone',
                'state',
                'zipcode',
                'website',
                'type'
            ]);

        $this->source = new MigrateSourceSQL($query);

        // Define the destination.
        $this->destination = new MigrateDestinationNode('cb_dealer');

        // Save the orignal user id as reference.
        $this->map = new MigrateSQLMap($this->machineName,
            array(
                'dealer_id' => array(
                    'type' => 'int',
                    'not null' => true,
                    'description' => 'Netsuite internal id.'
                ),
            ),
            MigrateDestinationNode::getKeySchema()
        );

        // Map the fields.
        $this->addFieldMapping('uid')
            ->defaultValue(1);
        $this->addFieldMapping('title', 'company');
        $this->addFieldMapping('field_dealer_phone', 'phone');
        $this->addFieldMapping('field_dealer_email', 'email');
        $this->addFieldMapping('field_dealer_website', 'website');
        $this->addFieldMapping('field_dealer_type', 'type');

        $this->addFieldMapping('field_dealer_address', 'country_code');
        $this->addFieldMapping('field_dealer_address:locality', 'city');
        $this->addFieldMapping('field_dealer_address:thoroughfare', 'address1');
        $this->addFieldMapping('field_dealer_address:premise', 'address2');
        $this->addFieldMapping('field_dealer_address:administrative_area', 'state');
        $this->addFieldMapping('field_dealer_address:postal_code', 'zipcode');
    }

    /**
     * Cache items from Netsuite locally.
     */
    public function preImport() {
//        self::displayMessage(t("\nReceiving latest dealers from Netsuite"), 'status');
//
//        $controller = cb_netsuite_controller('Dealer');
//        $controller->import();
    }

    /**
     * Remove items that were deleted in the source.
     */
    public function postImport() {
        self::displayMessage(t("\nRemove Dealers that no longer exist in Netsuite."), 'status');

        // Find the items that were deleted in the netsuite table.
        $nids = db_select('migrate_map_dealer', 'd')
            ->fields('d', array('sourceid1', 'destid1'))
            ->condition('needs_update', 1)
            ->execute()
            ->fetchAllKeyed(0, 1);

        foreach ($nids as $source => $dest) {
            // Double-check, if the item doesn't exist any more.
            $exists = db_select('ns_dealers', 'nd')
                ->fields('nd', array('dealer_id'))
                ->condition('dealer_id', $source)
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
    }

    /**
     * Make changes to the source data before processing. Used to skip rows.
     * @param  object $row current row
     * @return boolean             TRUE to process. FALSE to skip.
     */
    public function prepareRow($row) {}

    /**
     * Make changes to the user entity after the row was imported.
     * @param  stdClass $resource resource object
     * @param  stdClass $row     original source row
     */
    public function prepare(stdClass $resource, stdClass $row) {}

}