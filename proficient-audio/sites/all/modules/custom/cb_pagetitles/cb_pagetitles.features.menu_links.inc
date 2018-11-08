<?php
/**
 * @file
 * cb_pagetitles.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function cb_pagetitles_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_page-titles:admin/config/search/page-title
  $menu_links['management_page-titles:admin/config/search/page-title'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/page-title',
    'router_path' => 'admin/config/search/page-title',
    'link_title' => 'Page titles',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the page titles for your site (the title in the &lt;head&gt; tag).',
      ),
      'identifier' => 'management_page-titles:admin/config/search/page-title',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_search-and-metadata:admin/config/search',
  );
  // Exported menu link: navigation_page-title-list:admin/reports/page-title
  $menu_links['navigation_page-title-list:admin/reports/page-title'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'admin/reports/page-title',
    'router_path' => 'admin/reports/page-title',
    'link_title' => 'Page Title List',
    'options' => array(
      'attributes' => array(
        'title' => 'List all nodes with their Page Titles',
      ),
      'identifier' => 'navigation_page-title-list:admin/reports/page-title',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Page Title List');
  t('Page titles');

  return $menu_links;
}
