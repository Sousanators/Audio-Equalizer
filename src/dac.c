/*
 * File:   interrupts.c
 * Author: Sousa
 *
 * Created on February 20, 2020, 8:47 PM
 */

#include <xc.h>

void dac_init(void){
	ACLKCONbits.SELACLK = 0; //Sets Aux Clock source to PLL fo (before N2 divison)
	ACLKCONbits.APSTSCLR = 0b111; //Divide clock by 1
	
	IPC19bits.DAC1LIP = 0b110; //interrupt level 6
	IPC19bits.DAC1RIP = 0b101; //interrupt level 5. These settings are arbitrary, as long as they have different levels.
	
	DAC1STATbits.ROEN = 1; /* Right Channel DAC Output Enabled */
	DAC1STATbits.LOEN = 1; /* Left Channel DAC Output Enabled */
	DAC1STATbits.RITYPE = 0; /* Right Channel Interrupt if FIFO is not Full */
	DAC1STATbits.LITYPE = 0; /* Left Channel Interrupt if FIFO is not Full */
	DAC1CONbits.AMPON = 0; /* Amplifier Disabled During Sleep and Idle Modes */
	DAC1CONbits.DACFDIV = 13; /* Divide Clock by 13 */
	DAC1CONbits.FORM = 0; /* Data Format is Unsigned */
	DAC1DFLT = 0x8000; /* Default value set to Midpoint when FORM = 0 */
	IFS4bits.DAC1RIF = 0; /* Clear Right Channel Interrupt Flag */
	IFS4bits.DAC1LIF = 0; /* Clear Left Channel Interrupt Flag */
	IEC4bits.DAC1RIE = 1; /* Right Channel Interrupt Enabled */
	IEC4bits.DAC1LIE = 1; /* Left Channel Interrupt Enabled */
	DAC1CONbits.DACEN = 1; /* DAC1 Module Enabled */
}