<?php
/**
 * @file
 * cb_rotato.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cb_rotato_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_display_options|node|cb_rotato|form';
  $field_group->group_name = 'group_display_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cb_rotato';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Display Options',
    'weight' => '1',
    'children' => array(
      0 => 'field_rotato_background',
      1 => 'field_rotato_font',
      2 => 'field_rotato_image_style',
      3 => 'field_rotato_square',
      4 => 'field_rotato_landscape',
      5 => 'field_rotato_full',
      6 => 'field_rotato_parallax',
      7 => 'field_rotato_transparent',
      8 => 'field_rotato_full_short',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_display_options|node|cb_rotato|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text_wrapper|node|cb_rotato|hero_split';
  $field_group->group_name = 'group_text_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cb_rotato';
  $field_group->mode = 'hero_split';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Text Wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-wrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_text_wrapper|node|cb_rotato|hero_split'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text|node|cb_rotato|hero_full';
  $field_group->group_name = 'group_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cb_rotato';
  $field_group->mode = 'hero_full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Text',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'text-wrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_text|node|cb_rotato|hero_full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display Options');
  t('Text');
  t('Text Wrapper');

  return $field_groups;
}
