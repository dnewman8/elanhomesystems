<?php

function cb_netsuite_migrate_api() {
    $api = [
        'api' => 2,
        'groups' => [
            'netsuite' =>[
                'title' => t('Netsuite'),
            ]
        ],
        'migrations' => [
            'ProductCategory' => [
                'class_name' => 'ProductCategoryMigration',
                'group_name' => 'netsuite'
            ],
            'ProductSubCategory' => [
                'class_name' => 'ProductSubCategoryMigration',
                'group_name' => 'netsuite'
            ],
            'ProductSubType' => [
                'class_name' => 'ProductSubTypeMigration',
                'group_name' => 'netsuite'
            ],
            'ProductWebFamily' => [
                'class_name' => 'ProductWebFamilyMigration',
                'group_name' => 'netsuite'
            ],
            'Product' => [
                'class_name' => 'ProductMigration',
                'group_name' => 'netsuite'
            ],
            'Dealer' => [
                'class_name' => 'DealerMigration',
                'group_name' => 'netsuite'
            ]
        ]
    ];

    return $api;
}