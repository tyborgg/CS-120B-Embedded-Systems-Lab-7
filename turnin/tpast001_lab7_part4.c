/*      Author: Tyler Pastor tpast001@ucr.edu
 *  Partner(s) Name: N/A
 *      Lab Section: 023
 *      Assignment: Lab #7  Exercise #4
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 *
 *      Demo Link: https://www.youtube.com/watch?v=t8DyLpWfGYY
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
		
		if(val <= (MAX / 8)){
			PORTB = 0x01;
		}
		else if(val <= (MAX / 7)){
			PORTB = 0x03;
		}
		else if(val <= (MAX / 6)){
			PORTB = 0x07;
		}
		else if(val <= (MAX / 5)){
                        PORTB = 0x0F;
                }
                else if(val <= (MAX / 4)){
                        PORTB = 0x1F;
                }
		else if(val <= (MAX / 3)){
                        PORTB = 0x3F;
                }
                else if(val <= (MAX / 2)){
                        PORTB = 0x7F;
                }
		else if(val <= (MAX)){
			PORTB = 0xFF;
		}
        }

        return 0;
}

