/*
 * Interrupt6.c
 *
 * Created: 2022-06-20 오후 2:31:49
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char Time_STOP = 0;
volatile unsigned char cnt = 0;

int main()
{
	unsigned char FND_DATA_TBL []={0x3F,0X06,0X5B,0X4F,0X66,0X6D,
		0X7C,0X07,0X7F,0X67,0X77,0X7C,
	0X39,0X5E,0X79,0X71,0X08,0X80};
	
	DDRA = 0xff;
	DDRE = 0x00;
	
	EICRB = 0x32;	// 0b 0011 0010
	EIMSK = 0x50;	// 0b 0101 0000
	EIFR = 0x50;
	sei();
	
	while(1)
	{
		PORTA = FND_DATA_TBL[cnt];
		if (Time_STOP ==0)
		{
			cnt++;
			if(cnt>17) cnt = 0;
		}
		_delay_ms(200);
	}
}
SIGNAL(INT4_vect)
{
	cli();
	
	Time_STOP = 1;
	cnt =0;
	sei();
}
SIGNAL(INT6_vect)
{
	cli();
	
	Time_STOP =0;
	sei();
}
