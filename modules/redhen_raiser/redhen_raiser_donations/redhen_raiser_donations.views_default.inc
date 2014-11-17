<?php
/**
 * @file
 * redhen_raiser_donations.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function redhen_raiser_donations_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'donations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'redhen_donation';
  $view->human_name = 'Donations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Donations';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access redhen campaign pages';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Donation: RedHen Contact contact_id */
  $handler->display->display_options['relationships']['contact']['id'] = 'contact';
  $handler->display->display_options['relationships']['contact']['table'] = 'redhen_donation';
  $handler->display->display_options['relationships']['contact']['field'] = 'contact';
  /* Relationship: Donation: RedHen Campaign Context */
  $handler->display->display_options['relationships']['redhen_campaign_context']['id'] = 'redhen_campaign_context';
  $handler->display->display_options['relationships']['redhen_campaign_context']['table'] = 'redhen_donation';
  $handler->display->display_options['relationships']['redhen_campaign_context']['field'] = 'redhen_campaign_context';
  /* Relationship: Donation: RedHen Campaign Page Context */
  $handler->display->display_options['relationships']['redhen_campaign_page_context']['id'] = 'redhen_campaign_page_context';
  $handler->display->display_options['relationships']['redhen_campaign_page_context']['table'] = 'redhen_donation';
  $handler->display->display_options['relationships']['redhen_campaign_page_context']['field'] = 'redhen_campaign_page_context';
  /* Field: Donation: Donation ID */
  $handler->display->display_options['fields']['donation_id']['id'] = 'donation_id';
  $handler->display->display_options['fields']['donation_id']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['donation_id']['field'] = 'donation_id';
  /* Field: Donation: Amount received. */
  $handler->display->display_options['fields']['received_1']['id'] = 'received_1';
  $handler->display->display_options['fields']['received_1']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['received_1']['field'] = 'received';
  $handler->display->display_options['fields']['received_1']['label'] = '';
  $handler->display->display_options['fields']['received_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['received_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['received_1']['separator'] = '';
  /* Field: Global: Math expression */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['exclude'] = TRUE;
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['expression'] = '[received_1]/100';
  /* Field: Donation: Amount received. */
  $handler->display->display_options['fields']['received']['id'] = 'received';
  $handler->display->display_options['fields']['received']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['received']['field'] = 'received';
  $handler->display->display_options['fields']['received']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['received']['alter']['text'] = '$[expression]';
  /* Field: Donation: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Donation Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
  /* Field: Donation: Comment */
  $handler->display->display_options['fields']['field_donation_comment']['id'] = 'field_donation_comment';
  $handler->display->display_options['fields']['field_donation_comment']['table'] = 'field_data_field_donation_comment';
  $handler->display->display_options['fields']['field_donation_comment']['field'] = 'field_donation_comment';
  $handler->display->display_options['fields']['field_donation_comment']['type'] = 'text_plain';
  /* Field: Contact: Billing Address - Postal code */
  $handler->display->display_options['fields']['field_billing_address_postal_code']['id'] = 'field_billing_address_postal_code';
  $handler->display->display_options['fields']['field_billing_address_postal_code']['table'] = 'field_data_field_billing_address';
  $handler->display->display_options['fields']['field_billing_address_postal_code']['field'] = 'field_billing_address_postal_code';
  $handler->display->display_options['fields']['field_billing_address_postal_code']['relationship'] = 'contact';
  $handler->display->display_options['fields']['field_billing_address_postal_code']['label'] = 'Zip Code';
  /* Field: RedHen Campaign: Campaign Name */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'redhen_campaign';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['relationship'] = 'redhen_campaign_context';
  /* Field: RedHen Campaign Page: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'redhen_campaign_page';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'redhen_campaign_page_context';
  /* Field: RedHen Campaign Page: Campaign Page Name */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'redhen_campaign_page';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['relationship'] = 'redhen_campaign_page_context';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'redhen/donations';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'redhen/donations/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export 2 */
  $handler = $view->new_display('views_data_export', 'Data export 2', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'donations/excel';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['donations'] = $view;

  $view = new view();
  $view->name = 'my_donations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'redhen_donation';
  $view->human_name = 'My Donations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Donations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'donation_id' => 'donation_id',
    'received' => 'received',
    'field_donation_comment' => 'field_donation_comment',
    'created' => 'created',
    'entity_id' => 'entity_id',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'donation_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'received' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_donation_comment' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Donation: RedHen Campaign Context */
  $handler->display->display_options['relationships']['redhen_campaign_context']['id'] = 'redhen_campaign_context';
  $handler->display->display_options['relationships']['redhen_campaign_context']['table'] = 'redhen_donation';
  $handler->display->display_options['relationships']['redhen_campaign_context']['field'] = 'redhen_campaign_context';
  $handler->display->display_options['relationships']['redhen_campaign_context']['required'] = TRUE;
  /* Relationship: Donation: RedHen Campaign Page Context */
  $handler->display->display_options['relationships']['redhen_campaign_page_context']['id'] = 'redhen_campaign_page_context';
  $handler->display->display_options['relationships']['redhen_campaign_page_context']['table'] = 'redhen_donation';
  $handler->display->display_options['relationships']['redhen_campaign_page_context']['field'] = 'redhen_campaign_page_context';
  $handler->display->display_options['relationships']['redhen_campaign_page_context']['required'] = TRUE;
  /* Relationship: RedHen Campaign Page: Team Page */
  $handler->display->display_options['relationships']['team']['id'] = 'team';
  $handler->display->display_options['relationships']['team']['table'] = 'redhen_campaign_page';
  $handler->display->display_options['relationships']['team']['field'] = 'team';
  $handler->display->display_options['relationships']['team']['relationship'] = 'redhen_campaign_page_context';
  $handler->display->display_options['relationships']['team']['label'] = 'Team';
  /* Field: Donation: Donation ID */
  $handler->display->display_options['fields']['donation_id']['id'] = 'donation_id';
  $handler->display->display_options['fields']['donation_id']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['donation_id']['field'] = 'donation_id';
  $handler->display->display_options['fields']['donation_id']['exclude'] = TRUE;
  /* Field: RedHen Campaign: Redhen campaign ID */
  $handler->display->display_options['fields']['campaign_id']['id'] = 'campaign_id';
  $handler->display->display_options['fields']['campaign_id']['table'] = 'redhen_campaign';
  $handler->display->display_options['fields']['campaign_id']['field'] = 'campaign_id';
  $handler->display->display_options['fields']['campaign_id']['relationship'] = 'redhen_campaign_context';
  $handler->display->display_options['fields']['campaign_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['campaign_id']['separator'] = '';
  /* Field: RedHen Campaign Page: Redhen campaign page ID */
  $handler->display->display_options['fields']['page_id']['id'] = 'page_id';
  $handler->display->display_options['fields']['page_id']['table'] = 'redhen_campaign_page';
  $handler->display->display_options['fields']['page_id']['field'] = 'page_id';
  $handler->display->display_options['fields']['page_id']['relationship'] = 'redhen_campaign_page_context';
  $handler->display->display_options['fields']['page_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['page_id']['separator'] = '';
  /* Field: Donation: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'n/j/y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
  /* Field: Donation: Comment */
  $handler->display->display_options['fields']['field_donation_comment']['id'] = 'field_donation_comment';
  $handler->display->display_options['fields']['field_donation_comment']['table'] = 'field_data_field_donation_comment';
  $handler->display->display_options['fields']['field_donation_comment']['field'] = 'field_donation_comment';
  /* Field: RedHen Campaign Page: Campaign Page Name */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'redhen_campaign_page';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['relationship'] = 'redhen_campaign_page_context';
  $handler->display->display_options['fields']['label_1']['label'] = 'Fundraiser';
  $handler->display->display_options['fields']['label_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label_1']['alter']['path'] = 'redhen_campaign/page/[page_id]';
  /* Field: RedHen Campaign: Campaign Name */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'redhen_campaign';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['relationship'] = 'redhen_campaign_context';
  $handler->display->display_options['fields']['label']['label'] = 'Campaign';
  $handler->display->display_options['fields']['label']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['path'] = 'redhen_campaign/[campaign_id]';
  /* Field: Donation: Amount received. */
  $handler->display->display_options['fields']['received']['id'] = 'received';
  $handler->display->display_options['fields']['received']['table'] = 'redhen_donation';
  $handler->display->display_options['fields']['received']['field'] = 'received';
  $handler->display->display_options['fields']['received']['label'] = 'Amount';
  $handler->display->display_options['fields']['received']['prefix'] = '$';
  /* Contextual filter: Donation: RedHen Contact contact_id */
  $handler->display->display_options['arguments']['contact']['id'] = 'contact';
  $handler->display->display_options['arguments']['contact']['table'] = 'redhen_donation';
  $handler->display->display_options['arguments']['contact']['field'] = 'contact';
  $handler->display->display_options['arguments']['contact']['default_action'] = 'default';
  $handler->display->display_options['arguments']['contact']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['contact']['default_argument_options']['code'] = '$user = user_load(arg(1));
$email = $user->mail;
$result = redhen_contact_load_by_mail($email);
if ($result) {
$contact = reset($result);
return $contact->contact_id;
}
else return -1;';
  $handler->display->display_options['arguments']['contact']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['contact']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['contact']['summary_options']['items_per_page'] = '25';

  /* Display: My Donations Page */
  $handler = $view->new_display('page', 'My Donations Page', 'my_donations_page');
  $handler->display->display_options['display_comment'] = 'see: redhen_raiser_donations_views_pre_render()';
  $handler->display->display_options['path'] = 'user/%user/my-donations';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My Donations';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['my_donations'] = $view;

  return $export;
}