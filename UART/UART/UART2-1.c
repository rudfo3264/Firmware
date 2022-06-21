/*
 * UART4.c
 *
 * Created: 2022-06-21 오후 12:16:44
 *  Author: PKNU
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char TX_flag = 0;
volatile char TX_data = 0;

unsigned char FND_DATA_TBL[]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,
0X07,0X7F,0X6F};

void putch(unsigned char data)
{
	while ((UCSR0A & 0x20) ==0);
	UDR0 = data;
	UCSR0A |= 0x20;
}
unsigned char getch(void)
{
	unsigned char data;
	while((UCSR0A & 0x80) == 0);
	data = UDR0;
	UCSR0A |=0x80;
	return data;
}
int main()
{
	unsigned char RX_data = 0;
	DDRE = 0x0e;
	DDRA = 0xff;
	UCSR0A = 0x00;
	UCSR0B = 0x18;
	UCSR0C = 0x06;
	UBRR0H = 0x00;
	UBRR0L = 3;
	while(1)
	{
		RX_data = getch();
		if ((RX_data >= 0x30) && (RX_data <= 0x39))
		{
			PORTA = FND_DATA_TBL[RX_data - 0x30];
		}
	}
}