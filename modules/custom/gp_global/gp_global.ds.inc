<?php
/**
 * @file
 * gp_global.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function gp_global_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|front_page_item|titles_only';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'front_page_item';
  $ds_fieldsetting->view_mode = 'titles_only';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|front_page_item|titles_only'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function gp_global_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|front_page_item|front_page_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'front_page_item';
  $ds_layout->view_mode = 'front_page_content';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_logo',
        1 => 'field_company_name',
        2 => 'body',
      ),
    ),
    'fields' => array(
      'field_logo' => 'ds_content',
      'field_company_name' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|front_page_item|front_page_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|front_page_item|titles_only';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'front_page_item';
  $ds_layout->view_mode = 'titles_only';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|front_page_item|titles_only'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function gp_global_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'front_page_content';
  $ds_view_mode->label = 'Front page content';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['front_page_content'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'titles_only';
  $ds_view_mode->label = 'Titles Only';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['titles_only'] = $ds_view_mode;

  return $export;
}
