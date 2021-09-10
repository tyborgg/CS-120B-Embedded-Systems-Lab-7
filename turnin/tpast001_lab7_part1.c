/*      Author: Tyler Pastor tpast001@ucr.edu
 *  Partner(s) Name: N/A
 *      Lab Section: 023
 *      Assignment: Lab #7  Exercise #1
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 *
 *      Demo Link: https://www.youtube.com/watch?v=32X9nXbctcY
 *
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
        DDRD = 0x03; PORTD = 0x00;
	unsigned short val;

        ADC_init();

        while (1) {
		val = ADC;
		PORTB = (char)val;
		PORTD = (char)(val >> 8);
        }

        return 0;
}

