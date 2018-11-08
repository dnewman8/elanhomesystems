<?php

/**
 * Implements hook_drush_command().
 */
function cb_netsuite_drush_command() {

    $items['netsuite-import'] = [
        'description' => 'Cache items locally from Netsuite.',
        'aliases' => ['nsi'],
        'arguments' => [
            'resource' => 'The type of resource to import.',
        ]
    ];

    return $items;
}


/**
 * Callback for the drush-demo-command command
 */
function drush_cb_netsuite_netsuite_import($resource = null) {

    $resource_list = [
        'categories' => 'ProductCategory',
        'images' => 'ProductImage',
        'resources' => 'ProductResource',
        'products' => 'Product',
        'dealers' => 'Dealer'
    ];

    if ($resource == 'test') {
        // Little tool to make sure the basic connection to Netsuite is working.
        $controller = cb_netsuite_controller('Product');
        print_r($controller->connectionTest());
    }
    else if ($resource == 'all') {
        drupal_set_message(t('Importing all entities...'));
        foreach ($resource_list as $id => $name) {
            $controller = cb_netsuite_controller($name);

            $stats = $controller->import();

            drupal_set_message(t('Cached !count !resource successfully in !time seconds.',
                ['!count' => $stats['count'], '!time' => $stats['time'], '!resource' => $name]));
        }
    }
    else if (empty($resource) ||  !in_array($resource, array_keys($resource_list))) {
        return drush_set_error(dt('"@resource" is not a valid statement type. {dealers|products|categories|images}.', array('@resource' => $resource)));
    }
    else {
        // Load the controller for this resource.
        $controller = cb_netsuite_controller($resource_list[$resource]);

        $stats = $controller->import();

        drupal_set_message(t('Cached !count !resource successfully in !time seconds.',
            ['!count' => $stats['count'], '!time' => $stats['time'], '!resource' => $resource]));
    }
}