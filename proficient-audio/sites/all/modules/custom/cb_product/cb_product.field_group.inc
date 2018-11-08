<?php
/**
 * @file
 * cb_product.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cb_product_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|cb_product_hub|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cb_product_hub';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Categories',
    'weight' => '3',
    'children' => array(
      0 => 'field_category_section',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-categories field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_categories|node|cb_product_hub|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_listing|node|cb_product_hub|form';
  $field_group->group_name = 'group_listing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cb_product_hub';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Listing',
    'weight' => '4',
    'children' => array(
      0 => 'field_listing_title',
      1 => 'field_hub_products',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-listing field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_listing|node|cb_product_hub|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Product Categories');
  t('Product Listing');

  return $field_groups;
}
