/*
 * LCDTest2.c
 *
 * Created: 2022-06-20 오후 4:23:56
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include "Lcd.h"
#include <util/delay.h>
#include <stdio.h>

int main()
{
	int i,j;
	Byte str[15];
	DDRA = 0xff;
	DDRG = 0x0f;
	
	Lcd_Init();
	
	while(1)
	{
		for (i=2; i<10; i++)
		{
			for (j=1; j<10; j++)
			{
				Lcd_Pos(0,0);
				sprintf(str,"%d * %d = %d", i, j, i*j);
				Lcd_STR(str);
				_delay_ms(1000);
			}
		}
	}
	return 0;
}