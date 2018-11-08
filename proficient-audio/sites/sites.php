<?php

/**
 * @file
 * Configuration file for Drupal's multi-site directory aliasing feature.
 *
 * This file allows you to define a set of aliases that map hostnames, ports, and
 * pathnames to configuration directories in the sites directory. These aliases
 * are loaded prior to scanning for directories, and they are exempt from the
 * normal discovery rules. See default.settings.php to view how Drupal discovers
 * the configuration directory when no alias is found.
 *
 * Aliases are useful on development servers, where the domain name may not be
 * the same as the domain of the live server. Since Drupal stores file paths in
 * the database (files, system table, etc.) this will ensure the paths are
 * correct when the site is deployed to a live server.
 *
 * To use this file, copy and rename it such that its path plus filename is
 * 'sites/sites.php'. If you don't need to use multi-site directory aliasing,
 * then you can safely ignore this file, and Drupal will ignore it too.
 *
 * Aliases are defined in an associative array named $sites. The array is
 * written in the format: '<port>.<domain>.<path>' => 'directory'. As an
 * example, to map http://www.drupal.org:8080/mysite/test to the configuration
 * directory sites/example.com, the array should be defined as:
 * @code
 * $sites = array(
 *   '8080.www.drupal.org.mysite.test' => 'example.com',
 * );
 * @endcode
 * The URL, http://www.drupal.org:8080/mysite/test/, could be a symbolic link or
 * an Apache Alias directive that points to the Drupal root containing
 * index.php. An alias could also be created for a subdomain. See the
 * @link http://drupal.org/documentation/install online Drupal installation guide @endlink
 * for more information on setting up domains, subdomains, and subdirectories.
 *
 * The following examples look for a site configuration in sites/example.com:
 * @code
 * URL: http://dev.drupal.org
 * $sites['dev.drupal.org'] = 'example.com';
 *
 * URL: http://localhost/example
 * $sites['localhost.example'] = 'example.com';
 *
 * URL: http://localhost:8080/example
 * $sites['8080.localhost.example'] = 'example.com';
 *
 * URL: http://www.drupal.org:8080/mysite/test/
 * $sites['8080.www.drupal.org.mysite.test'] = 'example.com';
 * @endcode
 *
 * @see default.settings.php
 * @see conf_path()
 * @see http://drupal.org/documentation/install/multi-site
 */

$sites = array(
  '2gig.local' => '2gig.com',
  'dev-2gig.pantheonsite.io' => '2gig.com',
  'test-2gig.pantheonsite.io' => '2gig.com',
  'live-2gig.pantheonsite.io' => '2gig.com',

  'elanhomesystems.local' => 'elanhomesystems.com',
  'dev-elanhomesystems.pantheonsite.io' => 'elanhomesystems.com',
  'test-elanhomesystems.pantheonsite.io' => 'elanhomesystems.com',
  'live-elanhomesystems.pantheonsite.io' => 'elanhomesystems.com',

  'panamax.local' => 'panamax.com',
  'dev-panamax.pantheonsite.io' => 'panamax.com',
  'test-panamax.pantheonsite.io' => 'panamax.com',
  'live-panamax.pantheonsite.io' => 'panamax.com',

  'furmanpower.local' => 'furmanpower.com',
  'dev-furman-power.pantheonsite.io' => 'furmanpower.com',
  'test-furman-power.pantheonsite.io' => 'furmanpower.com',
  'live-furman-power.pantheonsite.io' => 'furmanpower.com',

  'corebrands.local' => 'corebrands.com',
  'dev-corebrands.pantheonsite.io' => 'corebrands.com',
  'test-corebrands.pantheonsite.io' => 'corebrands.com',
  'live-corebrands.pantheonsite.io' => 'corebrands.com',

  'elan-dealer.local' => 'dealer.elanhomesystems.com',
  'dev-elan-dealer.pantheonsite.io' => 'dealer.elanhomesystems.com',
  'test-elan-dealer.pantheonsite.io' => 'dealer.elanhomesystems.com',
  'live-elan-dealer.pantheonsite.io' => 'dealer.elanhomesystems.com',

  'gefen.local' => 'gefen.com',
  'dev-gefen.pantheonsite.io' => 'gefen.com',
  'test-gefen.pantheonsite.io' => 'gefen.com',
  'live-gefen.pantheonsite.io' => 'gefen.com',

  'niles-audio.local' => 'nilesaudio.com',
  'dev-niles-audio.pantheonsite.io' => 'nilesaudio.com',
  'test-niles-audio.pantheonsite.io' => 'nilesaudio.com',
  'live-niles-audio.pantheonsite.io' => 'nilesaudio.com',

  'speakercraft.local' => 'nilesaudio.com',
  'dev-speakercraft.pantheonsite.io' => 'speakercraft.com',
  'test-speakercraft.pantheonsite.io' => 'speakercraft.com',
  'live-speakercraft.pantheonsite.io' => 'speakercraft.com',

  'sunfire.local' => 'nilesaudio.com',
  'dev-sunfire.pantheonsite.io' => 'sunfire.com',
  'test-sunfire.pantheonsite.io' => 'sunfire.com',
  'live-sunfire.pantheonsite.io' => 'sunfire.com',

  'xantech.local' => 'nilesaudio.com',
  'dev-xantech.pantheonsite.io' => 'xantech.com',
  'test-xantech.pantheonsite.io' => 'xantech.com',
  'live-xantech.pantheonsite.io' => 'xantech.com',
);
