<?php

/**
 * Implements hook_webaccess.
 *
 * This allows projects to perform tasks just before the user
 * is logged in via webaccess.  You can use this to execute
 * environment specific code as the user is about to be logged in.
 */
function hook_webaccess() {
  
}

/**
 * Implements hook_webaccess_about_to_deny_access().
 *
 * This is a hook that fires very late in the page retrieval
 * process.  This can be used to try and clean up accidental
 * access denied errors from webaccess integrations. The
 * stupid name for this hook is to avoid conflicts with access
 * control modules.
 *
 * The below example is part of webaccess_catch_ad.module
 * which attempts to prevent an access denied error if it can
 * be avoided.  This should only be on sites that do
 * not allow non-webaccess logins.
 */
function hook_webaccess_about_to_deny_access() {
  // if person is logged out and about to get access denied error
  // force them to login and redirect back here
  // this could become transparent if they've logged into webaccess
  // but not the drupal site yet
  if ($GLOBALS['user']->uid == 0) {
    $dest = drupal_get_destination();
    $options = array('query' => array('redirect_url' => $base_url . base_path() . $dest['destination']));
    drupal_goto('login/cosign', $options);
  }
}