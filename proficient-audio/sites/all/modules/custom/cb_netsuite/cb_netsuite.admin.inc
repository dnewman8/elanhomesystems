<?php

/**
 * @file
 *   Holds all admin forms and handlers.
 */

/**
 * Configuration settings form.
 */
function cb_netsuite_settings_form($form, &$form_state) {
    $form = array();

    $resources = [
        '' => t('- Select -'),
        'ProductCategory' => t('Categories'),
        'ProductImage' => t('Images'),
        'ProductResource' => t('Resources'),
        'Product' => t('Products'),
        'Dealer' => t('Dealers')
    ];

    $form['feed_test'] = [
        '#type' => 'fieldset',
        '#title' => t('Debug Feed'),
        '#collapsible' => true,
        '#collapsed' => false,
        '#description' => t('Download different items from the feed as a plain text file') . '<br>'
                        . t('This is for testing purposes only and does not import anything into Drupal.')
    ];

    $form['feed_test']['item_type'] = array(
        '#type' => 'select',
        '#title' => t('Item type'),
        '#options' => $resources,
        '#description' => '<p>' . t('Choose an item type for the raw feed download.') . '</p>'
    );

    $form['feed_test']['item_download'] = [
        '#type' => 'submit',
        '#value' => t('Download Items'),
        '#name' => 'item_download',
    ];

    $form['feed_test']['test_connection'] = [
        '#type' => 'submit',
        '#value' => t('Test Connection'),
        '#name' => 'test_connection',
    ];

    $form['feed_import'] = [
        '#type' => 'fieldset',
        '#title' => t('Import Feed Manually'),
        '#collapsible' => true,
        '#collapsed' => false,
        '#description' => '<p>' . t('Run the import script manually. It is a two step process where you first cache the 
                        data from Netsuite in the database.<br>Then it runs the migration script to update Drupal.') . '</p>'
                        . '<strong>' . t('This has a performance impact on all sites. Only run this for one site at a time!') .'</strong>'
    ];

    $form['feed_import']['import'] = [
        '#type' => 'submit',
        '#value' => t('Import'),
        '#name' => 'import',
    ];

    return $form;
}

/**
 * Validation handler for the Netsuite settings form.
 */
function cb_netsuite_settings_form_validate($form, &$form_state) {
    if ($form_state['clicked_button']['#name'] == 'item_download') {
        if (empty($class_name = $form_state['values']['item_type'])) {
            form_set_error('resource', t('You have to choose an item type.'));
        }
    }
}

/**
 * Submit handler for the Netsuite settings form.
 */
function cb_netsuite_settings_form_submit($form, $form_state) {
    switch ($form_state['clicked_button']['#name']) {
        case 'test_connection':
            $pc = cb_netsuite_controller('Product');

            try {
                $response = $pc->connectionTest();
                drupal_set_message('Connection successful: ' . $response->response);
            }
            catch (Exception $e) {

            }

            break;

        case 'item_download':

            $item_class = $form_state['values']['item_type'];
            $items = [];

            $controller = cb_netsuite_controller($item_class);
            $filename = 'netsuite_' . $item_class . '_' . date('d-m-Y') . '.txt';

            try {
                switch($item_class) {
                    case 'ProductImage':
                        $items = $controller->getImages(true);
                        break;

                    case 'ProductCategory' :
                        $items = $controller->getCategories(true);
                        break;

                    case 'ProductResource':
                        $items = $controller->getResources(true);
                        break;

                    case 'Product':
                        $items = $controller->getProducts(true);
                        break;

                    case 'Dealer':
                        $items = $controller->getDealers(true);
                        break;
                }
            }
            catch(Exception $e) {}

            // Prepare the CSV.
            $fh = fopen('php://output', 'w');

            fwrite($fh, print_r($items, TRUE));

            // Set the headers for file handling.
            drupal_add_http_header('Content-Type', 'text/plain; utf-8');
            drupal_add_http_header('Content-Disposition', 'attachment; filename = ' . $filename);

            fclose($fh);

            module_invoke_all('exit');
            exit();

            break;

        case 'import':
            $cache_items = [
                'ProductCategory' => t('Categories'),
                'ProductImage' => t('Images'),
                'ProductResource' => t('Resources'),
                'Product' => t('Products'),
                'Dealer' => t('Dealers')
            ];

            $import_items = [
                'ProductCategory' => t('Categories'),
                'ProductSubCategory' => t('Sub Categories'),
                'ProductSubType' => t('Sub Types'),
                'Product' => t('Products')
            ];



            $operations = [];

            // Prepare caching operations.
            foreach($cache_items as $class => $name) {
                $operations[] = [
                    'cb_netsuite_cache',
                    [$class, $name]
                ];
            }

            // Prepare import operations.
            foreach ($import_items as $class => $name) {
                $operations[] = [
                    'cb_netsuite_import',
                    [$class, $name]
                ];
            }

            $batch = [
                'title' => t('Import Netsuite items manually'),
                'operations' => $operations,
                'finished' => 'cb_netsuite_cache_finished',
                'file' => drupal_get_path('module', 'cb_netsuite') . '/cb_netsuite.admin.inc',
            ];

            batch_set($batch);

            break;
    }
}


function cb_netsuite_cache($class, $name, &$context) {
    $controller = cb_netsuite_controller($class);
    $stats = $controller->import();


    $context['results'][] = t('Cached !count !name (!time seconds).',
        ['!count' => $stats['count'], '!time' => $stats['time'], '!name' => $name]);
    $context['message'] = t('Cached !count !name in !time seconds.',
        ['!count' => $stats['count'], '!time' => $stats['time'], '!name' => $name]);
}

function cb_netsuite_import($class, $name, &$context) {
    $migration = Migration::getInstance($class);
    $migration->prepareUpdate();
    $migration->processImport(['update' => true]);


//    $context['results'][] = $name;
    $context['message'] = 'Imported ' . $name;
}

function cb_netsuite_cache_finished($success, $results, $operations) {
    if ($success) {
        foreach ($results as $res) {
            drupal_set_message($res);
        }
        drupal_set_message('Import completed successfully!');
    }
    else {
        drupal_set_message(t('Finished with an error.'));
    }
}
