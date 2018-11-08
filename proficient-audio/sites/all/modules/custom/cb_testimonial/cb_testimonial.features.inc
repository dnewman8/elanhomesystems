<?php
/**
 * @file
 * cb_testimonial.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_testimonial_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cb_testimonial_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cb_testimonial_node_info() {
  $items = array(
    'cb_testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => t('Use <em>testimonials</em> to create customer feedback.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
