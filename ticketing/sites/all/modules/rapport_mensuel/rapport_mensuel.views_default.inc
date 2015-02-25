<?php
/**
 * @file
 * rapport_mensuel.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rapport_mensuel_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rapport_mensuel_des_prix_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Rapport mensuel des prix ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Rapport mensuel des prix ';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_dataviz';
  $handler->display->display_options['style_options']['type'] = 'ColumnChart';
  $handler->display->display_options['style_options']['_curveType'] = '0';
  /* Champ: SUM(Contenu: mois ) */
  $handler->display->display_options['fields']['field_mois_']['id'] = 'field_mois_';
  $handler->display->display_options['fields']['field_mois_']['table'] = 'field_data_field_mois_';
  $handler->display->display_options['fields']['field_mois_']['field'] = 'field_mois_';
  $handler->display->display_options['fields']['field_mois_']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_mois_']['label'] = '';
  $handler->display->display_options['fields']['field_mois_']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_mois_']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mois_']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Champ: Contenu: prix */
  $handler->display->display_options['fields']['field_prix']['id'] = 'field_prix';
  $handler->display->display_options['fields']['field_prix']['table'] = 'field_data_field_prix';
  $handler->display->display_options['fields']['field_prix']['field'] = 'field_prix';
  $handler->display->display_options['fields']['field_prix']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_prix']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Filter criterion: Contenu: Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenu: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'rapport_mensuel' => 'rapport_mensuel',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'rapport-mensuel-des-prix-';
  $translatables['rapport_mensuel_des_prix_'] = array(
    t('Master'),
    t('Rapport mensuel des prix '),
    t('more'),
    t('Apply'),
    t('Réinitialiser'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('prix'),
    t('Page'),
  );
  $export['rapport_mensuel_des_prix_'] = $view;

  return $export;
}
