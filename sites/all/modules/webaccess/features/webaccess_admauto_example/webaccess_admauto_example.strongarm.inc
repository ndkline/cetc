<?php
/**
 * @file
 * webaccess_admauto_example.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function webaccess_admauto_example_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webaccess_admauto_role';
  $strongarm->value = 'guest';
  $export['webaccess_admauto_role'] = $strongarm;

  return $export;
}
