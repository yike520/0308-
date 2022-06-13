#include<intrins.h>
sbit DQ = P1^0;

void Delay750us()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 84;
	do
	{
		while (--j);
	} while (--i);
}
void Delay75us()		//@11.0592MHz
{
	unsigned char i;

	i = 32;
	while (--i);
}
void Delay8us()		//@11.0592MHz
{
	unsigned char i;

	i = 1;
	while (--i);
}

/*��ʼ��*/	   
void DS18B20_init(void)
{
	unsigned char x = 255;
	DQ = 1;
	DQ = 0;
	 Delay750us();		   //750us
	
	DQ = 1;
    while(DQ && x--); //�ȴ�Ӧ��
	 Delay750us();
}
/*д����*/
void write_DS18B20(unsigned char dat)
{
	unsigned char i;
	for(i = 8; i > 0; i--)
	{
		DQ = 0;
		Delay8us();
		DQ = dat & 0x01;
		Delay75us();
		DQ = 1;
		dat >>= 1;	 
	}	 	
}

/*������*/
unsigned char read_DS18B20(void)
{
	unsigned char i,dat;
	for(i = 8; i > 0; i--)
	{
		DQ = 1;
		DQ = 0;
		dat >>= 1;
		DQ = 1;
		if(DQ)dat |= 0x80;
		Delay75us(); 
	}
	return(dat);		
}

/*��ȡ�¶�*/
	unsigned char a, b, c;
unsigned char get_temp(void)
{
	unsigned char t;
	DS18B20_init();
	write_DS18B20(0xcc);	
	write_DS18B20(0x44);
	DS18B20_init();
	write_DS18B20(0xcc);	
	write_DS18B20(0xbe);
	a = read_DS18B20();
	b = read_DS18B20();
	c = a & 0x0f;
    a >>= 4;
	b <<= 4;
	t = a | b;
	return(t);
}