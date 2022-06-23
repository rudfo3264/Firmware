/*
 * PWM_PIEZO_KEYPAD.c
 *
 * Created: 2022-06-23 오전 11:04:04
 *  Author: PKNU
 */ 

#define F_CPU 7372800UL
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

unsigned int DoReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};
	
void putch(unsigned char data)
{
	while((UCSR0A & 0x20) == 0);
	UDR0 = data;
	UCSR0A |=0x20;	
}
unsigned char getch()
{
	unsigned char data;
	while((UCSR0A & 0x80) == 0);
	data = UDR0;
	UCSR0A |= 0x80;
	return data;	
}

int main()
{
	   int input = 0;
	   
	   DDRB = 0x80;
	   UCSR0A = 0x00;
	   UCSR0B = 0x18;
	   UCSR0C = 0x06;
	   UBRR0H = 0x00;
	   UBRR0L = 0x03;
	   
	   TCCR1A = 0x00;
	   TCCR1B |= 0x19;
	   TCCR1C = 0x00;
	   TCNT1 = 0x0000;
	  
	   while(1)
	   {
		   input = getch()-'0';
		   if(input){
			   TCCR1A |= 0x0A;
			   ICR1 = 7372800/DoReMi[input];
			   OCR1C = ICR1/2;
			   _delay_ms(300);
			   TCCR1A = 0x00;
			   input = 0;
		   }
	   }

	
		//unsigned char text[] = "Click the KeyPad!! \r\n";
		//unsigned char RX_data = 0;
		//unsigned char i = 0;
		//
		//
		//DDRE = 0xfe;
		//UCSR0A = 0x00;
		//UCSR0B = 0x18;
		//UCSR0C = 0x06;
		//
		//UBRR0H = 0x00;
		//UBRR0L = 3;
		//
		//while (1)
		//{
			//
			//if (RX_data)
			//{
				//
			//}
		//}
}