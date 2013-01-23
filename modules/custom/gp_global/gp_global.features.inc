<?php
/**
 * @file
 * gp_global.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gp_global_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function gp_global_node_info() {
  $items = array(
    'front_page_item' => array(
      'name' => t('Front Page Item'),
      'base' => 'node_content',
      'description' => t('This content type has been created for the holding page using \'Initiate, Deliver, Manage, Invest\' as the four initial front-page items.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
