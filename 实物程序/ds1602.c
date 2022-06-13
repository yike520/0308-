#define uchar unsigned char 
#define uint  unsigned int
 
sbit RS = P2^5;//数据/命令
sbit RW = P2^6;//读/写
sbit E  = P2^7;//使能
uchar i;
uchar str[] = {"Internet of Things00"};
uchar num[] = {"0123456789"};

void delayus(uint x)  //延时函数
{
	while(x--);
}

void write_com(uchar com)//写命令
{
	RW = 0;
	RS = 0;
	E = 1;
	P0 = com;
	delayus(100);
	E = 0;
}
void write_data(uchar da)//写入数据
{
	RW = 0;
	RS = 1;
	E = 1;
	P0 = da;
	delayus(100);
	E = 0;
}


void init_1602()	//LCD1602  初始化
{
	write_com(0x3c);//设定数据总线的个数4/8，显示一行/两行
	write_com(0x0c);//	  //光标不显示
	write_com(0x06);//	   //光标随字符右移
}
void LCD_clr1602()	//LCD1602  清屏
{
	write_com(0x01);	// 对字符串清0
	write_com(0x02);   //对光标清0
}

void goto_xy(uchar y,uchar x)    //定位显示位置
{
	if(y == 1)
		write_com(x + 0x80);		 //定位第一行
	else
		write_com(x + 0x80 + 0x40);	 //定位第二行
}

void display_num(unsigned char x)		 //显示数字
{
	write_data(num[x / 10%10]);	 
	write_data(num[x % 10]);
}

void display_num1(unsigned int x)		 //显示数字
{
	write_data(num[x / 1000 % 10]);
	write_data(num[x / 100 % 10]);
	write_data(num[x / 10 % 10]);		 
	write_data(num[x % 10]);
}

void display_string(uchar *p)	 //显示字符
{
	while(*p)
	{
		write_data(*p);
		p++;	
	}
}
void display_xnum2(float x)		 //显示数字
{
	uint y,x1;
	
	y = (int)x;
	write_data(num[y / 10]);	 
	write_data(num[y % 10]);
	x1 = (int)((x -(float)y)*1000);
	display_string(".");
	write_data(num[x1 / 100 % 10]);
	write_data(num[x1 / 10 % 10]);		 
//	write_data(num[x1 % 10]);
}
void display_xnum1(float x)		 //显示数字
{
	uint y,x1;
	
	y = (int)x;
		 
	write_data(num[y % 10]);
	x1 = (int)((x -(float)y)*1000);
	display_string(".");
	write_data(num[x1 / 100 % 10]);
	write_data(num[x1 / 10 % 10]);		 

}