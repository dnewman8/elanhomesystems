<?php
/**
 * @file
 * cb_imce.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_imce_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
