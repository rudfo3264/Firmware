/*
 * fnd1.c
 *
 * Created: 2022-06-17 오후 4:21:33
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
		PORTA = 0x3f;	//0b 0011 1111
	}
	
	return 0;
}