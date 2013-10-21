<?php

/**
 * @file
 * The node_statistics.admin.module
 */

/**
 * Form constructor for the node_statistics_article_metrics settings form.
 *
 * @see hook_admin_settings_validate()
 *
 * @ingroup forms
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
    '#default_value' => variable_get('advance_clock_count', 3),
    '#description' => t('Allowed clock for user.'),
    '#required' => TRUE,
  );
  $form['#validate'][] = 'advance_clock_admin_settings_validate';
  return system_settings_form($form);
}

/**
 * Form validation handler for hook_admin_settings().
 */
function advance_clock_admin_settings_validate($form, &$form_state) {
  // Nothing
}
