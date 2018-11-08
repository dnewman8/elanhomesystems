<?php
/**
 * @file
 * cb_rotato.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_rotato_ctools_plugin_api($module = NULL, $api = NULL) {
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
function cb_rotato_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cb_rotato_image_default_styles() {
  $styles = array();

  // Exported image style: rotato_full.
  $styles['rotato_full'] = array(
    'label' => 'Rotato Full (1500x750)',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1500,
          'height' => 750,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotato_full_medium.
  $styles['rotato_full_medium'] = array(
    'label' => 'Rotato Full - Medium (900x450)',
    'effects' => array(
      24 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 900,
          'height' => 450,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotato_full_short.
  $styles['rotato_full_short'] = array(
    'label' => 'Rotato Full short (1500x560)',
    'effects' => array(
      30 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1500,
          'height' => 560,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotato_full_short_medium.
  $styles['rotato_full_short_medium'] = array(
    'label' => 'Rotato Full short - Medium (900x336)',
    'effects' => array(
      31 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 900,
          'height' => 336,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotato_full_short_small.
  $styles['rotato_full_short_small'] = array(
    'label' => 'Rotato Full short - Small (500x187)',
    'effects' => array(
      32 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 187,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotato_full_small.
  $styles['rotato_full_small'] = array(
    'label' => 'Rotato Full - Small (500x250)',
    'effects' => array(
      25 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotato_landscape.
  $styles['rotato_landscape'] = array(
    'label' => 'Rotato Landscape (1000x750)',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 750,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotato_parallax.
  $styles['rotato_parallax'] = array(
    'label' => 'Rotato Parallax (2000x1500)',
    'effects' => array(
      24 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2000,
          'height' => 1500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotato_square.
  $styles['rotato_square'] = array(
    'label' => 'Rotato Square (750x750)',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 750,
          'height' => 750,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotato_static.
  $styles['rotato_static'] = array(
    'label' => 'Rotato Static',
    'effects' => array(
      25 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1500,
          'height' => 1125,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: rotato_transparent.
  $styles['rotato_transparent'] = array(
    'label' => 'Rotato Transparent (2000x1080)',
    'effects' => array(
      29 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2000,
          'height' => 1080,
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
function cb_rotato_node_info() {
  $items = array(
    'cb_rotato' => array(
      'name' => t('Rotato'),
      'base' => 'node_content',
      'description' => t('Use <em>rotatos</em> for sliders and carousels.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
