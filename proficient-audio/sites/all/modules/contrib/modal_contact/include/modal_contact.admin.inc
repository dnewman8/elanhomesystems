<?php
/**
 * @file
 * Admin file.
 */

/**
 * Settings form.
 */
function modal_contact_system_settings($form) {
  $variables = _modal_contact_variable_get();

  $form['contact_gen'] = array(
    '#type' => 'fieldset',
	'#collapsible' => TRUE,
	'#collapsed' => FALSE,
    '#title' => t('General setting'),
  );

  $form['contact_msg'] = array(
    '#type' => 'fieldset',
	'#collapsible' => TRUE,
	'#collapsed' => TRUE,
    '#title' => t('Message setting'),
  );

  $form['contact_host'] = array(
    '#type' => 'fieldset',
	'#collapsible' => TRUE,
	'#collapsed' => TRUE,
    '#title' => t('Host setting'),
  );

  $form['contact_rules'] = array(
    '#type' => 'fieldset',
	'#collapsible' => TRUE,
	'#collapsed' => TRUE,
    '#title' => t('Visibility'),
  );

  $form['contact_gen']['form_general_markup'] = array(
    '#markup' => '<br clear="all" />',
  );
  
  $form['contact_gen']['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => $variables['enabled'],
  );

  $form['contact_gen']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Form Title'),
    '#description' => t('Define your form title'),
    '#default_value' => $variables['title'],
  );
  
  $form['contact_gen']['theme'] = array(
    '#type' => 'select',
    '#title' => t('Theme'),
    '#description' => t('Contact form theme'),
    '#options' => array(
      'default' => t('Default'),
      'blue' => t('Blue'),
      'crayon' => t('Crayon'),
      'darkblue' => t('Dark Blue'),
      'green' => t('Green'),
      'grey' => t('Grey'),
      'red' => t('Red'),
    ),
    '#default_value' => $variables['theme'],
  );

  $form['contact_gen']['align'] = array(
    '#type' => 'select',
    '#title' => t('Icon Position'),
    '#description' => t('Side of the window to attach to'),
    '#options' => array(
      'left' => t('Left'),
      'right' => t('Right'),
    ),
    '#default_value' => $variables['align'],
  );

  $form['contact_gen']['top'] = array(
    '#type' => 'select',
    '#title' => t('Icon Position from Top'),
    '#description' => t('Distance from the top'),
    '#default_value' => $variables['top'],
  );
  for ($i = 0; $i <= 100; $i += 5) {
    $top["$i%"] = "$i%";
  }

  $form['contact_gen']['top']['#options'] = $top;

  $form['contact_gen']['pretext'] = array(
    "#type" => 'textarea',
    '#title' => t('Pretext Message'),
    '#description' => t('Define your pre text message, this will appear before form.'),
    '#default_value' => $variables['pretext'],
	'#cols' => 5,
  );

  $form['contact_rules']['form_denyallow_markup'] = array(
    '#markup' => t('<h3>Visibility rules</h3><p>By default, the modal contact icon shows on every page except on the <em>link</em> set above. Paths can explicity be set to hide or show below, by listing them with wild cards, one per line</p>'),
  );

  $form['contact_rules']['deny'] = array(
    "#type" => 'textarea',
    '#title' => t('Deny'),
    '#description' => t('Hide on these paths, one per line'),
    '#default_value' => $variables['deny'],
  );

  $form['contact_rules']['allow'] = array(
    "#type" => 'textarea',
    '#title' => t('Allow'),
    '#description' => t('Show on these paths, one per line'),
    '#default_value' => $variables['allow'],
  );

  $form['contact_msg']['form_admin_markup'] = array(
    '#markup' => t('<h3>Administrator message<hr style="width:30%;margin-top:5px;" /></h3>'),
  );

  $form['contact_msg']['to'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Address'),
    '#description' => t('Define your email address where submission will be delivered'),
    '#default_value' => $variables['to'],
  );

  $form['contact_msg']['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Define your subject when user submit submission, allowed tags: <strong>[name], [sitename]</strong>'),
    '#default_value' => $variables['subject'],
  );

  $form['contact_msg']['body'] = array(
    "#type" => 'textarea',
    '#title' => t('Message body'),
    '#description' => t('Define your message body, allowed tags: <strong>[name], [email], [message], [sitename], [siteurl]</strong>'),
    '#default_value' => $variables['body'],
	'#cols' => 5,
  );

  $form['contact_msg']['form_msg_markup'] = array(
    '#markup' => t('<h3>Thank you message<hr style="width:30%;margin-top:5px;" /></h3>'),
  );

  $form['contact_msg']['subthank'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Define your subject for thank you message, allowed tags: <strong>[name], [sitename]</strong>'),
    '#default_value' => $variables['subthank'],
  );

  $form['contact_msg']['thankyou'] = array(
    "#type" => 'textarea',
    '#title' => t('Message Body'),
    '#description' => t('Define your thank you message boby that will be sent to user email after submission, allowed tags: <strong>[name], [email], [message], [sitename], [siteurl]</strong>'),
    '#default_value' => $variables['thankyou'],
	'#cols' => 5,
  );


  $form['contact_host']['smtp'] = array(
    '#title' => t('SMTP Status'),
    '#type' => 'radios',
    '#options' => array(
      'off' => t('Off, will use default mail service.'),
      'on' => t('On, Use SMTP as mail server'),
    ),
    '#default_value' => $variables['smtp'],
  );

  foreach (array('off', 'on') as $smtp_status) {
    $form['modal_host'][$smtp_status]['#type'] = 'container';
    $form['modal_host'][$smtp_status]['#states']['visible'][':input[name="smtp"]'] = array('value' => $smtp_status);
  }

  $form['contact_host']['on']['host'] = array(
    '#type' => 'textfield',
    '#title' => t('Host'),
    '#description' => t('Define your SMTP host name, default: <strong>localhost</strong>'),
    '#default_value' => $variables['host'],
  );

  $form['contact_host']['on']['port'] = array(
    '#type' => 'textfield',
    '#title' => t('Port'),
    '#description' => t('Define your SMTP Port.'),
    '#default_value' => $variables['port'],
  );

  $form['contact_host']['on']['secure'] = array(
    '#type' => 'radios',
    '#title' => t('Encryption'),
    '#options' => array(
      'none' => t('No encryption.'),
      'ssl' => t('Use SSL encryption.'),
      'tls' => t('Use TLS encryption. This is not the same as STARTTLS. For most servers SSL is the recommended option.'),
    ),
    '#default_value' => $variables['secure'],
  );

  $form['contact_host']['on']['auth'] = array(
    '#type' => 'radios',
    '#title' => t('Authentication'),
    '#options' => array(
      'false' => t('No, Do not use SMTP authentication.'),
      'true' => t('Yes, Use SMTP authentication.'),
    ),
    '#default_value' => $variables['auth'],
  );

  $form['contact_host']['on']['user'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#description' => t('Define your SMTP username.'),
    '#default_value' => $variables['user'],
  );

  $form['contact_host']['on']['secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#description' => t('Define your SMTP password.'),
    '#default_value' => $variables['secret'],
  );

  $form['image'] = array(
    '#type' => 'hidden',
    '#default_value' => $variables['image'],
  );

  $form['alt'] = array(
    '#type' => 'hidden',
    '#default_value' => $variables['alt'],
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('modal_contact_system_settings_save'),
  );

  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Restore Defaults'),
    '#submit' => array('modal_contact_system_settings_reset'),
  );

  return $form;
}

/**
 * Settings save submit.
 */
function modal_contact_system_settings_save($form, &$form_state) {
  foreach ($form_state['values'] as $key => $value) {
    if (!preg_match('/^form_|^op|^submit|^reset/', $key)) {
      $variables[$key] = $value;
    }
    if ($key == 'class') {
      $variables[$key] = explode(' ', $value);
    }
  }

  variable_set('modal_contact', $variables);
  drupal_theme_rebuild();
}

/**
 * Settings reset submit.
 */
function modal_contact_system_settings_reset($form, &$form_state) {
  module_load_install('modal_contact');
  modal_contact_install();
  drupal_theme_rebuild();
}
