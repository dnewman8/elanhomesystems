<?php
/**
 * @file
 * cb_product.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function cb_product_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'product_category';
  $bean_type->label = 'Product Category';
  $bean_type->options = '';
  $bean_type->description = 'Use this block to create a visual link to a product category, sub category or web family.';
  $export['product_category'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'product_listing';
  $bean_type->label = 'Product Listing';
  $bean_type->options = '';
  $bean_type->description = 'Use this block to display short lists of products on a page, e.g. top sellers.';
  $export['product_listing'] = $bean_type;

  return $export;
}
