/*
 * APP.h
 *
 * Created: 9/4/2022 11:40:51 PM
 *  Author: m
 */ 

#ifndef APP_H
#define APP_H
#include "../ECUAL/Button Driver/Button.h"
#include "../ECUAL/LED Driver/LED.h"
#include "../MCAL/DIO Driver/DIO.h"
typedef struct ST_app_t{
	ST_BUTTON_CONFIG_t buttton;
	ST_LED_CONFIG_t LD;
}ST_app_t;
typedef struct ST_appt_t{
	ST_TIMER_CONFIG_t TM;
}ST_appt_t;
#define counttime 5;
#define interFlag (1<<6);
void mode_set();
void app_init();
void app();

#endif