/*
 * fsm_uart.h
 *
 *  Created on: Nov 20, 2024
 *      Author: vinhd
 */

#ifndef INC_FSM_UART_H_
#define INC_FSM_UART_H_

#include "main.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 30

extern uint8_t index_buffer;
extern uint8_t buffer_flag; //flag báo new data
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t temp;

extern uint8_t is_ReadADC_flag;
extern uint8_t is_SendADC_flag;

extern char str[50];


extern uint8_t command_flag, command_data;

void uart_fsm_init(void);
void command_parser_fsm(void);
void uart_communication_fsm(void);

typedef enum  {
    INIT,
	RECEIVED_EXCLAMATION_MARK,
	RECEIVED_R,
	RECEIVED_S,
	RECEIVED_T,
	RECEIVED_O,
	RECEIVED_K,
} COMMAND_PARSER_STATE;

typedef enum   {
	READ_ADC,
	SEND_ADC
} COMMUNICATION_STATE;

extern  COMMAND_PARSER_STATE command_parser_state;
extern  COMMUNICATION_STATE  communication_state;



#endif /* INC_FSM_UART_H_ */
