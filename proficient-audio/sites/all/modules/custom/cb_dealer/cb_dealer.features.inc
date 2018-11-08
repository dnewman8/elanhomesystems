<?php
/**
 * @file
 * cb_dealer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_dealer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cb_dealer_node_info() {
  $items = array(
    'cb_dealer' => array(
      'name' => t('Dealer'),
      'base' => 'node_content',
      'description' => t('Use <em>dealers</em> to create dealers, distributors and sales people.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
