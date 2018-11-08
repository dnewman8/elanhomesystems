<?php

if (!defined('COREBRANDS_DOMAIN')) {
  define('COREBRANDS_DOMAIN', '');
}
if (!defined('COREBRANDS_BRAND')) {
  define('COREBRANDS_BRAND', '');
}

if (!defined('NETSUITE_BRAND')) {
  define('NETSUITE_BRAND', '');
}
if (!defined('NETSUITE_ACCOUNT')) {
  define('NETSUITE_ACCOUNT', '');
}
if (!defined('NETSUITE_HOST')) {
  define('NETSUITE_HOST', '');
}
if (!defined('NETSUITE_PATH')) {
  define('NETSUITE_PATH', '');
}
if (!defined('NETSUITE_CONSUMER_KEY')) {
  define('NETSUITE_CONSUMER_KEY', '');
}
if (!defined('NETSUITE_CONSUMER_SECRET')) {
  define('NETSUITE_CONSUMER_SECRET', '');
}
if (!defined('NETSUITE_TOKEN_ID')) {
  define('NETSUITE_TOKEN_ID', '');
}
if (!defined('NETSUITE_TOKEN_SECRET')) {
  define('NETSUITE_TOKEN_SECRET', '');
}

if (!defined('ADROLL_ADV_ID')) {
  define('ADROLL_ADV_ID', '');
}
if (!defined('ADROLL_PIX_ID')) {
  define('ADROLL_PIX_ID', '');
}

if (defined('PANTHEON_ENVIRONMENT')) {
  if (
    $_ENV['PANTHEON_ENVIRONMENT'] == 'live' ||
    $_ENV['PANTHEON_ENVIRONMENT'] == 'test'
  ) {
    define('COREBRANDS_ENV', $_ENV['PANTHEON_ENVIRONMENT']);

    // $conf['cache'] = 1;
    // $conf['block_cache'] = 1;
    // $conf['page_compression'] = 0;
    // $conf['preprocess_css'] = 1;
    // $conf['preprocess_js'] = 1;
  }
  else {
    define('COREBRANDS_ENV', 'dev');

    // $conf['cache'] = 0;
    // $conf['block_cache'] = 0;
    // $conf['cache_lifetime'] = 0;
    // $conf['page_cache_maximum_age'] = 0;
    // $conf['page_compression'] = 0;
    // $conf['preprocess_css'] = 0;
    // $conf['preprocess_js'] = 0;
  }
}
else {
  define('COREBRANDS_ENV', 'dev');
}

$conf['shortcut_max_slots'] = 12;

$conf['x_frame_options'] = '';
