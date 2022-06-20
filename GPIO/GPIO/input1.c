/*
 * input1.c
 *
 * Created: 2022-06-17 오후 3:20:10
 *  Author: PKNU
 */ 
#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>

int main()	//OS 운영체제
{
	DDRD = 0x00;	//포트D 입력으로 설정
	DDRA = 0xFF;	//포트A 출력으로 설정
	
	
	
	while(1)
	{
		PORTA=PIND;
		
		//if(PIND == ) 
		//{
			//PORTA = ;	//포트D 입력값이 0x01이면 포트A의 0번 비트를 출력
			//_delay_ms(300);
			//PORTA = 0x00;
		//}
	}
	
	return 0;
}