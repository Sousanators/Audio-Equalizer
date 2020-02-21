/*
 * File:   main.c
 * Author: Sousa
 *
 * Created on February 10, 2020, 1:47 PM
 */


#include <xc.h>
#include "configbits.h"
#include "typedefs.h"
#include "util.h"
#include "interrupts.h"
#include "timer.h"
#include "dac.h"

void init(void);

int main(void)
{
	util_pause(50000);
	init();
	//timer_Tmr1Init();
	dac_init();
	while(1){
		util_pause(5000);
	}
}

void init(void){
	CLKDIVbits.PLLPOST = 0b00;
	CLKDIVbits.PLLPRE = 4;
	PLLFBDbits.PLLDIV = 158;
	OSCCONbits.NOSC = 0b011;
	
	TRISB = 0x00;	//Set B port as outputs
	LATB = 0x00;	//Set outputs to 0
	RPOR3bits.RP6R = 0;		//Set RP6 (on same pin as RB6) as default port function
}