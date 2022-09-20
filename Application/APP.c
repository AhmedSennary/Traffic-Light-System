/*
 * APP.c
 *
 * Created: 9/4/2022 11:40:40 PM
 *  Author: m
 */ 
#include "APP.h"
ST_app_t CAR_LED_G;
ST_app_t CAR_LED_Y;
ST_app_t CAR_LED_R;
ST_app_t PED_LED_G;
ST_app_t PED_LED_Y;
ST_app_t PED_LED_R;
ST_app_t Push_b;
ST_appt_t timer;
uint8_t mode = 1;
uint8_t flag =0;
uint8_t PedMode = 0;
uint8_t Blink_count= 0;
uint8_t past_mode=0;
void app_init(){
	CAR_LED_R.LD.direction =OUT;
	CAR_LED_Y.LD.direction =OUT;
	CAR_LED_G.LD.direction =OUT;
	PED_LED_R.LD.direction =OUT;
	PED_LED_Y.LD.direction =OUT;
	PED_LED_G.LD.direction =OUT;

	CAR_LED_R.LD.portNumber = PORT_A;
	CAR_LED_Y.LD.portNumber = PORT_A;
	CAR_LED_G.LD.portNumber = PORT_A;
	PED_LED_R.LD.portNumber = PORT_B;
	PED_LED_Y.LD.portNumber = PORT_B;
	PED_LED_G.LD.portNumber = PORT_B;

	CAR_LED_R.LD.pinNumber = 0;
	CAR_LED_Y.LD.pinNumber = 1;
	CAR_LED_G.LD.pinNumber = 2;
	PED_LED_R.LD.pinNumber = 0;
	PED_LED_Y.LD.pinNumber = 1;
	PED_LED_G.LD.pinNumber = 2;

	LED_init(&CAR_LED_R.LD);
	LED_init(&CAR_LED_G.LD);
	LED_init(&CAR_LED_Y.LD);
	LED_init(&PED_LED_R.LD);
	LED_init(&PED_LED_G.LD);
	LED_init(&PED_LED_Y.LD);

	Push_b.buttton.direction =IN;
	Push_b.buttton.pinNumber = 2 ;
	Push_b.buttton.portNumber = PORT_D;
	BUTTON_init(&Push_b.buttton);

	timer.TM.timerMode = NormalMode ;
	timer.TM.timerClock = Prescaler5;
	timer.TM.timerStartVal = 20;
	TIMER_init(&timer.TM);
	
}
void mode_set(){
	if (PedMode == 1){
		flag= 0;
		if (Blink_count == 3){
			PedMode = 0;
		}	
	}
	if (PedMode == 0){
		GICR |= interFlag;
		if (mode == 3){
				mode = 2;
				past_mode = 3;
			}
		else if (mode == 1 ) {
				mode=2;
				past_mode =1;
			}
		else if (mode==2){
			if (past_mode == 1 ) mode =3;
			else if (past_mode == 3) mode =1;
		}
		flag = 0;
	}

}

void mode_set2(){
	if (PedMode == 0){
		GICR &= ~interFlag; // disable interrupt for the button so if pushed nothing would happen
		switch (mode){
			case 1:
				mode = 2;
				PedMode = 1;
				flag =  0;
				break;
			case 2:
				mode = 2;
				PedMode =1;
				flag = 0;
				break;
			case 3:
				mode = 3;
				flag=0;
				break;
		}
	}
}


void app(){
	if (flag==1) return;
	switch (mode){
		//for (int volatile i = 10 ;i !=0; i++);
		case 1:	
			if(flag == 0) {	
				LED_off(&CAR_LED_R.LD);
				LED_off(&CAR_LED_Y.LD);
				LED_on(&CAR_LED_G.LD);
				LED_on(&PED_LED_R.LD);
				LED_off(&PED_LED_Y.LD);
				LED_off(&PED_LED_G.LD);
				timer.TM.timeCount = counttime; // each count =  0.262143 
				TIMER_set(&timer.TM);
				TIMER_start(&timer.TM);
				flag = 1;
				addfcallback(mode_set);
				addfcallback2(mode_set2);
				}
			break;
		case 2:
			if(flag == 0 && PedMode == 0 ) {
				LED_off(&CAR_LED_R.LD);
				LED_on(&CAR_LED_Y.LD);
				LED_off(&CAR_LED_G.LD);
				LED_off(&PED_LED_R.LD);
				LED_on(&PED_LED_Y.LD);
				LED_off(&PED_LED_G.LD);
				timer.TM.timeCount = counttime; // each count =  0.262143 
				TIMER_set(&timer.TM);
				TIMER_start(&timer.TM);
				flag = 1;
				addfcallback(mode_set);
				addfcallback2(mode_set2);
			}
			else if (PedMode == 1 && flag == 0){
				Blink_count++;
				LED_off(&CAR_LED_R.LD);
				LED_toggle(&CAR_LED_Y.LD);
				LED_off(&CAR_LED_G.LD);
				LED_off(&PED_LED_R.LD);
				LED_toggle(&PED_LED_Y.LD);
				LED_off(&PED_LED_G.LD);
				timer.TM.timeCount = 1; // each count =  0.262143 
				TIMER_set(&timer.TM);
				TIMER_start(&timer.TM);
				flag =1;
				addfcallback(mode_set);
				past_mode =1;
			}
			break;
		case 3:
			if(flag == 0 ) {
				past_mode = 3;
				LED_on(&CAR_LED_R.LD);
				LED_off(&CAR_LED_Y.LD);
				LED_off(&CAR_LED_G.LD);
				LED_off(&PED_LED_R.LD);
				LED_off(&PED_LED_Y.LD);
				LED_on(&PED_LED_G.LD);
				timer.TM.timeCount = counttime; // each count =  0.262143 
				TIMER_set(&timer.TM);
				TIMER_start(&timer.TM);
				flag = 1;
				addfcallback(mode_set);
				addfcallback2(mode_set2);
				}
			break;
	}
}