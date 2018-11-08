<?php

/**
 * Here we override the default HTML output of drupal.
 * refer to https://drupal.org/node/457740
 */

// Auto-rebuild the theme registry during theme development.
if (theme_get_setting('corebrands_rebuild_registry')) {
  // Rebuild .info data.
  system_rebuild_theme_data();
  // Rebuild theme registry.
  drupal_theme_rebuild();
}

/**
 * Implements hook_html_head_alter().
 */
function corebrands_html_head_alter(&$head_elements) {
  global $theme_key;

  $path = drupal_get_path('theme', $theme_key);

  if (file_uri_scheme($path)) {
    $path = file_stream_wrapper_uri_normalize($path);
  }
  else {
    $path = rtrim($path, '/\\');
  }

  $touchicon_57x57 = drupal_strip_dangerous_protocols($path . '/icons/apple-touch-icon-57x57.png');
  if (file_exists($touchicon_57x57)) {
    $head_elements['touchicon_57x57'] = array(
      '#type' => 'html_tag',
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '57x57',
        'type' => 'image/png',
        'href' => url($touchicon_57x57, array('absolute' => TRUE)),
      ),
      '#weight' => 101,
    );
  }

  $favicon_32x32 = drupal_strip_dangerous_protocols($path . '/icons/favicon-32x32.png');
  if (file_exists($favicon_32x32)) {
    $head_elements['favicon_32x32'] = array(
      '#type' => 'html_tag',
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'sizes' => '32x32',
        'type' => 'image/png',
        'href' => url($favicon_32x32, array('absolute' => TRUE)),
      ),
      '#weight' => 102,
    );
  }

  $favicon_16x16 = drupal_strip_dangerous_protocols($path . '/icons/favicon-16x16.png');
  if (file_exists($favicon_16x16)) {
    $head_elements['favicon_16x16'] = array(
      '#type' => 'html_tag',
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'sizes' => '16x16',
        'type' => 'image/png',
        'href' => url($favicon_16x16, array('absolute' => TRUE)),
      ),
      '#weight' => 103,
    );
  }

  $favicon_ico = drupal_strip_dangerous_protocols($path . '/icons/favicon.ico');
  if (file_exists($favicon_ico)) {
    // Remove the default "shortcut icon", if we are using the theme defined icon.
    unset($head_elements['metatag_shortcut icon']);

    $head_elements['favicon_ico'] = array(
      '#type' => 'html_tag',
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'shortcut icon',
        'href' => url($favicon_ico, array('absolute' => TRUE)),
        'type' => 'image/vnd.microsoft.icon',
      ),
      '#weight' => 104,
    );
  }
}

/**
 * Implements theme_preprocess_html().
 */
function corebrands_preprocess_html(&$vars) {
    global $user, $language, $theme_key;

    // HTML Attributes
    // Use a proper attributes array for the html attributes.
    $vars['html_attributes'] = array();
    $vars['html_attributes']['lang'][] = $language->language;
    $vars['html_attributes']['dir'][] = $language->dir;

    // Convert RDF Namespaces into structured data using drupal_attributes.
    $vars['rdf_namespaces'] = array();
    if (function_exists('rdf_get_namespaces')) {
        foreach (rdf_get_namespaces() as $prefix => $uri) {
            $prefixes[] = $prefix . ': ' . $uri;
        }
        $vars['rdf_namespaces']['prefix'] = implode(' ', $prefixes);
    }

    // Flatten the HTML attributes and RDF namespaces arrays.
    $vars['html_attributes'] = drupal_attributes($vars['html_attributes']);
    $vars['rdf_namespaces'] = drupal_attributes($vars['rdf_namespaces']);

    if (!$vars['is_front']) {
        // Add unique classes for each page and website section
        $path = drupal_get_path_alias($_GET['q']);
        list($section, ) = explode('/', $path, 2);
        $vars['classes_array'][] = 'with-subnav';
    }

    // Prepare the front-page intro variables for the logo and the slogan.
    $intro_logo_vars = array(
      'path' => theme_get_setting('logo'),
      'alt' => $theme_key,
      'title' => $theme_key,
      'attributes' => array('class' => array('pg-loading-logo', "pg-loading-logo-$theme_key")),
    );
    $vars['intro_logo'] = theme('image', $intro_logo_vars);

    $vars['intro_slogan'] = '';
    if (variable_get('site_slogan', '') !== '') {
      $vars['intro_slogan'] = '<p>' . filter_xss_admin(variable_get('site_slogan', '')) . '</p>';
    }

    // Determine the Google Schema.
    $vars['google_schema'] = '';

    // Special case for Elan.
    if (defined('COREBRANDS_BRAND') && COREBRANDS_BRAND == 'ELAN') {
        $vars['google_schema'] = '
            <script type="application/ld+json">
            {
              "@context": "http://schema.org",
              "@type": "Corporation",
              "name": "ELAN",
              "url": "https://www.elanhomesystems.com/",
              "logo": "https://www.elanhomesystems.com/sites/elanhomesystems.com/themes/elan/logo.png",
              "contactPoint": {
                "@type": "ContactPoint",
                "telephone": "+1-800-472-5555",
                "contactType": "sales"
              },
              "sameAs": [
                "https://www.facebook.com/elanhomesystems",
                "https://twitter.com/elanhomesystems",
                "https://www.youtube.com/user/ELANHOMESYSTEMS"
              ]
            }
            </script>';
    }

    // Google Schema for product pages.
    if ($node = menu_get_object()) {

        if ($node->type == 'cb_product') {
            $image_url = '';
            $description = '';
            $brand = defined('COREBRANDS_BRAND') ? COREBRANDS_BRAND : '';

            if (!empty($node->field_product_image)) {
                $image_url = file_create_url($node->field_product_image['und'][0]['uri']);
            }

            if (!empty($node->field_product_description)) {
                $description = $node->field_product_description['und'][0]['value'];
            }


            $vars['google_schema'] = '
            <script type="application/ld+json">
            {
             "@context": "http://schema.org/",
             "@type": "Product",
             "name": "' . $node->title . '",
             "image": [
               "' . $image_url .'"
              ],
             "description": "' . strip_tags($description) . '",
             "brand": {
               "@type": "Thing",
               "name": "' . $brand . '"
             }
            }
            </script>';
        }
    }

}

function corebrands_menu_tree($variables) {
  return '<ul itemscope itemtype="http://www.schema.org/SiteNavigationElement" class="menu">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_preprocess_page().
 */
function corebrands_preprocess_page(&$vars, $hook) {
    // Make sure tabs is empty.
    if (empty($vars['tabs']['#primary']) && empty($vars['tabs']['#secondary'])) {
        $vars['tabs'] = '';
    }

    $vars['section_title'] = '';


    // Set page titles for certain content types.
    if (!empty($vars['node'])) {
        switch ($vars['node']->type) {
            case 'cb_press':
                $vars['section_title'] = t('Press Releases');
                break;

            case 'cb_blog':
                $vars['title'] = t('Blog');
                break;

            case 'cb_showcase':
                $showcase_type = field_view_field('node', $vars['node'], 'field_showcase_type');
                $vars['title'] = $showcase_type[0]['#markup'];
                switch ($showcase_type[0]['#markup']){
                    case 'Commercial':
                        $showcase_type_id = 1;
                        break;
                    case 'Residential':
                        $showcase_type_id = 2;
                        break;
                    default :
                        $showcase_type_id = 0;
                }

                $vars['gallery_breadcrumbs'] = '<a href="/" class="back-link">Home > </a><a href="/gallery" class="back-link">Gallery > </span><a href="/gallery?qt-gallery_tab=' . $showcase_type_id .'" class="back-link">' . $showcase_type[0]['#markup'] . '</a>';

                break;
        }
    }
}

/**
 * Implements theme_preprocess_node().
 */
function corebrands_preprocess_node(&$vars) {
    $vars['classes_array'][] = 'view-mode-' . $vars['view_mode'];

    switch($vars['type']) {
        case 'cb_rotato':
            $vars['image_style'] = $vars['field_rotato_image_style'][LANGUAGE_NONE][0]['value'];

            $vars['classes_array'][] = $vars['image_style'];
            $vars['classes_array'][] = 'font-' . $vars['field_rotato_font'][LANGUAGE_NONE][0]['value'];
            $vars['classes_array'][] = 'bg-' . $vars['field_rotato_background'][LANGUAGE_NONE][0]['value'];
            break;

        case 'cb_showcase':

            if ($vars['view_mode'] == 'gallery') {
                $threshold = '700px';
                $vars['images'] = [];
                $sc_style = $vars['field_showcase_style'][LANGUAGE_NONE][0]['value'];
                $vars['classes_array'][] = 'gallery-' . $sc_style;
                $image_square = !empty($vars['field_showcase_square']) ? $vars['field_showcase_square'][0] : null;
                $image_landscape = !empty($vars['field_showcase_landscape']) ? $vars['field_showcase_landscape'][0] : null;;
                $image_portrait = !empty($vars['field_showcase_portrait']) ? $vars['field_showcase_portrait'][0] : null;;


                switch ($sc_style) {
                    case 'tile_square':
                        if (!empty($image_square)) {
                            $vars['images'][] = '<img src="'
                                . image_style_url('gallery_square', $image_square['uri'])
                                . '" alt="' . $image_square['alt'] . '" title="' . $image_square['title'] . '">';
                        }

                        break;

                    case 'tile_portrait':
                        if (!empty($image_square)) {
                            $vars['images'][] = '<source media="(max-width: ' . $threshold . ')" srcset="'
                                . image_style_url('gallery_square', $image_square['uri']) . '">';
                        }

                        if (!empty($image_portrait)) {
                            $vars['images'][] = '<img src="'
                                . image_style_url('gallery_portrait', $image_portrait['uri'])
                                . '" alt="' . $image_portrait['alt'] . '" title="' . $image_portrait['title'] . '">';
                        }

                        break;

                    case 'tile_landscape':
                        if (!empty($image_square)) {
                            $vars['images'][] = '<source media="(max-width: ' . $threshold . ')" srcset="'
                                . image_style_url('gallery_square', $image_square['uri']) . '">';
                        }

                        if (!empty($image_landscape)) {
                            $vars['images'][] = '<img src="'
                                . image_style_url('gallery_landscape', $image_landscape['uri'])
                                . '" alt="' . $image_landscape['alt'] . '" title="' . $image_landscape['title'] . '">';
                        }
                        break;
                }
            }

            break;

        case 'cb_blog':
            // Load the full user information.
            $author = user_load($vars['node']->uid);
            $vars['author_name'] = $author->field_user_name[LANGUAGE_NONE][0]['safe_value'];

            // Get the related blog posts.
            if ($vars['view_mode'] == 'full') {
                $view = views_get_view('blog');
                $output = $view->preview('block_related');

                if ($view->result) {
                    $vars['blog_related'] = $output;
                }
            }

            break;

        case 'page':
            // Handle dealer search form.
            if (drupal_get_path_alias(current_path()) === 'find-dealer') {
                $params = drupal_get_query_parameters();

                if (!empty($params['zip_code'])) {
                    $vars['classes_array'][] = 'has-results';
                }
            }

            break;

        case 'cb_press':

            // Get the related press releases.
            if ($vars['view_mode'] == 'full') {
                $view = views_get_view('press_releases');
                $output = $view->preview('block_1');

                if ($view->result) {
                    $vars['press_related'] = $output;
                }
            }


            break;

        case 'cb_product':
            // Check, if a featured image is set. If not, take the first one from the feed.
            if (empty($vars['field_product_featured_image'])
                && !empty($vars['field_product_image'])) {

                $product_images = field_get_items('node', $vars['node'], 'field_product_image');

                $vars['content']['field_product_featured_image'] = [
                    '#theme' => 'image_style',
                    '#path' => $product_images[0]['uri'],
                    '#style_name' => $vars['view_mode'] == 'teaser' ? 'product_tier_3' : 'product_featured',
                    '#alt' => $product_images[0]['alt'],
                    '#title' => $product_images[0]['title'],
                ];
            }

            // Create a back link, if this product's category or sub-category is in the menu
            if ($vars['view_mode'] == 'full') {
                $main_menu = menu_load_links('main-menu');

                if (!empty($vars['field_product_category'])) {
                    $category = taxonomy_term_load($vars['field_product_category'][LANGUAGE_NONE][0]['tid']);
                    $category_path = 'products/' . str_replace(' ', '-', strtolower($category->name)) . '/all/all';

                    foreach ($main_menu as $link) {
                        if ($link['link_path'] == $category_path) {
                            $vars['back_link'] = url($link['link_path']);
                            $vars['back_link_label'] = $category->name;
                        }
                    }
                }

                if (!empty($vars['field_prod_sub_category'])) {
                    $sub_category = taxonomy_term_load($vars['field_prod_sub_category'][LANGUAGE_NONE][0]['tid']);
                    $sub_category_path = 'products/all/' . str_replace(' ', '-', strtolower($sub_category->name) . '/all');

                    foreach ($main_menu as $link) {
                        if ($link['link_path'] == $sub_category_path) {
                            $vars['back_link'] = url($link['link_path']);
                            $vars['back_link_label'] = $sub_category->name;
                        }
                    }
                }

                // Make sure we display either the model number or item id.
                if (empty($vars['field_product_model']) && !empty($vars['field_product_item_id'])) {
                    $item_id = field_view_field('node', $vars['node'], 'field_product_item_id');
                    $item_id['#field_name'] = 'field_product_model';
                    $item_id['#label_display'] = 'hidden';
                    $vars['content']['field_product_model'] = $item_id;
                }
            }
            break;
    }

    // Custom view mode theming suggestions.
    if($vars['view_mode'] == 'gallery') {
        $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__gallery';
    }
}

/**
 * Implements template_preprocess_field()
 */
function corebrands_preprocess_field(&$vars) {

    // Make sure the alt and title properties are not empty for images.
    if ($vars['element']['#field_type'] == 'image') {

        foreach ($vars['element']['#items'] as $i => $img) {
            // Convert file name into something readable.
            $file_tokens = explode('.', $img['filename']);
            $name = $file_tokens[0];
            $name = ucwords(str_replace(['-', '_'], ' ', $name));

            if (empty($img['alt'])) {
                $vars['items'][$i]['#item']['alt'] = $name;
            }

            if (empty($img['title'])) {
                $vars['items'][$i]['#item']['title'] = $name;
            }
        }
    }
}

/**
 * Implements template_preprocess_block()
 */
function corebrands_preprocess_block(&$vars) {
    // Add the Bean types to the block classes.
    if (!empty($vars['elements']['bean'])) {
        $delta = $vars['block']->delta;
        if (isset($delta) && isset($vars['elements']['bean'][$delta])) {
            $bean = $vars['elements']['bean'][$delta]['#entity'];
            $wrapper = entity_metadata_wrapper('bean', $bean);

            $vars['classes_array'][] = 'block-bean-' . str_replace('_','-', $wrapper->getBundle());
        }
    }
}

/**
 * Implements hook_views_pre_render().
 *
 * - Hide product images, if there are less than 2.
 */
function corebrands_views_pre_render(&$view) {
    if ($view->name == 'product_details' && $view->current_display == 'block_product_images') {
        // Don't display this view, if there less than 2 images
        if (count($view->result) < 2) {
            $view->result = [];
        }
    }
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return
 *   A string containing the breadcrumb output.
 */
function corebrands_breadcrumb($variables) {
    $breadcrumb = $variables['breadcrumb'];  // Determine if we are to display the breadcrumb.
    $show_breadcrumb = theme_get_setting('corebrands_breadcrumb');

    if ($show_breadcrumb == 'yes' || ($show_breadcrumb == 'admin' && arg(0) == 'admin')) {

        // Optionally get rid of the homepage link.
        $show_breadcrumb_home = theme_get_setting('corebrands_breadcrumb_home');
        if (!$show_breadcrumb_home) {
            array_shift($breadcrumb);
        }
        // Return the breadcrumb with separators.
        if (!empty($breadcrumb)) {
            $breadcrumb_separator = theme_get_setting('corebrands_breadcrumb_separator');
            $trailing_separator = $title = '';
            if (theme_get_setting('corebrands_breadcrumb_title')) {
                $item = menu_get_item();
                if (!empty($item['tab_parent'])) {
                    // If we are on a non-default tab, use the tab's title.
                    $title = check_plain($item['title']);
                }
                else {
                    $title = drupal_get_title();
                }
                if ($title) {
                    $trailing_separator = $breadcrumb_separator;
                }
            }
            elseif (theme_get_setting('corebrands_breadcrumb_trailing')) {
                $trailing_separator = $breadcrumb_separator;
            }
            // Provide a navigational heading to give context for breadcrumb links to
            // screen-reader users. Make the heading invisible with .element-invisible.
            $heading = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

            return $heading . '<div class="breadcrumb">' . implode($breadcrumb_separator, $breadcrumb) . $trailing_separator . $title . '</div>';
        }
    }
    // Otherwise, return an empty string.
    return '';
}

/**
 * Implements templater_preprocess_search_results().
 */
function corebrands_preprocess_search_result(&$vars) {

    // Add item number to title
    $node = $vars['result']['node'];
    if ($node->type == 'cb_product') {

        if ($item_id = field_get_items('node', $node, 'field_product_item_id')) {
            $vars['title'] = $item_id[0]['value'] . ' - ' . $vars['title'];
        }
    }

}

function corebrands_links($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . ' itemscope itemtype="http://www.schema.org/SiteNavigationElement">';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);

      // Add first, last and active classes to the list of links to help out
      // themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
          && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . ' itemprop="name">';

      if (isset($link['href'])) {
        $link['attributes']['itemprop'] = 'url';
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for
        // adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

function corebrands_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $element['#localized_options']['attributes']['itemprop'] = 'url';
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . ' itemprop="name">' . $output . $sub_menu . "</li>\n";
}

function corebrands_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_form') {
    $form['basic']['keys']['#attributes']['placeholder'] = t('Enter some Keywords');
    $form['#submit'][0] = '_corebrands_search_form_submit';
  }
  if ($form_id == 'search_block_form') {
    $form['#submit'][0] = '_corebrands_search_box_form_submit';
  }
}

function _corebrands_search_form_submit($form, &$form_state) {
  $keys = $form_state['values']['processed_keys'];
  if ($keys == '') {
    //form_set_error('keys', t('Please enter some keywords.'));
    // Fall through to the form redirect.
    $form['basic']['keys']['#attributes']['placeholder'] = t('Enter some Keywords');
  }

  $form_state['redirect'] = $form_state['action'] . '/' . $keys;
}

function _corebrands_search_box_form_submit($form, &$form_state) {

  if (isset($_GET['destination'])) {
    unset($_GET['destination']);
  }
  if ($form_state['values']['search_block_form'] == '') {
    //form_set_error('keys', t('Please enter some keywords.'));
    $form['search_block_form']['#attributes']['placeholder'] = t('Enter some Keywords');
  }
  $form_id = $form['form_id']['#value'];
  $info = search_get_default_module_info();
  if ($info) {
    $form_state['redirect'] = 'search/' . $info['path'] . '/' . trim($form_state['values'][$form_id]);
  }
  else {
    form_set_error(NULL, t('Search is currently disabled.'), 'error');
  }
}
