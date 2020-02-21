/*
 * File:   util.c
 * Author: Sousa
 *
 * Created on February 20, 2020, 5:30 PM
 */


#include <xc.h>

void util_pause(uint16_t delay){
	do{
		delay--;
	}
	while(delay > 0);
}

