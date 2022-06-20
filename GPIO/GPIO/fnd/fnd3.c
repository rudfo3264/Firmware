/*
 * fnd3.c
 *
 * Created: 2022-06-17 오후 4:50:47
 *  Author: PKNU
 */ 
int main()
{
	DDRD = 0x00;
	DDRA = 0xFF;
	
	int output[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x7f};
	int input[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
	int i;
	while (1)
	{
		PORTA = PIND;
		
		//PORTA = 0x3f;	//0b 0011 1111 0
		//_delay_ms(1000);
		//PORTA = 0x06;	//2
		//_delay_ms(1000);
		//PORTA = 0x5b;	//3
		//_delay_ms(1000);
		//PORTA = 0x4f;	//4
		//_delay_ms(1000);
		//PORTA = 0x66;	//5
		//_delay_ms(1000);
		//PORTA = 0x6d;	//6
		//_delay_ms(1000);
		//PORTA = 0x7d;	//7
		//_delay_ms(1000);
		//PORTA = 0x7f;	//8
		//_delay_ms(1000);
		//PORTA = 0x6f;	//9
		//_delay_ms(1000);
	}
	
	return 0;
}