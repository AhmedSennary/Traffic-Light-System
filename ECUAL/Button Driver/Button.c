/*
 * Button.c
 *
 * Created: 9/4/2022 11:41:44 PM
 *  Author: m
 */ 

#include "Button.h"
ST_DIO_CONFIG_t DIOs2;
EN_Handler_t BUTTON_init(ST_BUTTON_CONFIG_t * configure){
		if (configure->direction == OUT) return nok;
		DIOs2.direction = configure->direction;
		DIOs2.pinNumber = configure->pinNumber;
		DIOs2.portNumber = configure->portNumber;
		DIO_init(&DIOs2);
		return ok;

}

EN_Handler_t BUTTON_read(ST_BUTTON_CONFIG_t * configure,uint8_t *value){
	DIOs2.direction = configure->direction;
	DIOs2.pinNumber = configure->pinNumber;
	DIOs2.portNumber = configure->portNumber;
	DIO_read(&DIOs2,value);
}