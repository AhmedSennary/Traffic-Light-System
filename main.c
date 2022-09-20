/*
 * TrafficLightProject.c
 *
 * Created: 9/4/2022 11:39:01 PM
 * Author : m
 */ 


//#include <avr/io.h>
//#include "Utilites/Registers.h"



/************************************************************************/
/*                              Test Timer                              */
/************************************************************************/
//#include "MCAL/Interrupts.h"
//#include "MCAL/Timers Driver/Timer.h"
//ST_TIMER_CONFIG_t a;
//int main(void)
//{
		//a.timerMode =0x00; // normal mode
		//a.timerStartVal = 0x0C; // start 13
		//a.timerClock = 0x05; // prescaler 1024
		//a.timeCount = 2; // 0->18 (19 rept.) 0.24s -> 240000us 
		//TIMER_init(&a);
		//TIMER_set(&a);
		//TIMER_start(&a);
		//DDRA |= (1<<4);
    ///* Replace with your application code */
    //while (1) 
    //{
		//
		//PORTA |=(1<<4);
    //}
//}


/************************************************************************/
/*                              Test DIO                                */
/************************************************************************/
//#include "MCAL/Interrupts.h"
//#include "MCAL/DIO Driver/DIO.h"
//ST_DIO_CONFIG_t b;
//uint8_t *value;
//uint8_t v;
//
//int main(void)
//{
	//b.direction = IN;
	//b.portNumber = PORT_D;
	//b.pinNumber = 2;
	//DIO_init(&b);
	///* Replace with your application code */
	//while (1)
	//{
		//int x = TIMER_init(&a);
		//DIO_toggle(&b);
		//DIO_toggle(&b);
		//DIO_write(&b,0);
		//DIO_write(&b,HIGH);
		//DIO_read(&b, value);
		//v = *value;
		//DIO_write(&b,LOW);
		//DIO_read(&b, value);
		//v= *value;
	//}
//}

/************************************************************************/
/*                              Test LED                                */
/************************************************************************/
//#include "MCAL/Interrupts.h"
//#include "ECUAL/LED Driver/LED.h"
//ST_LED_CONFIG_t c1;
//ST_LED_CONFIG_t c2;
//ST_LED_CONFIG_t c3;
//ST_LED_CONFIG_t c4;
//ST_LED_CONFIG_t c5;
//ST_LED_CONFIG_t c6;
//
//
//int main(void)
//{
	//c1.direction = OUT;
	//c2.direction = OUT;
	//c3.direction = OUT;
	//c4.direction = OUT;
	//c5.direction = OUT;
	//c6.direction = OUT;
	//c1.portNumber= PORT_A;
	//c2.portNumber = PORT_B;
	//c3.portNumber= PORT_A;
	//c4.portNumber = PORT_B;
	//c5.portNumber= PORT_A;
	//c6.portNumber = PORT_B;
	//c1.pinNumber = 0;
	//c2.pinNumber = 0;
	//c3.pinNumber = 1;
	//c4.pinNumber = 1;
	//c5.pinNumber = 2;
	//c6.pinNumber = 2;
	//LED_init(&c1);
	//LED_off(&c1);
	//LED_on(&c1);
	//LED_toggle(&c1);
	//while(1){
		//
	//}
//}

/************************************************************************/
/*                              Test Button                             */
/************************************************************************/
//#include "MCAL/Interrupts.h"
//#include "ECUAL/Button Driver/Button.h"
//ST_BUTTON_CONFIG_t d1;
//uint8_t *value;
//int main(void)
//{
	//d1.direction = IN;
	//d1.portNumber= PORT_D;
	//d1.pinNumber = 2;
	//BUTTON_init(&d1);
	//BUTTON_read(&d1,value);
	//while(1){
		//printf("here");
	//}
//}

#include <stdio.h>
#include "Application/APP.h"


int main(void)
{
	app_init();
	while(1){	
		app();
	}
}