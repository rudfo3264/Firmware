/*
 * led2.c
 *
 * Created: 2022-06-17 오후 1:54:32
 *  Author: PKNU
 */ 

#define F_CPU	7432800
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0xFF;
	
	while (1)
	{
		//PORTA = 0x01;
		//_delay_ms(1000);
		//PORTA = 0x02;
		//_delay_ms(1000);
		//PORTA = 0x04;
		//_delay_ms(1000);
		//PORTA = 0x08;
		//_delay_ms(1000);
		
		
		int i;
		//for (i = 0; i < 8; i++)
		//{
			//int num = 0x01;
			//PORTA = num << i;
			//_delay_ms(1000)
		//}
		//
		//int i;
		//for (i = 0; i < 8; i++)
		//{
			//int num = 0x01;
			//PORTA = ~(num << i);
			//_delay_ms(1000);
		//}
		
		for (i=0; i<8; i++)
		{
			PORTA = 0xff;
			int num = 0xff;
			PORTA = num << i;
			_delay_ms(1000);
		}
	}
	
	return 0;
}