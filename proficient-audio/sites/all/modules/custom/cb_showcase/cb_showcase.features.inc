<?php
/**
 * @file
 * cb_showcase.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function cb_showcase_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_showcase_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cb_showcase_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cb_showcase_image_default_styles() {
  $styles = array();

  // Exported image style: gallery_carousel.
  $styles['gallery_carousel'] = array(
    'label' => 'Gallery Carousel (1000x800)',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 800,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_full.
  $styles['gallery_full'] = array(
    'label' => 'Gallery Full (1500x1000)',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1500,
          'height' => 1000,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_landscape.
  $styles['gallery_landscape'] = array(
    'label' => 'Gallery Landscape (800x400)',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 400,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_listing.
  $styles['gallery_listing'] = array(
    'label' => 'Gallery Listing (500x500)',
    'effects' => array(
      24 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_portrait.
  $styles['gallery_portrait'] = array(
    'label' => 'Gallery Portrait (400x800)',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 800,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_square.
  $styles['gallery_square'] = array(
    'label' => 'Gallery Square (400x400)',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 400,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_thumbnail.
  $styles['gallery_thumbnail'] = array(
    'label' => 'Gallery Thumbnail (370x240)',
    'effects' => array(
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 370,
          'height' => 240,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: showcase_carousel.
  $styles['showcase_carousel'] = array(
    'label' => 'Showcase Carousel (800x720)',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 720,
          'retinafy' => 0,
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
function cb_showcase_node_info() {
  $items = array(
    'cb_showcase' => array(
      'name' => t('Showcase'),
      'base' => 'node_content',
      'description' => t('Use <em>showcases</em> to create gallery items.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
