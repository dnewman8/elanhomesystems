<?php
/**
 * @file
 * cb_faq.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_faq_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cb_faq_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cb_faq_node_info() {
  $items = array(
    'cb_faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => t('Use <em>FAQ</em> to generate frequently asked questions.'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
