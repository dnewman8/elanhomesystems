<?php
/**
 * @file
 * cb_product.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_product_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
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
function cb_product_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cb_product_image_default_styles() {
  $styles = array();

  // Exported image style: product_detail.
  $styles['product_detail'] = array(
    'label' => 'Product Detail (360x525)',
    'effects' => array(
      24 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 360,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: product_featured.
  $styles['product_featured'] = array(
    'label' => 'Product Featured (750x750)',
    'effects' => array(
      27 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 710,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      28 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 750,
            'height' => 750,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: product_tier_1.
  $styles['product_tier_1'] = array(
    'label' => 'Product Tier 1 (750x560)',
    'effects' => array(
      20 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 750,
          'height' => 560,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: product_tier_2.
  $styles['product_tier_2'] = array(
    'label' => 'Product Tier 2 (740x360)',
    'effects' => array(
      21 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 740,
          'height' => 360,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: product_tier_3.
  $styles['product_tier_3'] = array(
    'label' => 'Product Tier 3 (360x360)',
    'effects' => array(
      30 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 350,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      31 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 360,
            'height' => 360,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cb_product_node_info() {
  $items = array(
    'cb_product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => t('<em>Products</em> are imported from Netsuite directly and should not be created only administrated.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'cb_product_hub' => array(
      'name' => t('Product Hub Page'),
      'base' => 'node_content',
      'description' => t('Use this content type to create intermediate pages between product listing pages and their categories.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
