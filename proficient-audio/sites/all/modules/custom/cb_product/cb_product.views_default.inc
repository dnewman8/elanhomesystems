<?php
/**
 * @file
 * cb_product.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cb_product_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'product_details';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product Details';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_product_model' => 'field_product_model',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'cb_product' => 'cb_product',
  );

  /* Display: Block Description */
  $handler = $view->new_display('block', 'Block Description', 'block_description');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Item Id */
  $handler->display->display_options['fields']['field_product_item_id']['id'] = 'field_product_item_id';
  $handler->display->display_options['fields']['field_product_item_id']['table'] = 'field_data_field_product_item_id';
  $handler->display->display_options['fields']['field_product_item_id']['field'] = 'field_product_item_id';
  $handler->display->display_options['fields']['field_product_item_id']['label'] = '';
  $handler->display->display_options['fields']['field_product_item_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_item_id']['element_label_colon'] = FALSE;
  /* Field: Content: Model Number */
  $handler->display->display_options['fields']['field_product_model']['id'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['table'] = 'field_data_field_product_model';
  $handler->display->display_options['fields']['field_product_model']['field'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['label'] = '';
  $handler->display->display_options['fields']['field_product_model']['element_label_colon'] = FALSE;
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_product_introduction']['id'] = 'field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['table'] = 'field_data_field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['field'] = 'field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_product_introduction']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_product_description']['id'] = 'field_product_description';
  $handler->display->display_options['fields']['field_product_description']['table'] = 'field_data_field_product_description';
  $handler->display->display_options['fields']['field_product_description']['field'] = 'field_product_description';
  $handler->display->display_options['fields']['field_product_description']['label'] = '';
  $handler->display->display_options['fields']['field_product_description']['element_label_colon'] = FALSE;
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
    'cb_product' => 'cb_product',
  );
  /* Filter criterion: Content: Description (field_product_description) */
  $handler->display->display_options['filters']['field_product_description_value']['id'] = 'field_product_description_value';
  $handler->display->display_options['filters']['field_product_description_value']['table'] = 'field_data_field_product_description';
  $handler->display->display_options['filters']['field_product_description_value']['field'] = 'field_product_description_value';
  $handler->display->display_options['filters']['field_product_description_value']['operator'] = 'not empty';

  /* Display: Block Features */
  $handler = $view->new_display('block', 'Block Features', 'block_features');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_product_model' => 'field_product_model',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Model Number */
  $handler->display->display_options['fields']['field_product_model']['id'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['table'] = 'field_data_field_product_model';
  $handler->display->display_options['fields']['field_product_model']['field'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['label'] = '';
  $handler->display->display_options['fields']['field_product_model']['alter']['text'] = '[field_product_model] [nothing]';
  $handler->display->display_options['fields']['field_product_model']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Features at a Glance';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Features */
  $handler->display->display_options['fields']['field_product_features']['id'] = 'field_product_features';
  $handler->display->display_options['fields']['field_product_features']['table'] = 'field_data_field_product_features';
  $handler->display->display_options['fields']['field_product_features']['field'] = 'field_product_features';
  $handler->display->display_options['fields']['field_product_features']['label'] = '';
  $handler->display->display_options['fields']['field_product_features']['element_label_colon'] = FALSE;
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
    'cb_product' => 'cb_product',
  );
  /* Filter criterion: Content: Features (field_product_features) */
  $handler->display->display_options['filters']['field_product_features_value']['id'] = 'field_product_features_value';
  $handler->display->display_options['filters']['field_product_features_value']['table'] = 'field_data_field_product_features';
  $handler->display->display_options['filters']['field_product_features_value']['field'] = 'field_product_features_value';
  $handler->display->display_options['filters']['field_product_features_value']['operator'] = 'not empty';

  /* Display: Block Specs */
  $handler = $view->new_display('block', 'Block Specs', 'block_specs');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_product_model' => 'field_product_model',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Model Number */
  $handler->display->display_options['fields']['field_product_model']['id'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['table'] = 'field_data_field_product_model';
  $handler->display->display_options['fields']['field_product_model']['field'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['label'] = '';
  $handler->display->display_options['fields']['field_product_model']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Specifications';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Specs */
  $handler->display->display_options['fields']['field_product_specs']['id'] = 'field_product_specs';
  $handler->display->display_options['fields']['field_product_specs']['table'] = 'field_data_field_product_specs';
  $handler->display->display_options['fields']['field_product_specs']['field'] = 'field_product_specs';
  $handler->display->display_options['fields']['field_product_specs']['label'] = '';
  $handler->display->display_options['fields']['field_product_specs']['element_label_colon'] = FALSE;
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
    'cb_product' => 'cb_product',
  );
  /* Filter criterion: Content: Specs (field_product_specs) */
  $handler->display->display_options['filters']['field_product_specs_value']['id'] = 'field_product_specs_value';
  $handler->display->display_options['filters']['field_product_specs_value']['table'] = 'field_data_field_product_specs';
  $handler->display->display_options['filters']['field_product_specs_value']['field'] = 'field_product_specs_value';
  $handler->display->display_options['filters']['field_product_specs_value']['operator'] = 'not empty';

  /* Display: Block Resources */
  $handler = $view->new_display('block', 'Block Resources', 'block_resources');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Resources */
  $handler->display->display_options['fields']['field_product_resources']['id'] = 'field_product_resources';
  $handler->display->display_options['fields']['field_product_resources']['table'] = 'field_data_field_product_resources';
  $handler->display->display_options['fields']['field_product_resources']['field'] = 'field_product_resources';
  $handler->display->display_options['fields']['field_product_resources']['label'] = '';
  $handler->display->display_options['fields']['field_product_resources']['element_label_colon'] = FALSE;
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
    'cb_product' => 'cb_product',
  );
  /* Filter criterion: Content: Resources (field_product_resources) */
  $handler->display->display_options['filters']['field_product_resources_value']['id'] = 'field_product_resources_value';
  $handler->display->display_options['filters']['field_product_resources_value']['table'] = 'field_data_field_product_resources';
  $handler->display->display_options['filters']['field_product_resources_value']['field'] = 'field_product_resources_value';
  $handler->display->display_options['filters']['field_product_resources_value']['operator'] = 'not empty';

  /* Display: Block Warranty */
  $handler = $view->new_display('block', 'Block Warranty', 'block_warranty');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Model Number */
  $handler->display->display_options['fields']['field_product_model']['id'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['table'] = 'field_data_field_product_model';
  $handler->display->display_options['fields']['field_product_model']['field'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['label'] = '';
  $handler->display->display_options['fields']['field_product_model']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Warranty';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Warranty */
  $handler->display->display_options['fields']['field_product_warranty']['id'] = 'field_product_warranty';
  $handler->display->display_options['fields']['field_product_warranty']['table'] = 'field_data_field_product_warranty';
  $handler->display->display_options['fields']['field_product_warranty']['field'] = 'field_product_warranty';
  $handler->display->display_options['fields']['field_product_warranty']['label'] = '';
  $handler->display->display_options['fields']['field_product_warranty']['element_label_colon'] = FALSE;
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
    'cb_product' => 'cb_product',
  );
  /* Filter criterion: Content: Warranty (field_product_warranty) */
  $handler->display->display_options['filters']['field_product_warranty_value']['id'] = 'field_product_warranty_value';
  $handler->display->display_options['filters']['field_product_warranty_value']['table'] = 'field_data_field_product_warranty';
  $handler->display->display_options['filters']['field_product_warranty_value']['field'] = 'field_product_warranty_value';
  $handler->display->display_options['filters']['field_product_warranty_value']['operator'] = 'not empty';

  /* Display: Block Related */
  $handler = $view->new_display('block', 'Block Related', 'block_related');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Products';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'slick-slider with-arrows multiple-items';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Related Products */
  $handler->display->display_options['fields']['field_product_related']['id'] = 'field_product_related';
  $handler->display->display_options['fields']['field_product_related']['table'] = 'field_data_field_product_related';
  $handler->display->display_options['fields']['field_product_related']['field'] = 'field_product_related';
  $handler->display->display_options['fields']['field_product_related']['label'] = '';
  $handler->display->display_options['fields']['field_product_related']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_related']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_product_related']['settings'] = array(
    'view_mode' => 'teaser',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_product_related']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_product_related']['delta_offset'] = '0';
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
    'cb_product' => 'cb_product',
  );
  /* Filter criterion: Content: Related Products (field_product_related) */
  $handler->display->display_options['filters']['field_product_related_target_id']['id'] = 'field_product_related_target_id';
  $handler->display->display_options['filters']['field_product_related_target_id']['table'] = 'field_data_field_product_related';
  $handler->display->display_options['filters']['field_product_related_target_id']['field'] = 'field_product_related_target_id';
  $handler->display->display_options['filters']['field_product_related_target_id']['operator'] = 'not empty';

  /* Display: Block Images */
  $handler = $view->new_display('block', 'Block Images', 'block_product_images');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'slick-slider with-arrows multiple-items';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_product_image']['id'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['table'] = 'field_data_field_product_image';
  $handler->display->display_options['fields']['field_product_image']['field'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_image']['settings'] = array(
    'image_style' => 'product_detail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_product_image']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_product_image']['delta_offset'] = '0';
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
    'cb_product' => 'cb_product',
  );
  $export['product_details'] = $view;

  $view = new view();
  $view->name = 'products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Sort Order (field_product_sort) */
  $handler->display->display_options['sorts']['field_product_sort_value']['id'] = 'field_product_sort_value';
  $handler->display->display_options['sorts']['field_product_sort_value']['table'] = 'field_data_field_product_sort';
  $handler->display->display_options['sorts']['field_product_sort_value']['field'] = 'field_product_sort_value';
  $handler->display->display_options['sorts']['field_product_sort_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Category (field_product_category) */
  $handler->display->display_options['arguments']['field_product_category_tid']['id'] = 'field_product_category_tid';
  $handler->display->display_options['arguments']['field_product_category_tid']['table'] = 'field_data_field_product_category';
  $handler->display->display_options['arguments']['field_product_category_tid']['field'] = 'field_product_category_tid';
  $handler->display->display_options['arguments']['field_product_category_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_product_category_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_product_category_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_product_category_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_product_category_tid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_product_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_product_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_product_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_product_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_product_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_product_category_tid']['validate_options']['vocabularies'] = array(
    'product_category' => 'product_category',
  );
  $handler->display->display_options['arguments']['field_product_category_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_product_category_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['field_product_category_tid']['validate']['fail'] = 'empty';
  /* Contextual filter: Content: Sub Category (field_prod_sub_category) */
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['id'] = 'field_prod_sub_category_tid';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['table'] = 'field_data_field_prod_sub_category';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['field'] = 'field_prod_sub_category_tid';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['title'] = '%2';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['validate_options']['vocabularies'] = array(
    'product_sub_category' => 'product_sub_category',
  );
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['field_prod_sub_category_tid']['validate']['fail'] = 'empty';
  /* Contextual filter: Content: Web Family (field_prod_web_family) */
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['id'] = 'field_prod_web_family_tid';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['table'] = 'field_data_field_prod_web_family';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['field'] = 'field_prod_web_family_tid';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['title'] = '%3';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['validate_options']['vocabularies'] = array(
    'product_web_family' => 'product_web_family',
  );
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['field_prod_web_family_tid']['validate']['fail'] = 'empty';
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
    'cb_product' => 'cb_product',
  );

  /* Display: Page Landing */
  $handler = $view->new_display('page', 'Page Landing', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Category Description */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['ui_name'] = 'Category Description';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<div class="product-category-hero">[field_cat_hero]</div>
<div class="product-category-intro">[description]</div>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Header: Sub Category Description */
  $handler->display->display_options['header']['area_text_custom_1']['id'] = 'area_text_custom_1';
  $handler->display->display_options['header']['area_text_custom_1']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom_1']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom_1']['ui_name'] = 'Sub Category Description';
  $handler->display->display_options['header']['area_text_custom_1']['content'] = '<div class="product-category-hero">[field_sub_cat_hero]</div>
<div class="product-category-intro">[description_1]</div>';
  $handler->display->display_options['header']['area_text_custom_1']['tokenize'] = TRUE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view_2']['id'] = 'view_2';
  $handler->display->display_options['header']['view_2']['table'] = 'views';
  $handler->display->display_options['header']['view_2']['field'] = 'view';
  $handler->display->display_options['header']['view_2']['label'] = 'Tier 1';
  $handler->display->display_options['header']['view_2']['empty'] = TRUE;
  $handler->display->display_options['header']['view_2']['view_to_insert'] = 'products:block_products_tier1';
  $handler->display->display_options['header']['view_2']['inherit_arguments'] = TRUE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view_1']['id'] = 'view_1';
  $handler->display->display_options['header']['view_1']['table'] = 'views';
  $handler->display->display_options['header']['view_1']['field'] = 'view';
  $handler->display->display_options['header']['view_1']['label'] = 'Tier 2';
  $handler->display->display_options['header']['view_1']['empty'] = TRUE;
  $handler->display->display_options['header']['view_1']['view_to_insert'] = 'products:block_products_tier2';
  $handler->display->display_options['header']['view_1']['inherit_arguments'] = TRUE;
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['label'] = 'Tier 3';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'products:block_products_tier3';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No products found for this category.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Category (field_product_category) */
  $handler->display->display_options['relationships']['field_product_category_tid']['id'] = 'field_product_category_tid';
  $handler->display->display_options['relationships']['field_product_category_tid']['table'] = 'field_data_field_product_category';
  $handler->display->display_options['relationships']['field_product_category_tid']['field'] = 'field_product_category_tid';
  $handler->display->display_options['relationships']['field_product_category_tid']['label'] = 'category';
  /* Relationship: Content: Sub Category (field_prod_sub_category) */
  $handler->display->display_options['relationships']['field_prod_sub_category_tid']['id'] = 'field_prod_sub_category_tid';
  $handler->display->display_options['relationships']['field_prod_sub_category_tid']['table'] = 'field_data_field_prod_sub_category';
  $handler->display->display_options['relationships']['field_prod_sub_category_tid']['field'] = 'field_prod_sub_category_tid';
  $handler->display->display_options['relationships']['field_prod_sub_category_tid']['label'] = 'sub_category';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_product_featured_image']['id'] = 'field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['table'] = 'field_data_field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['field'] = 'field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_featured_image']['settings'] = array(
    'image_style' => 'product_tier_3',
    'image_link' => 'content',
  );
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_product_image']['id'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['table'] = 'field_data_field_product_image';
  $handler->display->display_options['fields']['field_product_image']['field'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_image']['settings'] = array(
    'image_style' => 'product_tier_3',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_product_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_product_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_product_image']['multi_type'] = 'ul';
  /* Field: Content: Model Number */
  $handler->display->display_options['fields']['field_product_model']['id'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['table'] = 'field_data_field_product_model';
  $handler->display->display_options['fields']['field_product_model']['field'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['label'] = '';
  $handler->display->display_options['fields']['field_product_model']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_product_model']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_product_model']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_product_model']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Hero Image */
  $handler->display->display_options['fields']['field_cat_hero']['id'] = 'field_cat_hero';
  $handler->display->display_options['fields']['field_cat_hero']['table'] = 'field_data_field_cat_hero';
  $handler->display->display_options['fields']['field_cat_hero']['field'] = 'field_cat_hero';
  $handler->display->display_options['fields']['field_cat_hero']['relationship'] = 'field_product_category_tid';
  $handler->display->display_options['fields']['field_cat_hero']['label'] = '';
  $handler->display->display_options['fields']['field_cat_hero']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cat_hero']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cat_hero']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cat_hero']['settings'] = array(
    'image_style' => 'page_hero',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['relationship'] = 'field_product_category_tid';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Hero Image */
  $handler->display->display_options['fields']['field_sub_cat_hero']['id'] = 'field_sub_cat_hero';
  $handler->display->display_options['fields']['field_sub_cat_hero']['table'] = 'field_data_field_sub_cat_hero';
  $handler->display->display_options['fields']['field_sub_cat_hero']['field'] = 'field_sub_cat_hero';
  $handler->display->display_options['fields']['field_sub_cat_hero']['relationship'] = 'field_prod_sub_category_tid';
  $handler->display->display_options['fields']['field_sub_cat_hero']['label'] = '';
  $handler->display->display_options['fields']['field_sub_cat_hero']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sub_cat_hero']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sub_cat_hero']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sub_cat_hero']['settings'] = array(
    'image_style' => 'page_hero',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description_1']['id'] = 'description_1';
  $handler->display->display_options['fields']['description_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description_1']['field'] = 'description';
  $handler->display->display_options['fields']['description_1']['relationship'] = 'field_prod_sub_category_tid';
  $handler->display->display_options['fields']['description_1']['label'] = '';
  $handler->display->display_options['fields']['description_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['description_1']['element_label_colon'] = FALSE;
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
    'cb_product' => 'cb_product',
  );
  /* Filter criterion: Content: Feature Options (field_product_featured) */
  $handler->display->display_options['filters']['field_product_featured_value']['id'] = 'field_product_featured_value';
  $handler->display->display_options['filters']['field_product_featured_value']['table'] = 'field_data_field_product_featured';
  $handler->display->display_options['filters']['field_product_featured_value']['field'] = 'field_product_featured_value';
  $handler->display->display_options['filters']['field_product_featured_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_product_featured_value']['value'] = array(
    'tier_1' => 'tier_1',
    'tier_2' => 'tier_2',
    'tier_3' => 'tier_3',
  );
  $handler->display->display_options['path'] = 'products/%/%/%';

  /* Display: Block Tier 1 */
  $handler = $view->new_display('block', 'Block Tier 1', 'block_products_tier1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Category (field_product_category) */
  $handler->display->display_options['relationships']['field_product_category_tid']['id'] = 'field_product_category_tid';
  $handler->display->display_options['relationships']['field_product_category_tid']['table'] = 'field_data_field_product_category';
  $handler->display->display_options['relationships']['field_product_category_tid']['field'] = 'field_product_category_tid';
  $handler->display->display_options['relationships']['field_product_category_tid']['label'] = 'product_category';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_product_featured_image']['id'] = 'field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['table'] = 'field_data_field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['field'] = 'field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_featured_image']['settings'] = array(
    'image_style' => 'product_tier_1',
    'image_link' => '',
  );
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_product_image']['id'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['table'] = 'field_data_field_product_image';
  $handler->display->display_options['fields']['field_product_image']['field'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_image']['settings'] = array(
    'image_style' => 'product_tier_1',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_product_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_product_image']['delta_offset'] = '0';
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'Group Text';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'title',
    1 => 'field_product_model',
    2 => 'field_product_introduction',
    3 => 'view_node',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'text-wrapper';
  /* Field: Content: Model Number */
  $handler->display->display_options['fields']['field_product_model']['id'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['table'] = 'field_data_field_product_model';
  $handler->display->display_options['fields']['field_product_model']['field'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['label'] = '';
  $handler->display->display_options['fields']['field_product_model']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_product_model']['element_label_colon'] = FALSE;
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_product_introduction']['id'] = 'field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['table'] = 'field_data_field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['field'] = 'field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_product_introduction']['alter']['max_length'] = '330';
  $handler->display->display_options['fields']['field_product_introduction']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_product_introduction']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'more-link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Product Details';
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
    'cb_product' => 'cb_product',
  );
  /* Filter criterion: Content: Feature Options (field_product_featured) */
  $handler->display->display_options['filters']['field_product_featured_value']['id'] = 'field_product_featured_value';
  $handler->display->display_options['filters']['field_product_featured_value']['table'] = 'field_data_field_product_featured';
  $handler->display->display_options['filters']['field_product_featured_value']['field'] = 'field_product_featured_value';
  $handler->display->display_options['filters']['field_product_featured_value']['value'] = array(
    'tier_1' => 'tier_1',
  );

  /* Display: Block Tier 2 */
  $handler = $view->new_display('block', 'Block Tier 2', 'block_products_tier2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_product_featured_image']['id'] = 'field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['table'] = 'field_data_field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['field'] = 'field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_featured_image']['settings'] = array(
    'image_style' => 'product_tier_2',
    'image_link' => '',
  );
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_product_image']['id'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['table'] = 'field_data_field_product_image';
  $handler->display->display_options['fields']['field_product_image']['field'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_image']['settings'] = array(
    'image_style' => 'product_tier_2',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_product_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_product_image']['delta_offset'] = '0';
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'Group Text';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_product_model',
    1 => 'title',
    2 => 'field_product_introduction',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'text-wrapper';
  /* Field: Content: Model Number */
  $handler->display->display_options['fields']['field_product_model']['id'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['table'] = 'field_data_field_product_model';
  $handler->display->display_options['fields']['field_product_model']['field'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['label'] = '';
  $handler->display->display_options['fields']['field_product_model']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_product_model']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_product_model']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_product_model']['element_label_colon'] = FALSE;
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_product_introduction']['id'] = 'field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['table'] = 'field_data_field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['field'] = 'field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_product_introduction']['alter']['max_length'] = '330';
  $handler->display->display_options['fields']['field_product_introduction']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_product_introduction']['element_label_colon'] = FALSE;
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
    'cb_product' => 'cb_product',
  );
  /* Filter criterion: Content: Feature Options (field_product_featured) */
  $handler->display->display_options['filters']['field_product_featured_value']['id'] = 'field_product_featured_value';
  $handler->display->display_options['filters']['field_product_featured_value']['table'] = 'field_data_field_product_featured';
  $handler->display->display_options['filters']['field_product_featured_value']['field'] = 'field_product_featured_value';
  $handler->display->display_options['filters']['field_product_featured_value']['value'] = array(
    'tier_2' => 'tier_2',
  );

  /* Display: Block Tier 3 */
  $handler = $view->new_display('block', 'Block Tier 3', 'block_products_tier3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Featured Image */
  $handler->display->display_options['fields']['field_product_featured_image']['id'] = 'field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['table'] = 'field_data_field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['field'] = 'field_product_featured_image';
  $handler->display->display_options['fields']['field_product_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_featured_image']['settings'] = array(
    'image_style' => 'product_tier_3',
    'image_link' => '',
  );
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_product_image']['id'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['table'] = 'field_data_field_product_image';
  $handler->display->display_options['fields']['field_product_image']['field'] = 'field_product_image';
  $handler->display->display_options['fields']['field_product_image']['label'] = '';
  $handler->display->display_options['fields']['field_product_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_product_image']['settings'] = array(
    'image_style' => 'product_tier_3',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_product_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_product_image']['delta_offset'] = '0';
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'Group Text';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_product_model',
    1 => 'field_product_introduction',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'text-wrapper';
  /* Field: Content: Model Number */
  $handler->display->display_options['fields']['field_product_model']['id'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['table'] = 'field_data_field_product_model';
  $handler->display->display_options['fields']['field_product_model']['field'] = 'field_product_model';
  $handler->display->display_options['fields']['field_product_model']['label'] = '';
  $handler->display->display_options['fields']['field_product_model']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_product_model']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_product_model']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_product_model']['element_label_colon'] = FALSE;
  /* Field: Content: Introduction */
  $handler->display->display_options['fields']['field_product_introduction']['id'] = 'field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['table'] = 'field_data_field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['field'] = 'field_product_introduction';
  $handler->display->display_options['fields']['field_product_introduction']['label'] = '';
  $handler->display->display_options['fields']['field_product_introduction']['alter']['max_length'] = '330';
  $handler->display->display_options['fields']['field_product_introduction']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_product_introduction']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_product_introduction']['alter']['preserve_tags'] = '<br><a>';
  $handler->display->display_options['fields']['field_product_introduction']['element_label_colon'] = FALSE;
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
    'cb_product' => 'cb_product',
  );
  /* Filter criterion: Content: Feature Options (field_product_featured) */
  $handler->display->display_options['filters']['field_product_featured_value']['id'] = 'field_product_featured_value';
  $handler->display->display_options['filters']['field_product_featured_value']['table'] = 'field_data_field_product_featured';
  $handler->display->display_options['filters']['field_product_featured_value']['field'] = 'field_product_featured_value';
  $handler->display->display_options['filters']['field_product_featured_value']['value'] = array(
    'tier_3' => 'tier_3',
  );
  $export['products'] = $view;

  return $export;
}
