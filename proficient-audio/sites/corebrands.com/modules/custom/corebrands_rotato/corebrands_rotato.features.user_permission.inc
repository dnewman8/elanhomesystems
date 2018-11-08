<?php
/**
 * @file
 * corebrands_rotato.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function corebrands_rotato_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cb_rotato content'.
  $permissions['create cb_rotato content'] = array(
    'name' => 'create cb_rotato content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any cb_rotato content'.
  $permissions['delete any cb_rotato content'] = array(
    'name' => 'delete any cb_rotato content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own cb_rotato content'.
  $permissions['delete own cb_rotato content'] = array(
    'name' => 'delete own cb_rotato content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any cb_rotato content'.
  $permissions['edit any cb_rotato content'] = array(
    'name' => 'edit any cb_rotato content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own cb_rotato content'.
  $permissions['edit own cb_rotato content'] = array(
    'name' => 'edit own cb_rotato content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
