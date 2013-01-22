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

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function gp_global_block_view($delta = ''){
  $ret = '';

  $function = __FUNCTION__ . $delta;
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