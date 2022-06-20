/*
 * fnd2.c
 *
 * Created: 2022-06-17 오후 4:27:18
 *  Author: PKNU
 */ 

#include <avr/io.h>
#define F_CPU 7432800UL
#include <util/delay.h>

int main()
{
	DDRA = 0xFF;
	
	while (1)
	{
		PORTA = 0x3f;	//0b 0011 1111 0
		_delay_ms(1000);
		PORTA = 0x06;	//1
		_delay_ms(1000);
		PORTA = 0x5b;	//2
		_delay_ms(1000);
		PORTA = 0x4f;	//3
		_delay_ms(1000);
		PORTA = 0x66;	//4
		_delay_ms(1000);
		PORTA = 0x6d;	//5
		_delay_ms(1000);
		PORTA = 0x7d;	//6
		_delay_ms(1000);
		PORTA = 0x27;	//7
		_delay_ms(1000);
		PORTA = 0x7f;	//8
		_delay_ms(1000);
		PORTA = 0x6f;	//9
		_delay_ms(1000);
		
	}
	
	return 0;
}