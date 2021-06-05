/*
 * delay.c
 *
 *  Created on: 2 Jun 2021
 *      Author: Ahmed Hamdy
 */

#include "tm4c123gh6pm.h"
void systick_init(void){
	NVIC_ST_CTRL_R=0;
	NVIC_ST_RELOAD_R=0x00FFFFFF;
    NVIC_ST_CURRENT_R=0;
    NVIC_ST_CTRL_R=0x00000005;
   
}

Void systick_delay(int time){
	NVIC_ST_RELOAD_R=time-1;s
    NVIC_ST_CURRENT_R=0;
while((NVIC_ST_CTRL_R & 0x0001000)==0);
}
