/*
 * Timer.c
 *
 * Created: 9/5/2022 8:31:21 PM
 *  Author: m
 */ 

#include "Timer.h"
#include "../Interrupts.h"

#include <stdio.h>
uint8_t *time_count;
void static (*fcallback) (void);
void addfcallback (void (*callback) (void)){
	fcallback=callback;
}

EN_Handler_t TIMER_init(ST_TIMER_CONFIG_t * configure){
	SREG |= (1<<7); // Global intrrupt enbaled
	if (configure->timerMode != 0) return nok; // Normal mode check!
	TCCR0 = configure->timerMode; // normal mode set
	return ok;
}
EN_Handler_t TIMER_set(ST_TIMER_CONFIG_t * configure){
	TCNT0 = configure->timerStartVal;
	if (TCNT0 != configure->timerStartVal) return nok;
	return ok;
}
EN_Handler_t TIMER_start(ST_TIMER_CONFIG_t * configure){
	TCCR0 = 0;
	TCCR0 = configure->timerClock; // prescaler set
	if(TCCR0 != configure->timerClock) return nok;
	TIMSK = 0x01; // interupt enable for timer0;
	time_count = &(configure->timeCount);
	return ok;
}
ISR(TIMER0_OVF_vect){
	if ( (*time_count) != 0) 
	(*time_count) --;
	else {
	TCCR0 = 0x00;
	TIMSK = 0x00; //disable interrupt
	fcallback();
	}
}