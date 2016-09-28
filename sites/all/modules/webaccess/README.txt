About
Originally based on webserver_auth.  Webaccess is maintained by the Drupal @ PSU community.
If you experience issues when using this module please post to the Drupal user group on Yammer.

Installation

1. Add the following lines to your Apache Config for you site.

<LocationMatch "/cosign">
  CosignProtected On
  CosignAllowPublicAccess Off
  AuthType Cosign
</LocationMatch>

If running cosign v.3 which requires /cosign/valid make sure to place it after the LocationMatch like such. This will allow both the webaccess module and cosign v.3 to work correctly.

    CosignValidReference              ^https?:\/\/.*\.psu\.edu(\/.*)?
    CosignValidationErrorRedirect      https://webaccess.psu.edu/validation_error.html

   <LocationMatch "/cosign">
      CosignProtected On
      CosignAllowPublicAccess Off
      AuthType Cosign
   </LocationMatch>

    <Location /cosign/valid>
         SetHandler          cosign
         CosignProtected     Off
         Allow from all
         Satisfy any
   </Location>

For drupal not to rewrite the url "/cosign/valid", I would recommend changing the rewrite lines in your .htaccess file in your base drupal folder and adding the following exclusion.

  # Rewrite current-style URLs of the form 'index.php?q=x'.
  RewriteCond %{REQUEST_FILENAME} !-f
  RewriteCond %{REQUEST_FILENAME} !-d
  RewriteCond %{REQUEST_URI} !^/cosign/
  RewriteRule ^(.*)$ index.php?q=$1 [L,QSA]

2. This module requires clean urls. On windows I would suggest using ISAPI_rewrite(helicon) or the URL Rewrite Module in IIS 7+. [in IIS select your site > URL Rewrite. Under 'Short URLs' add a rule: condition: {REQUEST_URI} Check if input string: Matches the Pattern Pattern: !^/cosign/ toggle: Ignore case (true)
Note: Some users reported the module working fine with non-clean urls. However, the module will still redirect to the clean url "/login/cosign" during the login process that is protected by the apache config above. Since the module does require that a particular url is cosign protected you may run into issues with not using clean urls. I will look at adding this feature option in at a later time.
3. Create a role called "Administrators" and add all current access rights to it. Then add the access id you would like to be an administrator to this new role. It is important to do this before enabling the module or you may lock yourself out of your new site. If this would happen you will need to manually disable the webaccess module.
4. Goto "admin/config/people/webaccess" and save the settings. The module doesn't have an install routine written yet. You should do this anyway.
Problems

- Someone reported that without CosignAllowPublicAccess set to On "/" under Drupal 6 that the login will not function correctly. For now I would recommend setting this under Drupal 6 till I can look into the problem. Since auth can be loaded in hook_init there may not actually be a fix for this at the current time.
Here is a normal Apache config I use for cosign
   CosignProtected On
   CosignHostName webaccess.psu.edu
   CosignRedirect https://webaccess.psu.edu/
   CosignPostErrorRedirect https://webaccess.psu.edu/post_error.html
   CosignService drupal.site.psu.edu
   CosignCrypto /etc/pki/tls/private/server.key /etc/pki/tls/certs/server.crt /etc/pki/tls/certs/
   CosignAllowPublicAccess On
   CosignHttpOnly On

   CosignValidReference              ^https?:\/\/.*\.psu\.edu(\/.*)?
   CosignValidationErrorRedirect      https://webaccess.psu.edu/validation_error.html

   <LocationMatch "/cosign">
      CosignProtected On
      CosignAllowPublicAccess Off
      AuthType Cosign
   </LocationMatch>

    <Location /cosign/valid>
         SetHandler          cosign
         CosignProtected     Off
         Allow from all
         Satisfy any
   </Location>