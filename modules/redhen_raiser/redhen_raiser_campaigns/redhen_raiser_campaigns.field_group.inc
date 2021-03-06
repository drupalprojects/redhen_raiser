<?php
/**
 * @file
 * redhen_raiser_campaigns.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function redhen_raiser_campaigns_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_customize|redhen_campaign|general|form';
  $field_group->group_name = 'group_customize';
  $field_group->entity_type = 'redhen_campaign';
  $field_group->bundle = 'general';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Customize your campaign',
    'weight' => '5',
    'children' => array(
      0 => 'field_banner_image',
      1 => 'field_promotion',
      2 => 'path',
      3 => 'promote',
      4 => 'sticky',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Customize your campaign',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-customize field-group-fieldset',
        'description' => '<span class="fieldset-description-title">Customization Tips</span>
<p>Find a great banner image: it sets the tone for the campaign and will be displayed on most of the sub-pages in the campaign.</p>',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_customize|redhen_campaign|general|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding|redhen_campaign|general|form';
  $field_group->group_name = 'group_funding';
  $field_group->entity_type = 'redhen_campaign';
  $field_group->bundle = 'general';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Timing and Funding',
    'weight' => '0',
    'children' => array(
      0 => 'redhen_campaign_goal',
      1 => 'field_end_date',
      2 => 'field_start_date',
      3 => 'field_teaser',
      4 => 'field_allow_dedication',
      5 => 'label',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Timing and Funding',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-funding field-group-fieldset',
        'description' => '<span class="fieldset-description-title">Funding Tip</span>
<p>Keep your Title concise and use the Teaser for more specifics.</p>
<p>Set an ambitious goal!</p>',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_funding|redhen_campaign|general|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_story|redhen_campaign|general|form';
  $field_group->group_name = 'group_story';
  $field_group->entity_type = 'redhen_campaign';
  $field_group->bundle = 'general';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tell your story',
    'weight' => '4',
    'children' => array(
      0 => 'field_story',
      1 => 'field_story_media',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Tell your story',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-story field-group-fieldset',
        'description' => '<span class="fieldset-description-title">Story Tip</span>
<p>Personalize your fundraiser with an image or video, and tell a story about why this cause is important.</p>',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_story|redhen_campaign|general|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Customize your campaign');
  t('Tell your story');
  t('Timing and Funding');

  return $field_groups;
}
