<?php
/**
 * @file
 * cb_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cb_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cb_news_node_info() {
  $items = array(
    'cb_news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('Use <em>news</em> to create relevant articles on external sites.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
