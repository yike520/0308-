sbit DQ1 = P1^1;



/*初始化*/	   
void DS18B20_init_1(void)
{
	unsigned char x = 255;
	DQ1 = 1;
	DQ1 = 0;
	 Delay750us();		   //750us
	
	DQ1 = 1;
    while(DQ1 && x--); //等待应答
	 Delay750us();
}
/*写数据*/
void write_DS18B20_1(unsigned char dat)
{
	unsigned char i;
	for(i = 8; i > 0; i--)
	{
		DQ1 = 0;
		Delay8us();
		DQ1 = dat & 0x01;
		Delay75us();
		DQ1 = 1;
		dat >>= 1;	 
	}	 	
}

/*读数据*/
unsigned char read_DS18B20_1(void)
{
	unsigned char i,dat;
	for(i = 8; i > 0; i--)
	{
		DQ1 = 1;
		DQ1 = 0;
		dat >>= 1;
		DQ1 = 1;
		if(DQ1)dat |= 0x80;
		Delay75us(); 
	}
	return(dat);		
}

/*获取温度*/
	unsigned char a1, b1, c1;
unsigned char get_temp_1(void)
{
	unsigned char t;
	DS18B20_init_1();
	write_DS18B20_1(0xcc);	
	write_DS18B20_1(0x44);
	DS18B20_init_1();
	write_DS18B20_1(0xcc);	
	write_DS18B20_1(0xbe);
	a1 = read_DS18B20_1();
	b1 = read_DS18B20_1();
	c1 = a1 & 0x0f;
    a1 >>= 4;
	b1 <<= 4;
	t = a1 | b1;
	return(t);
}