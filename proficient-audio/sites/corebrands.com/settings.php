<?php

/**
 * @file
 * Drupal site-specific configuration file.
 */

define('COREBRANDS_DOMAIN', 'corebrands.com');
define('COREBRANDS_BRAND', 'Corebrands');

if (defined('PANTHEON_ENVIRONMENT')) {
    if ($_ENV['PANTHEON_ENVIRONMENT'] == 'live') {
        define('ADROLL_ADV_ID', 'E3NBSUJATFAGFIZNFTDOS4');
        define('ADROLL_PIX_ID', 'ECAEWLZ6CBFADMUPU5M3KK');

        define('GA_CODE', 'UA-2201870-6');
    }
}

include_once DRUPAL_ROOT . '/sites/default/settings.php';

/**
 * Override settings locally, if the file exists.
 */
$local_settings = __DIR__ . '/settings.local.php';

if (file_exists($local_settings)) {
    include_once $local_settings;
}
