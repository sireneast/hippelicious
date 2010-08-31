<?php

/**
 * Retrieve an options array of styles.
 */
function hippelicious_get_styles() {
  $options = array();
  $options['default'] = t('Default');
  $options['custom'] = t('Custom style');
  return $options;
}

/**
 * Retrieve specific info about the current style.
 */
function hippelicious_get_style_info() {
  $settings = theme_get_settings('hippelicious');
  $style = !empty($settings['style']) ? $settings['style'] : 'default';
  switch ($style) {
    case 'custom':
      $info = array();
      $info['background_color'] = !empty($settings['background_color']) ? $settings['background_color'] : '';
      $info['background_url'] = !empty($settings['background_path']) ? file_create_url($settings['background_path']) : '';
      $info['background_repeat'] = !empty($settings['background_repeat']) ? $settings['background_repeat'] : 'no-repeat';
      return $info;
    default:
      $path = drupal_get_path('theme', 'hippelicious') .'/images';
      $styles = array(
        'default' => array(
          'background_color' => '#fff',
          // 'background_repeat' => 'repeat-x',
          // 'background_url' => url("$path/default.jpg", array('absolute' => TRUE)),
        ),
      );
      return !empty($styles[$style]) ? $styles[$style] : $styles['default'];
      break;
  }
}
