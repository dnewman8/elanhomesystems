<?php
/**
 * @file
 * cb_pagetitles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cb_pagetitles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
