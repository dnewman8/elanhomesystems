<?php
/**
 * @file
 * Contains functions only needed for drush integration.
 */

/**
 * Implementation of hook_drush_command().
 */
function corebrands_drush_command() {
  $items = array();

  $items['corebrands'] = array(
    'description' => 'Create a theme using CoreBrands.',
    'arguments' => array(
      'name'         => 'A name for your theme.',
      'machine_name' => '[optional] A machine-readable name for your theme.',
    ),
    'options' => array(
      'name'         => 'A name for your theme.',
      'machine-name' => '[a-z, 0-9] A machine-readable name for your theme.',
      'path'         => 'The path where your theme will be created. Defaults to: sites/all/themes',
      'description'  => 'A description of your theme.',
    ),
    'examples' => array(
      'drush corebrands "My theme name"' => 'Create a sub-theme, using the default options.',
      'drush corebrands "My theme name" my_theme' => 'Create a sub-theme with a specific machine name.',
      'drush corebrands "My theme" --path=sites/all/themes' => 'Create a sub-theme in the specified directory.',
    ),
  );

  return $items;
}

/**
 * Create a CoreBrands sub-theme using the starter kit.
 */
function drush_corebrands($name = NULL, $machine_name = NULL) {
  // Determine the theme name.
  if (!isset($name)) {
    $name = drush_get_option('name');
  }

  // Determine the machine name.
  if (!isset($machine_name)) {
    $machine_name = drush_get_option('machine-name');
  }
  if (!$machine_name) {
    $machine_name = $name;
  }
  $machine_name = str_replace(' ', '_', strtolower($machine_name));
  $search = array(
    '/[^a-z0-9_]/', // Remove characters not valid in function names.
    '/^[^a-z]+/',   // Functions must begin with an alpha character.
  );
  $machine_name = preg_replace($search, '', $machine_name);

  // Determine the path to the new subtheme.
  $subtheme_path = 'sites/all/themes';
  if ($path = drush_get_option('path')) {
    $subtheme_path = drush_trim_path($path);
  }
  $subtheme_path = drush_normalize_path(drush_get_context('DRUSH_DRUPAL_ROOT') . '/' . $subtheme_path . '/' . $machine_name);

  // Make a fresh copy of the original starter kit.
  $starter_path = drush_normalize_path(drush_get_context('DRUSH_DRUPAL_ROOT') . '/' . drupal_get_path('theme', 'corebrands') . '/STARTERKIT');
  if (!is_dir(dirname($subtheme_path))) {
    drush_die(dt('The directory "!directory" was not found.', array('!directory' => dirname($subtheme_path))));
  }
  drush_op('drush_copy_dir', $starter_path, $subtheme_path);

  // Rename the .info file.
  $subtheme_info_file = $subtheme_path . '/' . $machine_name . '.info';
  drush_op('corebrands_file_str_replace', drush_normalize_path($subtheme_path . '/STARTERKIT.info.txt'), 'STARTERKIT', $name);
  drush_op('rename', drush_normalize_path($subtheme_path . '/STARTERKIT.info.txt'), drush_normalize_path($subtheme_info_file));

  // Replace all occurrences of 'STARTERKIT' with the machine name of our sub theme.
  drush_op('corebrands_file_str_replace', $subtheme_path . '/template.php', 'STARTERKIT', $machine_name);

  // Notify user of the newly created theme.
  drush_print(dt('Sub theme "!name" created in: !path', array(
    '!name' => $name,
    '!path' => $subtheme_path,
  )));
}

/**
 * Replace strings in a file.
 */
function corebrands_file_str_replace($file_path, $find, $replace) {
  $file_path = drush_normalize_path($file_path);
  $file_contents = file_get_contents($file_path);
  $file_contents = str_replace($find, $replace, $file_contents);
  file_put_contents($file_path, $file_contents);
}
