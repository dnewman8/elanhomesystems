<?php
/**
 * @file
 * cb_showcase.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cb_showcase_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gallery_images|node|cb_showcase|form';
  $field_group->group_name = 'group_gallery_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cb_showcase';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Gallery Images',
    'weight' => '8',
    'children' => array(
      0 => 'field_showcase_square',
      1 => 'field_showcase_portrait',
      2 => 'field_showcase_landscape',
      3 => 'field_showcase_full',
      4 => 'field_showcase_style',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-gallery-images field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_gallery_images|node|cb_showcase|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Gallery Images');

  return $field_groups;
}
