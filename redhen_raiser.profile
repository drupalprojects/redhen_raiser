<?php

/**
 * Implement hook_install_tasks().
 * We hook into the install process to add our own tasks prior to Drupal's final step in the default install process.
 */

function redhen_raiser_install_tasks(){
  $taskset = array(
    'redhen_raiser_custom_install' => array(
      'display_name' => st('Thinkshout Site Setup'),
    ),
  );
  return $taskset;
}

/**
 * Post install tasks.
 */
function redhen_raiser_custom_install(&$install_state) {
  variable_set('theme_default', 'zen');
  if (module_exists('block')) {
    // Disable DB blocks so we can use context or panels to place everything.
    db_update('block')
      ->fields(array(
        'status' => 0,
        'region' => -1,
        'theme' => 'zen'))
      ->execute();
    // Hide menu block names.
    db_update('block')
      ->fields(array(
        'title' => '<none>'))
      ->condition('delta', 'user-menu', '=')
      ->condition('module', 'system', '=')
      ->execute();
    db_update('block')
      ->fields(array(
        'title' => '<none>'))
      ->condition('delta', 'main-menu', '=')
      ->condition('module', 'system', '=')
      ->execute();
  }
  module_enable(array('redhen_raiser_custom_config'), TRUE);

  drupal_flush_all_caches();
  features_revert();
}