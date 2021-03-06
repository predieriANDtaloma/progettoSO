#include "adc.h"
#include "delay.h"
#include "uart.h"
#include <stdio.h>
#include <string.h>

int sensorPin = 0;

struct UART* uart;

void printString(char* s){
	int l=strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
}

int main(void) {
	adc_init();
	uart=UART_init("uart_0",115200);
	char msg[8];

	while(1) {
		int sensorValue = adc_read(sensorPin);
		sprintf(msg, "sensorValue = %d\n", sensorValue);
		printString(msg);
		delayMs(300);
	}
}
