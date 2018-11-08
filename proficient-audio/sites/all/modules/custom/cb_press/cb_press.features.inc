<?php
/**
 * @file
 * cb_press.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_press_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cb_press_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cb_press_image_default_styles() {
  $styles = array();

  // Exported image style: author_square.
  $styles['author_square'] = array(
    'label' => 'Author Square (75x75)',
    'effects' => array(
      23 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 75,
          'height' => 75,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cb_press_node_info() {
  $items = array(
    'cb_press' => array(
      'name' => t('Press Release'),
      'base' => 'node_content',
      'description' => t('Use <em>press releases</em> to create company produced press items.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
