/*
 * Timer_LED2.c
 *
 * Created: 2022-06-22 오전 11:39:10
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0x00;

int main()
{
	DDRC= 0x0f;
	
	TCCR3A = 0x00;
	TCCR3B = 0x05;
	
	TCNT3 = 51136;
	ETIMSK = 0x04;
	ETIFR |=1<<TOV3;
	
	sei();
	
	while (1)
	{
		PORTC = LED_Data;
	}
	return 0;
}
SIGNAL(TIMER3_OVF_vect)
{
	cli();
	
	TCNT3 = 51136;
	LED_Data++;
	
	if (LED_Data>0x0f)
	LED_Data = 0;
	sei();
}