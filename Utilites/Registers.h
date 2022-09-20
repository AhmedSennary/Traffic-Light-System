/*
 * Registers.h
 *
 * Created: 9/4/2022 11:45:26 PM
 *  Author: m
 */ 

#ifndef REG_H
#define REG_H
#include "Types.h"



//-------Interrupts-----------//
#define SREG  *((volatile uint8_t*)0x5F)
#define MCUCR *((volatile uint8_t*)0x55)
#define GICR *((volatile uint8_t*)0x5B)
#define TIMSK *((volatile uint8_t*)0x59)


//---------PortA---------------//
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)
//---------PortB------------//
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)
//---------PortC------------//
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)
//---------PortD------------//
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)


#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)
#endif
