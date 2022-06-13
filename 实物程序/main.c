#include <reg51.H>


//sbit P10 =P1^0;

//#include <ds1602.c>
#define uchar unsigned char 
#define uint  unsigned int
uchar cp,cp1;
uint ad0,vale = 0,temp,temp_x;
float I_vale,I_vale2[10],Izz = 0;

  #include <uart.c>
//#include <display.c>
#include <18b20.c>
#include <PCF8591.c>

#include <stdio.h>				//启用printf，将printf重映射到串口
//#include <adc.c>
//#include "key.c"

bit bit1=0,flag;
#include <stdio.h>				//启用printf，将printf重映射到串口

void Timer_isr(void)interrupt 1
{
	
	
		TH0 =0xf7;
	TL0 =0x5c;
	cp++;

	
	if(cp >= 200)
	{
		
		cp = 0;
		cp1++;
		
		  	 if(cp1 == 8)
		{
		 			
		temp = get_temp();
		
		temp_x = c*6.25;
//			I_vale2[vale]	 = 	temp +	temp_x;
//			vale++;
//			if(vale >= 10)	 vale = 0;
		}

	
		if(cp1 >= 10)
		{
//		ad0 = read_pcf8591(0x40);
//		I_vale  = 	(float)	 ad0 *5/255;

			
			cp1 = 0;
			
		}
	}
	
}
void Timer_Init()
{
		TMOD = 0x01;
	TH0 =0xf7;
	TL0 =0x5c;
//	TH1 =65525/256;
//	TL1 =65525%256;
//TR1 = 1;
	TR0 = 1;
//	ET1 = 1;
	ET0 = 1;

	EA =1;
}
  void delayus(uint x)  //延时函数
{
	while(x--);
}
void main()
{
	Timer_Init();
//	 init_1602();
//	LCD_clr1602();
//	delayus(20000);
	  uart_init();
	 init_24c04();
	DS18B20_init();
		  TI = 1;
//	  temp = get_temp();
//	  temp = get_temp();
	while(1)
	{
		 
	
	   

	 TI = 1;
		 printf("\r\ntemp:%d.%d",temp,temp_x);
		   TI = 0;
//		   	 TI = 1;
//	    printf("\r\nI:%f",I_vale);
//		  TI = 0;
	
		delayus(2000);
	  
	 
	
	}
}
