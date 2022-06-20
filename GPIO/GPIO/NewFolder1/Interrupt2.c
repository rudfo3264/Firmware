/*
 * Interrupt2.c
 *
 * Created: 2022-06-20 오전 10:40:17
 *  Author: PKNU
 */ 

#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned char exchange = 0;
//INT4
SIGNAL(INT4_vect)
{
	exchange = ~exchange;
}

int main()
{
	DDRE = 0x00;
	DDRA = 0xff;
	EIMSK = 1<<INT4;
	EICRB = 1<<ISC41;
	sei();
	
	while(1)
	{
		if (exchange) PORTA = 0xff;
		else PORTA = 0x00;
	}
	
	return 0;
}