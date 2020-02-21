/*
 * File:   timer.c
 * Author: Sousa
 *
 * Created on February 20, 2020, 8:08 PM
 */


#include <xc.h>

void timer_Tmr1Init(void){
	T1CONbits.TON = 0; // Disable Timer
	T1CONbits.TCS = 0; // Select internal instruction cycle clock
	T1CONbits.TGATE = 0; // Disable Gated Timer mode
	T1CONbits.TCKPS = 0b00; // Select 1:1 Prescaler
	TMR1 = 0x00; // Clear timer register
	PR1 = 832; // Load the period value
	IPC0bits.T1IP = 0b111; // Set Timer1 Interrupt Priority Level
	IFS0bits.T1IF = 0; // Clear Timer1 Interrupt Flag
	IEC0bits.T1IE = 1; // Enable Timer1 interrupt
	T1CONbits.TON = 1; // Start Timer
}
