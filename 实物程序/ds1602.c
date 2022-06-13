#define uchar unsigned char 
#define uint  unsigned int
 
sbit RS = P2^5;//����/����
sbit RW = P2^6;//��/д
sbit E  = P2^7;//ʹ��
uchar i;
uchar str[] = {"Internet of Things00"};
uchar num[] = {"0123456789"};

void delayus(uint x)  //��ʱ����
{
	while(x--);
}

void write_com(uchar com)//д����
{
	RW = 0;
	RS = 0;
	E = 1;
	P0 = com;
	delayus(100);
	E = 0;
}
void write_data(uchar da)//д������
{
	RW = 0;
	RS = 1;
	E = 1;
	P0 = da;
	delayus(100);
	E = 0;
}


void init_1602()	//LCD1602  ��ʼ��
{
	write_com(0x3c);//�趨�������ߵĸ���4/8����ʾһ��/����
	write_com(0x0c);//	  //��겻��ʾ
	write_com(0x06);//	   //������ַ�����
}
void LCD_clr1602()	//LCD1602  ����
{
	write_com(0x01);	// ���ַ�����0
	write_com(0x02);   //�Թ����0
}

void goto_xy(uchar y,uchar x)    //��λ��ʾλ��
{
	if(y == 1)
		write_com(x + 0x80);		 //��λ��һ��
	else
		write_com(x + 0x80 + 0x40);	 //��λ�ڶ���
}

void display_num(unsigned char x)		 //��ʾ����
{
	write_data(num[x / 10%10]);	 
	write_data(num[x % 10]);
}

void display_num1(unsigned int x)		 //��ʾ����
{
	write_data(num[x / 1000 % 10]);
	write_data(num[x / 100 % 10]);
	write_data(num[x / 10 % 10]);		 
	write_data(num[x % 10]);
}

void display_string(uchar *p)	 //��ʾ�ַ�
{
	while(*p)
	{
		write_data(*p);
		p++;	
	}
}
void display_xnum2(float x)		 //��ʾ����
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
void display_xnum1(float x)		 //��ʾ����
{
	uint y,x1;
	
	y = (int)x;
		 
	write_data(num[y % 10]);
	x1 = (int)((x -(float)y)*1000);
	display_string(".");
	write_data(num[x1 / 100 % 10]);
	write_data(num[x1 / 10 % 10]);		 

}