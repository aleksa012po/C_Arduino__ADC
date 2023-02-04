/*
 * C_Arduino_Asembler_ADC.c
 *
 * Created: 23.11.2022. 22:00:03
 * Author : Aleksandar Bogdanovic
 */ 

// Arduino Assembler, ADC. Install a voltage divider at the input. Change the value of the resistor and read the states of the AD converter.
// ADC = Vin*1024 / Vref
// ADMUX – ADC Multiplexer Selection Register
// ADCSRA - ADC Control and Status Register A
// DIDR0 – Digital Input Disable Register 0

#define F_CPU  16000000UL		// 16MHz

#include <avr/io.h>
#include <avr/interrupt.h>
#include "startConversion.h"
#include "init.h"

double dutyCycle = 0;

int main(void) {
	
		init();
	
	while(1) {
		// Loop
	}
}
	void setupADC() {
		
		ADMUX = (1 << REFS0)  | (1 << MUX0) | (1 << MUX2);		// ADMUX = 0b01000101
		ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS0) | (1<<ADPS1) | (1 << ADPS2);		// ADCSRA = 0b10001111
		DIDR0 = (1 << ADC5D);		// DIDR0 = 0b00100000
	}


	ISR(TIMER0_OVF_VECT) {
		OCR0A = dutyCycle;
	}

	ISR(ADC_vect) {
		dutyCycle = ADC;
		startConversion();
	}