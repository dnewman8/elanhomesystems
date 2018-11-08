<?php

/**
 * @file
 * Drupal site-specific configuration file.
 */

define('COREBRANDS_DOMAIN', 'elanhomesystems.com');
define('COREBRANDS_BRAND', 'ELAN');

define('NETSUITE_BRAND', 3);
define('NETSUITE_RESOURCE_BRAND', 33);
define('NETSUITE_ACCOUNT', 3468268);
define('NETSUITE_HOST', 'rest.na2.netsuite.com');
define('NETSUITE_PATH', '/app/site/hosting/restlet.nl?script=1466&deploy=1');
define('NETSUITE_CONSUMER_KEY', '5974a7fa07f5e2d30fd6d94317528c064e7d13acf657258798b217cd5e0ac307');
define('NETSUITE_CONSUMER_SECRET', 'eb5524797e0fc2a8df6c0723788e2ae2a918c16e73bbf033f6bafe45c5bcd4eb');
define('NETSUITE_TOKEN_ID', '80777aca335593ebc9e0fbdc9fea8f51423361d4af4df6e0d36edd3fd815cce5');
define('NETSUITE_TOKEN_SECRET', 'af8642a68dec85dab82dc2cf6c4393fc27972f16060ff7801b6d922bf0bd50f5');


if (defined('PANTHEON_ENVIRONMENT')) {
    if ($_ENV['PANTHEON_ENVIRONMENT'] == 'live') {
        define('GA_CODE', 'UA-2201870-11');

        define('ADROLL_ADV_ID', 'VTMN2ABMCJAVLCS4CGWUDY');
        define('ADROLL_PIX_ID', 'LTQTP4TCKNADLN2HQPZRTO');
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
