/*
 * Timer_Counter1.c
 *
 * Created: 2022-06-21 오후 3:32:59
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0x00;
unsigned char timer0Cnt = 0;	// 인터럽트 반복횟수를 넣을 변수
SIGNAL(TIMER0_OVF_vect);

int main()
{
	DDRC = 0x0f;
	TCCR0 = 0x07;
	TCNT0 = 183;
	TIMSK = 0x01;
	TIFR |= 1 << TOV0;
	sei();
	while (1)
	{
		PORTC = LED_Data;
	}
}
SIGNAL(TIMER0_OVF_vect)
{
	cli();
	TCNT0 = 183;
	timer0Cnt++;
	if (timer0Cnt ==100)
	{
		LED_Data++;
		if (LED_Data>0x0f) LED_Data = 0;
		timer0Cnt = 0;
	}
	sei();
}