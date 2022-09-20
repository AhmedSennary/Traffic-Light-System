/*
 * DIO.h
 *
 * Created: 9/5/2022 8:31:09 PM
 *  Author: m
 */ 

#ifndef DIO_H
#define DIO_H
#include "../../Utilites/Types.h"
#include "../../Utilites/Registers.h"
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define LOW 0
#define HIGH 1

#define IN 0
#define OUT 1
typedef struct ST_DIO_CONFIG_t{
uint8_t pinNumber;
uint8_t portNumber;
uint8_t direction;
}ST_DIO_CONFIG_t;



EN_Handler_t DIO_init(ST_DIO_CONFIG_t * configure);
EN_Handler_t DIO_write(ST_DIO_CONFIG_t * configure,uint8_t value);
EN_Handler_t DIO_toggle(ST_DIO_CONFIG_t * configure);
EN_Handler_t DIO_read(ST_DIO_CONFIG_t * configure,uint8_t *value);
void addfcallback2 (void (*callback2) (void));
#endif