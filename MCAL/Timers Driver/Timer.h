/*
 * Timer.h
 *
 * Created: 9/5/2022 8:31:32 PM
 *  Author: m
 */ 

#ifndef TIMER_H
#define TIMER_H
#include "../../Utilites/Types.h"
#include "../../Utilites/Registers.h"
#define NormalMode 0x00;
#define Prescaler1 0x01;
#define Prescaler2 0x02;
#define Prescaler3 0x03;
#define Prescaler4 0x04;
#define Prescaler5 0x05;
typedef struct ST_TIMER_CONFIG_t{
	uint8_t timerMode;
	uint8_t timerStartVal;
	uint8_t timerClock;
	uint8_t timeCount;
}ST_TIMER_CONFIG_t;

EN_Handler_t TIMER_init(ST_TIMER_CONFIG_t * configure);
EN_Handler_t TIMER_start(ST_TIMER_CONFIG_t * configure);
EN_Handler_t TIMER_set(ST_TIMER_CONFIG_t * configure);
void addfcallback (void (*callback) (void));
#endif