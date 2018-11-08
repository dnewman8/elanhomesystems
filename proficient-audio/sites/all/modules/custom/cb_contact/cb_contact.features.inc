<?php
/**
 * @file
 * cb_contact.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_contact_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_weight_features_default_settings().
 */
function cb_contact_weight_features_default_settings() {
  $settings = array();

  $settings['webform'] = array(
    'enabled' => 0,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
