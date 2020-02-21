/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef INTERRUPTS_H
#define	INTERRUPTS_H

void __attribute__((interrupt(auto_psv))) _T1Interrupt(void);
void __attribute__((interrupt, no_auto_psv))_DAC1RInterrupt(void);
void __attribute__((interrupt, no_auto_psv))_DAC1LInterrupt(void);

#endif	/* INTERRUPTS_H */

