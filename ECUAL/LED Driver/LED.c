/*
 * LED.c
 *
 * Created: 9/4/2022 11:42:20 PM
 *  Author: m
 */ 
#include "LED.h"
ST_DIO_CONFIG_t DIOs;
EN_Handler_t LED_init(ST_LED_CONFIG_t * configure){
	if (configure->direction == IN) return nok;
	DIOs.direction = configure->direction;
	DIOs.pinNumber = configure->pinNumber;
	DIOs.portNumber = configure->portNumber;
	DIO_init(&DIOs);
	return ok;
}

EN_Handler_t LED_on(ST_LED_CONFIG_t * configure){
	if (configure->direction == IN) return nok;
	DIOs.direction = configure->direction;
	DIOs.pinNumber = configure->pinNumber;
	DIOs.portNumber = configure->portNumber;
	DIO_write(&DIOs,HIGH);
	return ok;
}

EN_Handler_t LED_off(ST_LED_CONFIG_t * configure){
	if (configure->direction == IN) return nok;
	DIOs.direction = configure->direction;
	DIOs.pinNumber = configure->pinNumber;
	DIOs.portNumber = configure->portNumber;
	DIO_write(&DIOs,LOW);
	return ok;
}

EN_Handler_t LED_toggle(ST_LED_CONFIG_t * configure){
	if (configure->direction == IN) return nok;
	DIOs.direction = configure->direction;
	DIOs.pinNumber = configure->pinNumber;
	DIOs.portNumber = configure->portNumber;
	DIO_toggle(&DIOs);
	return ok;
}