<?php
/**
 * @file
 * rapport_mensuel.features.inc
 */

/**
 * Implements hook_views_api().
 */
function rapport_mensuel_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rapport_mensuel_node_info() {
  $items = array(
    'rapport_mensuel' => array(
      'name' => t('rapport mensuel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
