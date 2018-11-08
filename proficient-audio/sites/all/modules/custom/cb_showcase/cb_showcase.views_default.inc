<?php
/**
 * @file
 * cb_showcase.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cb_showcase_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'showcase_details';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Showcase Details';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_showcase_description']['id'] = 'field_showcase_description';
  $handler->display->display_options['fields']['field_showcase_description']['table'] = 'field_data_field_showcase_description';
  $handler->display->display_options['fields']['field_showcase_description']['field'] = 'field_showcase_description';
  $handler->display->display_options['fields']['field_showcase_description']['label'] = '';
  $handler->display->display_options['fields']['field_showcase_description']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cb_showcase' => 'cb_showcase',
  );

  /* Display: Block Description */
  $handler = $view->new_display('block', 'Block Description', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_showcase_description']['id'] = 'field_showcase_description';
  $handler->display->display_options['fields']['field_showcase_description']['table'] = 'field_data_field_showcase_description';
  $handler->display->display_options['fields']['field_showcase_description']['field'] = 'field_showcase_description';
  $handler->display->display_options['fields']['field_showcase_description']['label'] = '';
  $handler->display->display_options['fields']['field_showcase_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block Features */
  $handler = $view->new_display('block', 'Block Features', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Features */
  $handler->display->display_options['fields']['field_showcase_features']['id'] = 'field_showcase_features';
  $handler->display->display_options['fields']['field_showcase_features']['table'] = 'field_data_field_showcase_features';
  $handler->display->display_options['fields']['field_showcase_features']['field'] = 'field_showcase_features';
  $handler->display->display_options['fields']['field_showcase_features']['label'] = '';
  $handler->display->display_options['fields']['field_showcase_features']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cb_showcase' => 'cb_showcase',
  );
  /* Filter criterion: Content: Features (field_showcase_features) */
  $handler->display->display_options['filters']['field_showcase_features_value']['id'] = 'field_showcase_features_value';
  $handler->display->display_options['filters']['field_showcase_features_value']['table'] = 'field_data_field_showcase_features';
  $handler->display->display_options['filters']['field_showcase_features_value']['field'] = 'field_showcase_features_value';
  $handler->display->display_options['filters']['field_showcase_features_value']['operator'] = 'not empty';

  /* Display: Block Equipment */
  $handler = $view->new_display('block', 'Block Equipment', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Equipment */
  $handler->display->display_options['fields']['field_showcase_equipment']['id'] = 'field_showcase_equipment';
  $handler->display->display_options['fields']['field_showcase_equipment']['table'] = 'field_data_field_showcase_equipment';
  $handler->display->display_options['fields']['field_showcase_equipment']['field'] = 'field_showcase_equipment';
  $handler->display->display_options['fields']['field_showcase_equipment']['label'] = '';
  $handler->display->display_options['fields']['field_showcase_equipment']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cb_showcase' => 'cb_showcase',
  );
  /* Filter criterion: Content: Equipment (field_showcase_equipment) */
  $handler->display->display_options['filters']['field_showcase_equipment_value']['id'] = 'field_showcase_equipment_value';
  $handler->display->display_options['filters']['field_showcase_equipment_value']['table'] = 'field_data_field_showcase_equipment';
  $handler->display->display_options['filters']['field_showcase_equipment_value']['field'] = 'field_showcase_equipment_value';
  $handler->display->display_options['filters']['field_showcase_equipment_value']['operator'] = 'not empty';

  /* Display: Block Related Projects */
  $handler = $view->new_display('block', 'Block Related Projects', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Projects';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'slick-slider with-arrows multiple-items';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Related Projects */
  $handler->display->display_options['fields']['field_showcase_related']['id'] = 'field_showcase_related';
  $handler->display->display_options['fields']['field_showcase_related']['table'] = 'field_data_field_showcase_related';
  $handler->display->display_options['fields']['field_showcase_related']['field'] = 'field_showcase_related';
  $handler->display->display_options['fields']['field_showcase_related']['label'] = '';
  $handler->display->display_options['fields']['field_showcase_related']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_related']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_showcase_related']['settings'] = array(
    'view_mode' => 'teaser',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_showcase_related']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_related']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_showcase_related']['multi_type'] = 'ul';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cb_showcase' => 'cb_showcase',
  );
  /* Filter criterion: Content: Related Projects (field_showcase_related) */
  $handler->display->display_options['filters']['field_showcase_related_target_id']['id'] = 'field_showcase_related_target_id';
  $handler->display->display_options['filters']['field_showcase_related_target_id']['table'] = 'field_data_field_showcase_related';
  $handler->display->display_options['filters']['field_showcase_related_target_id']['field'] = 'field_showcase_related_target_id';
  $handler->display->display_options['filters']['field_showcase_related_target_id']['operator'] = 'not empty';

  /* Display: Block Carousel */
  $handler = $view->new_display('block', 'Block Carousel', 'block_carousel');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'slick-slider center-mode with-thumbs';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Carousel Images */
  $handler->display->display_options['fields']['field_showcase_image']['id'] = 'field_showcase_image';
  $handler->display->display_options['fields']['field_showcase_image']['table'] = 'field_data_field_showcase_image';
  $handler->display->display_options['fields']['field_showcase_image']['field'] = 'field_showcase_image';
  $handler->display->display_options['fields']['field_showcase_image']['label'] = '';
  $handler->display->display_options['fields']['field_showcase_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_showcase_image']['settings'] = array(
    'image_style' => 'gallery_full',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_showcase_image']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_image']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block Carousel Thumb Nav */
  $handler = $view->new_display('block', 'Block Carousel Thumb Nav', 'block_4');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'slick-slider thumb-nav';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Carousel Images */
  $handler->display->display_options['fields']['field_showcase_image']['id'] = 'field_showcase_image';
  $handler->display->display_options['fields']['field_showcase_image']['table'] = 'field_data_field_showcase_image';
  $handler->display->display_options['fields']['field_showcase_image']['field'] = 'field_showcase_image';
  $handler->display->display_options['fields']['field_showcase_image']['label'] = '';
  $handler->display->display_options['fields']['field_showcase_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_showcase_image']['settings'] = array(
    'image_style' => 'gallery_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_showcase_image']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_image']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $export['showcase_details'] = $view;

  $view = new view();
  $view->name = 'showcase_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Showcase Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'gallery-listing';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Entityqueue: Content Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'gallery' => 'gallery',
    'home_hero' => 0,
    'home_gallery_residential' => 0,
    'home_gallery_commercial' => 0,
    'home_moments_static' => 0,
    'featured_blog_post' => 0,
  );
  /* Field: Content: Carousel Images */
  $handler->display->display_options['fields']['field_showcase_image']['id'] = 'field_showcase_image';
  $handler->display->display_options['fields']['field_showcase_image']['table'] = 'field_data_field_showcase_image';
  $handler->display->display_options['fields']['field_showcase_image']['field'] = 'field_showcase_image';
  $handler->display->display_options['fields']['field_showcase_image']['label'] = '';
  $handler->display->display_options['fields']['field_showcase_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_showcase_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_showcase_image']['settings'] = array(
    'image_style' => 'gallery_listing',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_showcase_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_showcase_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Entityqueue: Content Queue Position */
  $handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cb_showcase' => 'cb_showcase',
  );

  /* Display: Block Landing - Commercial */
  $handler = $view->new_display('block', 'Block Landing - Commercial', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cb_showcase' => 'cb_showcase',
  );
  /* Filter criterion: Content: Type (field_showcase_type) */
  $handler->display->display_options['filters']['field_showcase_type_value']['id'] = 'field_showcase_type_value';
  $handler->display->display_options['filters']['field_showcase_type_value']['table'] = 'field_data_field_showcase_type';
  $handler->display->display_options['filters']['field_showcase_type_value']['field'] = 'field_showcase_type_value';
  $handler->display->display_options['filters']['field_showcase_type_value']['value'] = array(
    'commercial' => 'commercial',
  );

  /* Display: Block Landing - Residential */
  $handler = $view->new_display('block', 'Block Landing - Residential', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cb_showcase' => 'cb_showcase',
  );
  /* Filter criterion: Content: Type (field_showcase_type) */
  $handler->display->display_options['filters']['field_showcase_type_value']['id'] = 'field_showcase_type_value';
  $handler->display->display_options['filters']['field_showcase_type_value']['table'] = 'field_data_field_showcase_type';
  $handler->display->display_options['filters']['field_showcase_type_value']['field'] = 'field_showcase_type_value';
  $handler->display->display_options['filters']['field_showcase_type_value']['value'] = array(
    'residential' => 'residential',
  );

  /* Display: Block Landing */
  $handler = $view->new_display('block', 'Block Landing', 'block_2');
  $export['showcase_listing'] = $view;

  $view = new view();
  $view->name = 'showcases';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Showcase Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'gallery-tiles clearfix';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'gallery';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Entityqueue: Content Queue Position */
  $handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cb_showcase' => 'cb_showcase',
  );
  /* Filter criterion: Content: Type (field_showcase_type) */
  $handler->display->display_options['filters']['field_showcase_type_value']['id'] = 'field_showcase_type_value';
  $handler->display->display_options['filters']['field_showcase_type_value']['table'] = 'field_data_field_showcase_type';
  $handler->display->display_options['filters']['field_showcase_type_value']['field'] = 'field_showcase_type_value';
  $handler->display->display_options['filters']['field_showcase_type_value']['value'] = array(
    'residential' => 'residential',
  );

  /* Display: Home Residential */
  $handler = $view->new_display('block', 'Home Residential', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Content Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['label'] = 'queue';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'home_gallery_residential' => 'home_gallery_residential',
    'home_hero' => 0,
    'home_moments' => 0,
    'home_gallery_commercial' => 0,
  );

  /* Display: Home Commercial */
  $handler = $view->new_display('block', 'Home Commercial', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Content Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['label'] = 'queue';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'home_gallery_commercial' => 'home_gallery_commercial',
    'home_hero' => 0,
    'home_gallery_residential' => 0,
    'home_moments_static' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cb_showcase' => 'cb_showcase',
  );
  /* Filter criterion: Content: Type (field_showcase_type) */
  $handler->display->display_options['filters']['field_showcase_type_value']['id'] = 'field_showcase_type_value';
  $handler->display->display_options['filters']['field_showcase_type_value']['table'] = 'field_data_field_showcase_type';
  $handler->display->display_options['filters']['field_showcase_type_value']['field'] = 'field_showcase_type_value';
  $handler->display->display_options['filters']['field_showcase_type_value']['value'] = array(
    'commercial' => 'commercial',
  );
  $export['showcases'] = $view;

  return $export;
}
