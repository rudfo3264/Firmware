/*
 * Interrupt5.c
 *
 * Created: 2022-06-20 오전 11:55:37
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char Time_STOP =0;

int main()
{
	unsigned char FND_DATA_TBL [] ={0x3F,0X06,0X5B,0X4F,0X66,0X6D,
								    0X7C,0X07,0X7F,0X67,0X77,0X7C,
								    0X39,0X5E,0X79,0X71,0X08,0X80};

	unsigned char cnt=0;
	DDRA = 0xff;	//출력
	DDRE = 0x00;	//입력
	
	EIMSK = 0x20;	//0b 0010 0000
	EICRB = 0x0C;	//0b 0000 1100
	//EIFR = 0x20;
	sei();
	
	while(1)
	{
		PORTA = FND_DATA_TBL[cnt];
		if (Time_STOP ==0)
		{
			cnt++;
			if (cnt>17) cnt =0;
		}
		_delay_ms(200);
	}
}
ISR(INT5_vect)
{
	cli();
	if (Time_STOP ==0)
	{
		Time_STOP =1;
	}
	else
	{
		Time_STOP=0;
	}
	sei();
}