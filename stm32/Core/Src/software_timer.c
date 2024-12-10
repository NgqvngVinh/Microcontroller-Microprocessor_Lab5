/*
 * software_timer.c
 *
 *  Created on: Nov 20, 2024
 *      Author: vinhd
 */


#include "software_timer.h"

#define TIME_CYCLE 10

int timer_flag = 0;
int timer_counter = 0;

void setTimer(int duration){
	timer_counter = duration / TIME_CYCLE;
	timer_flag = 0;
}
void TimerRun(){
	if(timer_counter > 0){
		timer_counter--;
	}
	if(timer_counter == 0)
		timer_flag = 1;
}
