<?php
/**
 * @file
 * cb_showcase.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function cb_showcase_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'gallery';
  $queue->label = 'Gallery';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'cb_showcase' => 'cb_showcase',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 0,
  );
  $export['gallery'] = $queue;

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'home_gallery_commercial';
  $queue->label = 'Home Gallery Commercial';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'cb_showcase' => 'cb_showcase',
    ),
    'min_size' => '0',
    'max_size' => '5',
    'act_as_queue' => 1,
  );
  $export['home_gallery_commercial'] = $queue;

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'home_gallery_residential';
  $queue->label = 'Home Gallery Residential';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'cb_showcase' => 'cb_showcase',
    ),
    'min_size' => '0',
    'max_size' => '5',
    'act_as_queue' => 1,
  );
  $export['home_gallery_residential'] = $queue;

  return $export;
}
