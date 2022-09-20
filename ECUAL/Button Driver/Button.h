/*
 * Button.h
 *
 * Created: 9/4/2022 11:41:57 PM
 *  Author: m
 */ 

#ifndef BUTTON_H
#define BUTTON_H
#include "../../MCAL/Timers Driver/Timer.h"
#include "../../MCAL/DIO Driver/DIO.h"
typedef struct ST_BUTTON_CONFIG_t{
	uint8_t pinNumber;
	uint8_t portNumber;
	uint8_t direction;
}ST_BUTTON_CONFIG_t;

EN_Handler_t BUTTON_init(ST_BUTTON_CONFIG_t * configure);
EN_Handler_t BUTTON_read(ST_BUTTON_CONFIG_t * configure , uint8_t *value);
#endif