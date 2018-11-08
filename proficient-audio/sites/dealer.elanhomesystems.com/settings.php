<?php

/**
 * @file
 * Drupal site-specific configuration file.
 */

define('COREBRANDS_DOMAIN', 'dealer.elanhomesystems.com');
define('COREBRANDS_BRAND', 'DEALER ELAN');

include_once DRUPAL_ROOT . '/sites/default/settings.php';

/**
 * Override settings locally, if the file exists.
 */
$local_settings = __DIR__ . '/settings.local.php';

if (file_exists($local_settings)) {
    include_once $local_settings;
}
