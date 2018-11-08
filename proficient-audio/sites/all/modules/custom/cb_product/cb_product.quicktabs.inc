<?php
/**
 * @file
 * cb_product.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function cb_product_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'product_details';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Product Details';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'product_details',
      'display' => 'block_description',
      'args' => '',
      'use_title' => 0,
      'title' => 'Description',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'product_details',
      'display' => 'block_features',
      'args' => '',
      'use_title' => 0,
      'title' => 'Features',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'product_details',
      'display' => 'block_specs',
      'args' => '',
      'use_title' => 0,
      'title' => 'Specs',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'product_details',
      'display' => 'block_resources',
      'args' => '',
      'use_title' => 0,
      'title' => 'Resources',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'product_details',
      'display' => 'block_warranty',
      'args' => '',
      'use_title' => 0,
      'title' => 'Warranty',
      'weight' => '-96',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'default';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Features');
  t('Product Details');
  t('Resources');
  t('Specs');
  t('Warranty');

  $export['product_details'] = $quicktabs;

  return $export;
}
