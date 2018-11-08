<?php
/**
 * @file
 * cb_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_video_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cb_video_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cb_video_image_default_styles() {
  $styles = array();

  // Exported image style: video_thumbnail.
  $styles['video_thumbnail'] = array(
    'label' => 'Video Thumbnail (500x324)',
    'effects' => array(
      24 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 324,
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
function cb_video_node_info() {
  $items = array(
    'cb_video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Use <em>videos</em> to display clips from Youtube.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
