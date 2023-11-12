/*
 * console.c
 *
 *  Created on: Nov 10, 2023
 *      Author: JOSE
 */

#include "console.h"


CONSOLE_DataStreamType ConsoleDataStream;

bool DebugOutputEnabled = true;


void ConsoleDebugDataFormat()
{
	sprintf(UartTxBuffer, "#DBG: %d \r\n", ConsoleDataStream.AdcValue);
}



void ConsoleDebugDataSend()
{
	if(DebugOutputEnabled)
	{
		ConsoleDebugDataFormat();
		HAL_UART_Transmit(&huart3, UartTxBuffer, strlen(UartTxBuffer), 100);
	}
}


