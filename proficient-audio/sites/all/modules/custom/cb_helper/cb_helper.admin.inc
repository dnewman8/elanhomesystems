<?php

/**
 * @file.
 */

/**
 * Implements hook_form().
 */
function cb_helper_configuration($form, &$form_state) {
  $brand_id = variable_get('ns_brand');
  $brands = function_exists('cb_netsuite_getBrands') ? cb_netsuite_getBrands() : [];
  $brand_name = (isset($brands[$brand_id]) && !empty($brands[$brand_id])) ? $brands[$brand_id] : '';


  $form = array();
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('%name Specific Settings', ['%name' => $brand_name]),
  );
  $form['settings']['cb_press_landing'] = array(
    '#title' => t('Press Release landing page'),
    '#type' => 'textfield',
    '#description' => t('Type the internal path for the Press Releases landing page. This path will be used in "go back" links, from press release detail page.'),
    '#default_value' => variable_get('cb_press_landing', ''),
    '#attributes' => array(
      'placeholder' => 'node/123',
    ),
  );

  return system_settings_form($form);
}
