<?php

/**
 * Define dealer search form.
 */
function cb_dealer_search_form($form, &$form_state) {

    $params = drupal_get_query_parameters();

    $form['#attributes']['class'] = ['dealer-search-form'];

    $form['name'] = [
        '#type' => 'textfield',
        '#title' => t(''),
        '#attributes' => [
            'placeholder' => t('Your Name'),
        ],
        '#size' => 60,
        '#prefix' => '<div class="container"><div class="get-started-block">',
        '#default_value' => !empty($params['name']) ? $params['name'] : ''
    ];

    $form['email'] = [
        '#type' => 'textfield',
        '#title' => t(''),
        '#attributes' => [
            'placeholder' => t('Your Email'),
        ],
        '#size' => 60,
        '#default_value' => !empty($params['email']) ? $params['email'] : ''
    ];


    $form['zip_code'] = [
        '#type' => 'textfield',
        '#title' => t(''),
        '#attributes' => [
            'placeholder' => t('Zip Code'),
        ],
        '#size' => 10,
        '#default_value' => !empty($params['zip_code']) ? $params['zip_code'] : ''
    ];

    $form['search'] = [
        '#type' => 'submit',
        '#value' => t('Show Dealers'),
        '#name' => 'search',
        '#suffix' => '</div></div>'
    ];

    return $form;
}

/**
 * Validation callback for dealer search form.
 */
function cb_dealer_search_form_validate($form, &$form_state) {
    // Zip code has to be numeric and 5 digits for the USA.
    if (empty($form_state['values']['zip_code']) ||
        !is_numeric($form_state['values']['zip_code']) ||
        strlen(trim($form_state['values']['zip_code'])) <> 5) {

        form_set_error('zip_code', t('Zip code needs to be numeric and 5 digits long.'));
    }

    if (empty($form_state['values']['name'])) {
        form_set_error('name', t('Please enter your name.'));
    }

    if (empty($form_state['values']['email'])) {
        form_set_error('email', t('Please enter your email.'));
    }

    if (!valid_email_address($form_state['values']['email'])) {
        form_set_error('email', t('Please enter a valid email address.'));
    }
}

/**
 * Submit callback for dealer search form.
 */
function cb_dealer_search_form_submit($form, $form_state) {
    $query = [
        'name' => $form_state['values']['name'],
        'email' => $form_state['values']['email'],
        'zip_code' => $form_state['values']['zip_code']
    ];

    // Add customer information to the leads table.
    db_insert('cb_dealer_leads')
        ->fields([
            'name' => $query['name'],
            'email' => $query['email'],
            'zip_code' => $query['zip_code'],
            'created_at' => REQUEST_TIME
        ])
        ->execute();


    // Redirect to search page.
    drupal_goto('find-dealer', ['query' => $query]);
}
