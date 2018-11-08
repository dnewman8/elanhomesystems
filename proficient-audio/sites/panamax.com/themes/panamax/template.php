<?php
/**
 * Implements theme_preprocess_page().
 */
function panamax_preprocess_page(&$vars, $hook) {

    // Set page titles for certain content types.
    if (!empty($vars['node'])) {
        switch ($vars['node']->type) {
            case 'cb_blog':
                $vars['title'] = t('The Connected Home');
                break;
        }
    }
}
