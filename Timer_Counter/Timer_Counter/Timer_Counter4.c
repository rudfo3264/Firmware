﻿/*
 * Timer_Counter4.c
 *
 * Created: 2022-06-21 오후 5:02:07
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char FND_DATA_TBL[]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,
							  0X07,0X7F,0X6F,0X77,0X7C,0X39,0X5E,
							  0X79,0X71};
					
volatile unsigned char time_s=0;
volatile unsigned char Time_STOP = 0;

unsigned char timer0Cnt =0;

int main()
{
	DDRA = 0xff;
	DDRE = 0x00;
	TCCR2 = 0x05;
	OCR2= 144;
	TIMSK = 0x80;
	TIFR |=1 << OCF2;
	
	EICRB = 0x03;
	EIMSK = 0x10;
	EIFR = 0x10;
	
	sei();
	
	while (1)
	{
		PORTA = FND_DATA_TBL[time_s];
	}
	return 0;
}

SIGNAL(TIMER2_COMP_vect)
{
	cli();
	OCR2 += 144;
	timer0Cnt++;
	if (timer0Cnt == 50)
	{
		if (Time_STOP == 0)
		{
			if (time_s >=16)
			time_s = 0;
			else
			time_s++;
		}
		timer0Cnt = 0;
	}
	sei();
}
SIGNAL(INT4_vect)
{
	cli();
	if (Time_STOP == 0)
	Time_STOP =1;
	else
	Time_STOP = 0;
	
	sei();
}