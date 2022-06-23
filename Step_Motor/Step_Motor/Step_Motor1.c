/*
 * Step_Motor1.c
 *
 * Created: 2022-06-23 오후 3:07:21
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRB = 0x20;	//0010 0000
	DDRD = 0xf0;	//1111 0000
	PORTB &= ~0x20;
	
	while (1)
	{
		PORTD = 0x10;
		_delay_ms(10);
		PORTD = 0x20;
		_delay_ms(10);
		PORTD = 0x40;
		_delay_ms(10);
		PORTD = 0x80;
		_delay_ms(10);
	}
}