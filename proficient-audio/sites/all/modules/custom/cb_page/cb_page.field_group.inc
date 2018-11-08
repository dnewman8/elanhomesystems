<?php
/**
 * @file
 * cb_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cb_page_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text_wrapper|bean|page_section|default';
  $field_group->group_name = 'group_text_wrapper';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'page_section';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text Wrapper',
    'weight' => '1',
    'children' => array(
      0 => 'field_description',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Text Wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-text-wrapper field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_text_wrapper|bean|page_section|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Text Wrapper');

  return $field_groups;
}
