/*
 * PWM_Brightness.c
 *
 * Created: 2022-06-22 오후 4:31:29
 *  Author: PKNU
 */ 

#define  F_CPU 7372800UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	unsigned char Light = 0;
	DDRB = 0x10;
	
	TCCR0 = 0x77;
	TCNT0 = 0x00;
	
	while (1)
	{
		for (Light = 0; Light<255; Light++)
		{
			OCR0 = Light;
			_delay_ms(10);
		}
		for (Light = 255; 0<Light; Light--)
		{
			OCR0 = Light;
			_delay_ms(10);
		}
	}
}