<?php
/**
 * @file
 * webaccess_authentication_required.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function webaccess_authentication_required_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webaccess_disallow_username_change';
  $strongarm->value = 1;
  $export['webaccess_disallow_username_change'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webaccess_domain';
  $strongarm->value = 'psu.edu';
  $export['webaccess_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webaccess_init_enable';
  $strongarm->value = 1;
  $export['webaccess_init_enable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webaccess_secure_site';
  $strongarm->value = 1;
  $export['webaccess_secure_site'] = $strongarm;

  return $export;
}
