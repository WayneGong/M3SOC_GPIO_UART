#include "system.h"

unsigned char i=0;
unsigned char  en=0; 
	
void Btn_ISR()
{
	  i=0;
}

void Timer_ISR()
{
	 en=1;
}



void	delay(unsigned int i)
{
	while(i--);

}

void send_str(char string[])
{

	AHB_UART	=	string[0];
	AHB_UART	=	string[1];
	AHB_UART	=	string[2];
	AHB_UART	=	string[3];
	AHB_UART	=	string[4];
	AHB_UART	=	string[5];
	AHB_UART	=	string[6];
	AHB_UART	=	string[7];
	AHB_UART	=	string[8];
	AHB_UART	=	string[9];	
	AHB_UART	=	string[10];
	AHB_UART	=	string[11];
	AHB_UART	=	string[12];
	AHB_UART	=	string[13];
	AHB_UART	=	string[14];
	AHB_UART	=	string[15];
	
}

//////////////////////////////////////////////////////////////////
// Main Function
//////////////////////////////////////////////////////////////////

int main(void) 
 {
	unsigned int	key_value	;
	unsigned int	delay_time	=	2500000; 
	unsigned int	led_value		=	0x05; 
	AHB_GPIO_LED	=	0xf;
	delay(delay_time*2);	 
	AHB_GPIO_LED	=	0x0;
	delay(delay_time*2);	
	AHB_GPIO_LED	=	0xf;
	delay(delay_time*2);	 
	AHB_GPIO_LED	=	0x0;
	delay(delay_time*2);
	 
	while(1)
	{
		key_value			=		AHB_GPIO_KEY;
																					
	if(	key_value ==	0x0d)		//the key value is 1101,	The key2 is pressed 
	{
		AHB_GPIO_LED	=	0x0e;
		delay(delay_time);		
		AHB_GPIO_LED	=	0x0d;;
		delay(delay_time);
		AHB_GPIO_LED	=	0x0b;
		delay(delay_time);		
		AHB_GPIO_LED	=	0x07;;
		delay(delay_time);	
	}	
	else if(	key_value ==	0x0b)		//the key value is 1011,	The key3 is pressed 
	{				
		AHB_GPIO_LED	=	0x07;;
		delay(delay_time);
		AHB_GPIO_LED	=	0x0b;
		delay(delay_time);
		AHB_GPIO_LED	=	0x0d;;
		delay(delay_time);
		AHB_GPIO_LED	=	0x0e;
		delay(delay_time);
	}	
	else if(	key_value ==	0x07)		//the key value is 0111,	The key4 is pressed 
	{
		AHB_GPIO_LED	=	0x5;
		delay(delay_time);	 
		AHB_GPIO_LED	=	0xa;
		delay(delay_time);		
	}
	
	else
	{
		AHB_GPIO_LED	=	0xf;
		delay(delay_time);	 
		AHB_GPIO_LED	=	0x0;
		delay(delay_time);		
	
	}

//		AHB_GPIO_LED 	= 	AHB_GPIO_KEY;		
//		send_str("hello,world!   \n");		
	}		
	return 0;
}
