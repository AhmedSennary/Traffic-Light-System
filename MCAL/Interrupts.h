/*
 * Interrupts.h
 *
 * Created: 9/5/2022 8:31:54 PM
 *  Author: m
 */ 

#ifndef INTERRUPT_H
#define INTERRUPT_H
#include "../Utilites/Types.h"
#include "../Utilites/Registers.h"

//#include <avr/iom32a.h>
//#include <avr/interrupt.h>


//-----------------------------------------------
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect __vector_11
//-----------------------------------------------

//-----------------------------------------------
/* External Interrupt Request 0 */
#define INT0_vect __vector_1

//-----------------------------------------------

//-----------------------------------------------
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)
#endif