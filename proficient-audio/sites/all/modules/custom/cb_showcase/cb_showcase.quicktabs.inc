<?php
/**
 * @file
 * cb_showcase.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function cb_showcase_quicktabs_default_quicktabs() {
  $brand_id = variable_get('ns_brand');
  $brands = function_exists('cb_netsuite_getBrands') ? cb_netsuite_getBrands() : [];
  $brand_name = (isset($brands[$brand_id]) && !empty($brands[$brand_id])) ? $brands[$brand_id] : 'Gallery';



  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'gallery_tab';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Gallery Tab';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'showcase_listing',
      'display' => 'block_2',
      'args' => '',
      'use_title' => 0,
      'title' => 'All',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'showcase_listing',
      'display' => 'block',
      'args' => '',
      'use_title' => 0,
      'title' => 'Commercial',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'showcase_listing',
      'display' => 'block_1',
      'args' => '',
      'use_title' => 0,
      'title' => 'Residential',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'default';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('All');
  t('Commercial');
  t('Gallery Tab');
  t('Residential');

  $export['gallery_tab'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'see_elan';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = t('See @brand', ['@brand' => $brand_name]);
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'showcases',
      'display' => 'block_1',
      'args' => '',
      'use_title' => 0,
      'title' => 'Residential',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'showcases',
      'display' => 'block_2',
      'args' => '',
      'use_title' => 0,
      'title' => 'Commercial',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'default';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Commercial');
  t('Residential');
  t('See @brand', ['@brand' => $brand_name]);

  $export['see_elan'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'showcase_details';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Showcase Details';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'showcase_details',
      'display' => 'block',
      'args' => '',
      'use_title' => 0,
      'title' => 'Description',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'showcase_details',
      'display' => 'block_1',
      'args' => '',
      'use_title' => 0,
      'title' => 'Features',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'showcase_details',
      'display' => 'block_2',
      'args' => '',
      'use_title' => 0,
      'title' => 'Equipment',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'default';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Equipment');
  t('Features');
  t('Showcase Details');

  $export['showcase_details'] = $quicktabs;

  return $export;
}
