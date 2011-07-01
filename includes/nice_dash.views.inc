<?php

/**
 * Implementation of hook_views_plugins()
 */
function nice_dash_views_plugins() {
  return array(
    'display' => array(
      'nice_dash_dashboard_widget' => array(
        'title' => t('Dashboard widget'),
        'help' => t('Creates a dashboard display.'),
        'handler' => 'nice_dash_views_plugin_display_dashboard_widget',
        'theme' => 'views_view',
        'theme path' => drupal_get_path('module', 'views') . '/theme',
        'uses hook block' => FALSE,
        'use ajax' => TRUE,
        'use pager' => TRUE,
        'use more' => FALSE,
        'accept attachments' => TRUE,
        'admin' => t('Dashboard widget'),
        'help topic' => 'display-default',
        'path' => drupal_get_path('module', 'nice_dash') . '/includes',
      ),
    ),
  );
}