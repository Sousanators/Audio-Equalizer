/*
 * File:   interrupts.c
 * Author: Sousa
 *
 * Created on February 20, 2020, 8:47 PM
 */

#include <xc.h>

void __attribute__((interrupt(auto_psv))) _T1Interrupt(void){
	LATBbits.LATB6 ^= 1;
	IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
}

void __attribute__((interrupt, no_auto_psv))_DAC1RInterrupt(void){
	IFS4bits.DAC1RIF = 0; //Clear flag
	static uint16_t rampR = 0;
	DAC1RDAT = rampR;
	rampR += 1569;
	LATBbits.LATB6 ^= 1; 
}

void __attribute__((interrupt, no_auto_psv))_DAC1LInterrupt(void){
	IFS4bits.DAC1LIF = 0; //Clear flag
	static uint16_t rampL = 0;
	DAC1LDAT = rampL;
	rampL += 5;
	LATBbits.LATB7 ^= 1; 
}