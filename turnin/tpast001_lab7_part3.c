/*      Author: Tyler Pastor tpast001@ucr.edu
 *  Partner(s) Name: N/A
 *      Lab Section: 023
 *      Assignment: Lab #7  Exercise #3
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 *
 *      Demo Link: https://www.youtube.com/watch?v=3B6CLKVTpY0
 *
 *
 * 	MAX Value = b1001100000 = #608
 * 	MIN Value = b0000001111 = #15
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
        ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
        DDRB = 0xFF; PORTB = 0x00;
	unsigned short val;
	int MAX = 608;

        ADC_init();

        while (1) {
		val = ADC;
		
		if(val >= (MAX / 2)){
			PORTB = 0x01;
		}
		else{
			PORTB = 0x00;
		}
        }

        return 0;
}

