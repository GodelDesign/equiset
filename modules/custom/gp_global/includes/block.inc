<?php
/**
 * @file
 * Integrate gp.module with block.module
 */

/**
 * Implements hook_block_info().
 */
function gp_global_block_info() {
  $blocks = array();

  // Blank template block.
  $blocks['blank'] = array(
    'info' => t('Blank'),
  );

   // Front page titles block.
  $blocks['titles'] = array(
    'info' => t('Titles'),
  );

     // Front page content block.
  $blocks['frontcontent'] = array(
    'info' => t('Front Content'),
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function gp_global_block_view($delta = ''){
  $ret = '';

  $function = __FUNCTION__ . '_' . $delta;
  if(function_exists($function)) {
    $ret = $function();
  }

  return $ret;
}

/**
 * Renders 'blank' block.
 */
function gp_global_block_view_blank() {
  $block = array();
  // The block title.
  $block['subject'] = '';
  // The content of the block.
  $block['content'] = '';
  // Save ourselves some typing; we'll be concatenating a lot to this variable.
  $content = &$block['content'];

  $content .= '<h2>Blank</h2>';

  return $block;
}

function getFrontPageNodes() {
  $ret = &drupal_static(__FUNCTION__);

  if (!isset($ret)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'front_page_item')
      ->propertyCondition('status', 1)
      ->range(0, 10);

    $ret = $query->execute();
  }

  return $ret;
}

/**
 * Renders 'titles' block.
 */
function gp_global_block_view_titles() {
  $block = array();
  // The block title.
  $block['subject'] = '';
  // The content of the block.
  $block['content'] = '';
  // Save ourselves some typing; we'll be concatenating a lot to this variable.
  $content = &$block['content'];

  $nid_list = getFrontPageNodes();
  $nid_list = array_keys($nid_list['node']);
  $render_array_list = node_view_multiple(node_load_multiple($nid_list), 'titles_only');
  $content .= drupal_render($render_array_list) . '<p class="relaunching">Website relaunching soon.</p>';

  return $block;
}



/**
 * Renders 'front content' block.
 */
function gp_global_block_view_frontcontent() {
  $block = array();
  // The block title.
  $block['subject'] = '';
  // The content of the block.
  $block['content'] = '';
  // Save ourselves some typing; we'll be concatenating a lot to this variable.
  $content = &$block['content'];

  $nid_list = getFrontPageNodes();
  $nid_list = array_keys($nid_list['node']);
  $render_array_list = node_view_multiple(node_load_multiple($nid_list), 'front_page_content');
  $content .= drupal_render($render_array_list);

  return $block;
}
