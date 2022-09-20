/*
 * DIO.c
 *
 * Created: 9/5/2022 8:30:59 PM
 *  Author: m
 */ 

#include "DIO.h"
#include "../Interrupts.h"
#include <stdio.h>
void static (*fcallback2) (void);
void addfcallback2 (void (*callback2) (void)){
	fcallback2=callback2;
}
EN_Handler_t DIO_init(ST_DIO_CONFIG_t * configure){
	switch(configure->portNumber){
		case PORT_A:
			if (configure->direction == IN)
				DDRA &= ~(1<<(configure->pinNumber));
			else if (configure->direction == OUT)
				DDRA |= (1<<(configure->pinNumber));
			else return nok;
			return ok;
		case PORT_B:
			if (configure->direction == IN)
				DDRB &= ~(1<<(configure->pinNumber));
			else if (configure->direction == OUT)
				DDRB |= (1<<(configure->pinNumber));
			else return nok;
			return ok;
		case PORT_C:
			if (configure->direction == IN)
				DDRC &= ~(1<<(configure->pinNumber));
			else if (configure->direction == OUT)
				DDRC |= (1<<(configure->pinNumber));
			else return nok;
			return ok;
		case PORT_D:	
			if (configure->direction == IN){
				SREG |= (1<<7);  //global interrupt enable	
				MCUCR |= (1<<1); //falling edge sense
				GICR |= (1<<6);  //enable external interrupt
				DDRD &= ~(1<<(configure->pinNumber));
				}
			else if (configure->direction == OUT)
				DDRD |= (1<<(configure->pinNumber));
			else return nok;
			return ok;						
	}
	return nok;
}

EN_Handler_t DIO_write(ST_DIO_CONFIG_t * configure,uint8_t value){
		if (configure->direction == IN) return nok;
		switch(configure->portNumber){
			case PORT_A:
				if (value == LOW)
						PORTA &= ~(1<<(configure->pinNumber));
				else if (configure->direction == HIGH)
						PORTA |= (1<<(configure->pinNumber));
				else return nok;
				return ok;
			case PORT_B:
				if (value == LOW)
						PORTB &= ~(1<<(configure->pinNumber));
				else if (configure->direction == HIGH)
						PORTB |= (1<<(configure->pinNumber));
				else return nok;
				return ok;
			case PORT_C:
				if (value == LOW)
					PORTC &= ~(1<<(configure->pinNumber));
				else if (configure->direction == HIGH)
					PORTC |= (1<<(configure->pinNumber));
				else return nok;
				return ok;
			case PORT_D:
				if (value == LOW)
					PORTD &= ~(1<<(configure->pinNumber));
				else if (configure->direction == HIGH)
					PORTD |= (1<<(configure->pinNumber));
				else return nok;
				return ok;
		}
		return nok;
}


EN_Handler_t DIO_toggle(ST_DIO_CONFIG_t * configure){
			if (configure->direction == IN) return nok;
			switch(configure->portNumber){
				case PORT_A:
					PORTA ^= (1<<(configure->pinNumber));
					return ok;
				case PORT_B:
					PORTB ^= (1<<(configure->pinNumber));
					return ok;
				case PORT_C:
					PORTC ^= (1<<(configure->pinNumber));
					return ok;
				case PORT_D:
					PORTD ^= (1<<(configure->pinNumber));
					return ok;
			}
			return nok;

}
EN_Handler_t DIO_read(ST_DIO_CONFIG_t * configure,uint8_t *value){
				switch(configure->portNumber){
					case PORT_A:
						*value = ((PINA & (1<<configure->pinNumber))>>configure->pinNumber);
						return ok;
					case PORT_B:
						*value = ((PINB & (1<<configure->pinNumber))>>configure->pinNumber);
						return ok;
					case PORT_C:
						*value = ((PINC & (1<<configure->pinNumber))>>configure->pinNumber);
						return ok;
					case PORT_D:
						*value = ((PIND & (1<<configure->pinNumber))>>configure->pinNumber);
						return ok;
				}
				return nok;
}

ISR(INT0_vect){
	//printf("here");
	fcallback2();
}


