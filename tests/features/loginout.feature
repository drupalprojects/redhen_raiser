Feature: Log in and out of the site
  In order to maintain an account
    As a site visitor
    I need to log in and out of the site.

#@javascript
Scenario: Logs in to the site
  Given I am on "/"
  When I follow "Login"
    And I fill in "E-mail" with "admin@example.com"
    And I fill in "Password" with "admin"
    And I press "Log In"
  Then I should see "Log out"
    And I should see "My account"

Scenario: Logs out of the site
  Given I am on "/"
  When I follow "Login"
    And I fill in "E-mail" with "admin@example.com"
    And I fill in "Password" with "admin"
    And I press "Log In"
    And I follow "Log out"
  Then I should see "Login"
    And I should not see "My account"

Scenario: Attempts login with wrong credentials.
  Given I am on "/"
  When I follow "Login"
    And I fill in "E-mail" with "badusername@notreal.com"
    And I fill in "Password" with "boguspass"
    And I press "Log In"
  Then I should see "Sorry, unrecognized username or password."
    And I should not see "My account"
