<?php

/**
 * Implements theme_preprocess_html().
 */
function elan_preprocess_html(&$vars) {
    // Alter meta tag for specific paths.
    $meta_tags = [
        'products/all/user-interfaces/all' => [
         'title' => 'Smart Home Remote & Interface | ELAN Home Systems',
         'description' => 'The elegant ELAN remote, touch panels and keypad bring smart home control to wherever you need it. Check out our sleek user-friendly interface here!'
        ],
        'products/all/system-controllers/all' => [
            'title' => 'Home Theater & System Controllers | ELAN Home Systems',
            'description' => 'ELAN home system and home theater controllers bring luxury and usability together. Learn how ELAN controllers couple brains with beauty, today!'
        ],
        'products/all/multi-room-audio-video/all' => [
            'title' => 'Multi-Room Audio & Video Systems | ELAN Home Systems',
            'description' => 'ELAN simplifies multi-room audio/video control with a premium series of A/V controllers. Revolutionary flexibility over a single cable. Learn more today!'
        ],
        'products/all/amps/all' => [
            'title' => 'Smart Home Audio Amplifiers | ELAN Home Systems',
            'description' => 'Find multi-zone amplifiers for home audio and whole house audio amplifiers. Browse our affordable amps ranging from 2 to 12 channel capabilities, today!'
        ],
        'products/all/control-attach/all' => [
            'title' => 'Smart Home Automation Accessories & Attachments | ELAN Home Systems',
            'description' => 'Browse ELAN smart home automation attachments & accessories.  Find thermostats, light sensors, motion sensors, irrigation and smart sprinkler attachments.'
        ],
        'products/all/surveillance/all' => [
            'title' => 'IP Camera Systems for Smart Home Surveillance | ELAN Home Systems',
            'description' => 'Keep an eye on things at home with ELAN\'s smart home surveillance IP cameras & recorders. Weather resistant, easy to install & wireless capability.'
        ]
    ];

    $current_path = request_path();

    foreach ($meta_tags as $path => $data) {

        if ($current_path == $path) {
            $vars['head_title'] = $data['title'];

            $description = [
                '#tag' => 'meta',
                '#attributes' => [
                    'name' => 'description',
                    'content' => $data['description']
                ]
            ];

            drupal_add_html_head($description, 'description');
        }
    }
}

/**
 * Implements theme_preprocess_page().
 */
function elan_preprocess_page(&$vars, $hook) {

    // Set page titles for certain content types.
    if (!empty($vars['node'])) {
        switch ($vars['node']->type) {
            case 'cb_blog':
                $vars['title'] = t('The Connected Home');
                break;
        }
    }
}
