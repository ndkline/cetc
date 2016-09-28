<?php
/**
 * @file
 * webaccess_admauto_example.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function webaccess_admauto_example_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
