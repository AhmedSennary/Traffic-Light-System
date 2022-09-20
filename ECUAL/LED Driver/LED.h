/*
 * LED.h
 *
 * Created: 9/4/2022 11:42:11 PM
 *  Author: m
 */ 

#ifndef LED_H
#define LED_H
#define OUT 1
#define IN 0
#define HIGH 1
#define LOW 0
#include "../../MCAL/Timers Driver/Timer.h"
#include "../../MCAL/DIO Driver/DIO.h"
typedef struct ST_LED_CONFIG_t{
	uint8_t pinNumber;
	uint8_t portNumber;
	uint8_t direction;
}ST_LED_CONFIG_t;

EN_Handler_t LED_init(ST_LED_CONFIG_t * configure);
EN_Handler_t LED_on(ST_LED_CONFIG_t * configure);
EN_Handler_t LED_off(ST_LED_CONFIG_t * configure);
EN_Handler_t LED_toggle(ST_LED_CONFIG_t * configure);
#endif