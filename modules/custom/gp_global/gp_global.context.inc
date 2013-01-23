<?php
/**
 * @file
 * gp_global.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function gp_global_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front-page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'gp_global-titles' => array(
          'module' => 'gp_global',
          'delta' => 'titles',
          'region' => 'content',
          'weight' => '-10',
        ),
        'gp_global-frontcontent' => array(
          'module' => 'gp_global',
          'delta' => 'frontcontent',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['front-page'] = $context;

  return $export;
}
