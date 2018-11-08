<?php
/**
 * @file
 * cb_linkit.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_linkit_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
}
