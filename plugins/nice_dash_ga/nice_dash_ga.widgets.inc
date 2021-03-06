<?php

/**
 * Callback for the Nice Dash: unpublish widget
 */
function nice_dash_ga_widget_visits(){
  // Grab the data.
  $request = array(
    '#dimensions' => array('pagePath', 'date'),
    '#metrics' => array('pageviews', 'timeOnPage', 'bounces', 'uniquePageviews'),
    '#sort_metric' => array('date', 'pagePath'),
    '#start_date' => strtotime('-35 days')
  );
  $rows = google_analytics_reports_path_report($request, 'node');

  // Check for data.
  if (!$rows) {
    return '<p>No analytics data is currently available for this path.</p>';
  }

  // Format and perform calculations to display charts.
  $chart_page_views = array();
  $chart_avg_time = array();
  $chart_bounce_rate = array();
  $chart_dates = array();
  foreach ($rows as $date => $row) {
    $chart_pageviews[] = $row['pageviews'];
    $chart_avg_time[] = number_format($row['timeOnPage'] / $row['pageviews'], 1);
    $chart_bounce_rate[] = number_format($row['bounces'] / $row['uniquePageviews'] * 100, 2);
    $chart_dates[] = date('d', strtotime($date));
  }

  // Create charts.
 $content .= chart_render(_google_analytics_reports_main_chart('page_views', t('Page Views'), $chart_pageviews, $chart_dates));

  return theme('nice_dash_component', t('Visit statistics from Google Analytics'), '', $content);

}