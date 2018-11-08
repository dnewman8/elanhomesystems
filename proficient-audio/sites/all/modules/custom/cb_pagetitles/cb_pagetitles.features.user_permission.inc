<?php
/**
 * @file
 * cb_pagetitles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cb_pagetitles_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer page titles'.
  $permissions['administer page titles'] = array(
    'name' => 'administer page titles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_title',
  );

  // Exported permission: 'set page title'.
  $permissions['set page title'] = array(
    'name' => 'set page title',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'page_title',
  );

  return $permissions;
}
