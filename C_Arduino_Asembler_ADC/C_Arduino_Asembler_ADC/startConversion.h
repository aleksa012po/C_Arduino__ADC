/*
 * startConversion.h
 *
 * Created: 23.11.2022. 22:51:12
 *  Author: user
 */ 

#pragma once

void startConversion() {
	
	ADCSRA |= (1 << ADSC);		// ADCSRA |= 0b01000000
}