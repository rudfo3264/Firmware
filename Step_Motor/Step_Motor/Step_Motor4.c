/*
 * Step_Motor4.c
 *
 * Created: 2022-06-23 오후 4:09:21
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define DIR_L 0
#define DIR_R 1

unsigned char timer0Cnt = 0, mot_cnt = 0;
volatile unsigned char dir = DIR_R;

unsigned char step[] = {0x90,0x80,0xC0,0x40,0x60,0x20,0x30,0x10};
	
SIGNAL(TIMER0_OVF_vect);
SIGNAL(TIMER0_OVF_vect);

int main() 
{
	DDRB = 0x20;
	PORTB &= ~0x20;
	DDRD = 0xf0;
	TCCR0 =0x07;
	TCNT0 =112;
	TCCR1A = 0;
	TCCR1B = 0x04;
	TCNT1H = 0xfb;
	TCNT1L = 0X0d;
	TIMSK = 0x05;
	TIFR = 0x05;
	sei();
	
	while(1){}
}
SIGNAL(TIMER0_OVF_vect)
{
	cli();
	TCNT0 =112;
	timer0Cnt++;
	if (timer0Cnt == 200)
	{
		dir^=1;
		timer0Cnt = 0;
	}
	sei();
}
SIGNAL(TIMER1_OVF_vect)
{
	cli();
	TCNT1H = 0xfb;
	TCNT1L = 0x0d;
	
	PORTD = step[mot_cnt];
	if (dir ==DIR_R)
	{
		if (mot_cnt++==7) mot_cnt = 0;
	}
	else if(mot_cnt--==0) mot_cnt = 7;
	sei();
}