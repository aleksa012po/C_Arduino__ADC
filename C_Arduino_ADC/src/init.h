/*
 * init.h
 *
 * Created: 23.11.2022. 22:53:03
 *  Author: user
 */ 

#pragma once

void init() {
	DDRD = (1 << PORTD6);		// PD6 as an output
	PORTD = (1 << PORTD6);		// Pull Up Resistor
	
	TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);		// TCCR0A = 0b10000011
	TIMSK0 = (1 << TOIE0);		// TIMSK0 = 0b00000001
	
	setupADC();
	
	sei();
	
	TCCR0B = (1 << CS00) | (1 << CS02);		// 0b00000101
	
}