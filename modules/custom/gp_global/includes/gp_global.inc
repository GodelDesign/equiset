<?php
/**
 * @file
 * Main file for hand-written custom code for gp_global.module.
 */

/**
 * Implements hook_init().
 */
function gp_global_init() {
  drupal_add_library('system', 'effects');
}
