/*
 * fsm_uart.c
 *
 *  Created on: Nov 20, 2024
 *      Author: vinhd
 */


#include "fsm_uart.h"
#include "main.h"
#include "software_timer.h"




uint8_t buffer[MAX_BUFFER_SIZE];

uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t temp = 0;
uint8_t command_flag, command_data;
uint8_t is_SendADC_flag, is_ReadADC_flag;

COMMAND_PARSER_STATE command_parser_state = INIT;
COMMUNICATION_STATE communication_state = READ_ADC;



void uart_fsm_init(void){
	buffer_flag = command_flag = command_data = 0;
	is_SendADC_flag = is_ReadADC_flag = 0;
//	ADC_VALUE = 0;
	command_parser_state = INIT;
	communication_state = READ_ADC;
}



void command_parser_fsm(void){
	switch(command_parser_state){
	case INIT:
		command_flag = command_data = 0;
		if(buffer[index_buffer] == '!'){
			command_parser_state = RECEIVED_EXCLAMATION_MARK;
			index_buffer++;
		}

		break;
	case RECEIVED_EXCLAMATION_MARK:
		if(buffer[index_buffer] == 'R'){
			command_parser_state = RECEIVED_R;
			index_buffer++;
		}
		else if(buffer[index_buffer] == 'O'){
			command_parser_state = RECEIVED_O;
			index_buffer++;
		}
		else command_parser_state = INIT;

		break;
	case RECEIVED_R:
		if(buffer[index_buffer] == 'S'){
			command_parser_state = RECEIVED_S;
			index_buffer++;
		}
		else command_parser_state = INIT;

		break;
	case RECEIVED_S:
		if(buffer[index_buffer] == 'T'){
			command_parser_state = RECEIVED_T;
			index_buffer++;
		}
		else command_parser_state = INIT;

		break;
	case RECEIVED_T:
		if(buffer[index_buffer] == '#'){
			command_flag = 1;
			HAL_GPIO_TogglePin(LY_GPIO_Port, LY_Pin);
			index_buffer++;
		}
		command_parser_state = INIT;

		break;
	case RECEIVED_O:
		if(buffer[index_buffer] == 'K'){
			command_parser_state = RECEIVED_K;
			index_buffer++;
		}
		else command_parser_state = INIT;

		break;
	case RECEIVED_K:
		if(buffer[index_buffer] == '#'){
			command_data = 1;
			HAL_GPIO_TogglePin(LY_GPIO_Port, LY_Pin);
			index_buffer++;
		}

		command_parser_state = INIT;

		break;
	default:
		break;
	}
}

void uart_communication_fsm(void){
    switch(communication_state){
    case READ_ADC:
        is_SendADC_flag = is_ReadADC_flag = 0;
        if(command_flag == 1) {
            is_ReadADC_flag = 1;
            communication_state = SEND_ADC;
            setTimer(3000);
        }
        break;
    case SEND_ADC:
        if(command_data == 1) {
            communication_state = READ_ADC;
            command_flag = command_data = 0;
        }
        break;
    default:
        break;
    }
}

