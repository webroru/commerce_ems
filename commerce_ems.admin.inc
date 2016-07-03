<?php

/**
 * @file
 * EMS shipping settings form
 */

function commerce_ems_settings_form() {
	$form = array();
	
	$form['origin'] = array(
		'#type' => 'fieldset',
		'#title' => t('Ship From Address'),
		'#collapsible' => TRUE,
	);
	
	$form['origin']['commerce_ems_region'] = array(
		'#type' => 'textfield',
		'#title' => t('Region'),
		'#default_value' => variable_get('commerce_ems_region')
	);

	$form['origin']['commerce_ems_city'] = array(
		'#type' => 'textfield',
		'#title' => t('City'),
		'#default_value' => variable_get('commerce_ems_city')
	);
	
	$form['commerce_ems_extra_charge_type'] = array(
		'#type' => 'select',
		'#options' => array('percent'=>'percent', 'fixed'=>'fixed'),
		'#title' => t('Extra charge type'),
		'#default_value' => variable_get('commerce_ems_extra_charge_type', 'percent'),
		'#description' => t('Adds extra amount to calculated shipping price'),
	);
	
	$form['commerce_ems_extra_charge'] = array(
		'#type' => 'textfield',
		'#title' => t('Extra charge amount'),
		'#description' => t('Numeric value, without "%" and other symbols. Leave 0 to disable extra charges.'),
		'#default_value' => variable_get('commerce_ems_extra_charge', 0),
		'#size' => 15,
		'#field_suffix' =>
			variable_get('commerce_ems_extra_charge_type', 'percent') == 'percent' ? '%' : 'р.',
	);
	$form['commerce_ems_city_cleanup'] = array(
		'#type' => 'textfield',
		'#title' => t('Remove these words/symbols from city'),
//		'#default_value' => variable_get('commerce_ems_city_cleanup', 'г.|пос.'),
		'#default_value' => variable_get('commerce_ems_city_cleanup', '/автономная/|/автономный/|/край/|/регион/|/область/|/республика/|/ г$/|/ обл$/|/ пос$/|/ респ$/|/ АО$/'),
		'#description' => t('Comma-separated words to remove from customer entered city name'),
	);
	$form['commerce_ems_fixed_price'] = array(
		'#type' => 'textfield',
		'#title' => t('Fixed delivery price'),
		'#default_value' => variable_get('commerce_ems_fixed_price', 600),
		'#description' => t('If EMS website is down, this price is used as a EMS delivery price. Leave 0 to not use fixed price approach (in that case error is shown to user during calculating delivery price.'),
		'#size' => 15,
		'#field_suffix' => 'р.',
	);
/*		$form['commerce_ems_insurance'] = array(
		'#type' => 'checkbox',
		'#title' => t('Add EMS insurance to delivery price'),
		'#default_value' => variable_get('commerce_ems_insurance', TRUE),
		'#description' => t('Adds 1% of order total to delivery price.'),
	);*/
	$form['commerce_ems_default_weight'] = array(
		'#type' => 'textfield',
		'#title' => t('Default product weight'),
		'#default_value' => variable_get('commerce_ems_default_weight', 0),
		'#description' => t('EMS requires weight for each item. That means, that if
		 you forgot to enter weight in some product, shipping calculation won\'t work. You can specify default product weight here to avoid that behavior. Leave 0 to make this feature inactive.'),
		'#size' => 10,
		'#field_suffix' => 'kg',
	);
	
	return system_settings_form($form);
}