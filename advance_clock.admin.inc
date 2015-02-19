<?php
/**
 * @file
 * The node_statistics.admin.module.
 */

/**
 * Admin setting form for Advance clock.
 */
function advance_clock_admin_settings() {
  $form = array();
  $form['advance_clock_count'] = array(
    '#type' => 'select',
    '#title' => t('Number of allowed clock per user'),
    '#options' => array(
      1 => t('1'),
      2 => t('2'),
      3 => t('3'),
      4 => t('4'),
      5 => t('5'),
      6 => t('6'),
    ),
    '#default_value' => variable_get('advance_clock_count'),
    '#description' => t('Allowed clock for user.'),
    '#required' => TRUE,
  );

  $form['advance_clock_show_secs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Seconds'),
    '#default_value' => variable_get('advance_clock_show_secs', TRUE),
    '#description' => t('Show Seconds Counter with digital clock'),
  );

  $form['advance_clock_show_only_city'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Only City Name'),
    '#default_value' => variable_get('advance_clock_show_only_city', FALSE),
    '#description' => t('Show only City Name as clock title.'),
  );

  $form['advance_clock_hour24'] = array(
    '#type' => 'checkbox',
    '#title' => t('24 hrs Clock'),
    '#default_value' => variable_get('advance_clock_hour24', FALSE),
    '#description' => t('Default is 12Hr Clock to display with digital clock.'),
  );

  $form['advance_clock_show_date'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Date'),
    '#default_value' => variable_get('advance_clock_show_date', FALSE),
  );

  $form['advance_clock_type'] = array(
    '#type' => 'radios',
    '#title' => t('Clock Type'),
    '#options' => array(
      0 => t('Digital Clock'),
      1 => t('Analog Clock'),
    ),
    '#default_value' => variable_get('advance_clock_type', 0),
    '#description' => t('Select which type of clock you want to display.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
