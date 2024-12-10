/*
 * software_timer.h
 *
 *  Created on: Nov 20, 2024
 *      Author: vinhd
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"


extern int timer_flag;
extern int timer_counter;

void setTimer(int duration);
void TimerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
