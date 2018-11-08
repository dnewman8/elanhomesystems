<?php
/**
 * @file
 * cb_press.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cb_press_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_author|user|user|form';
  $field_group->group_name = 'group_author';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Author Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_name',
      1 => 'field_user_address',
      2 => 'field_user_phone',
      3 => 'field_user_email',
      4 => 'field_user_company',
      5 => 'field_user_photo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-author field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_author|user|user|form'] = $field_group;

  return $export;
}
