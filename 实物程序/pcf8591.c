#include<intrins.h>
sbit scl = P2^0;
sbit sda = P2^1;

/*************��ʼ�ź�**************/
//��������sda �����½��� scl Ϊ�ߵ�ƽ��
void star_24c04 ()
{
	sda = 1;
	scl = 1;
	sda = 0;
	scl = 0;				 //ʱ���źŸ�λ
}
/*************��ֹ�ź�**************/
//��ֹ����sda�����źŲ����½��� scl ʱ���ź�Ϊ�ߵ�ƽ
void stop_24c04()
{
	sda = 0;
	scl = 1;
	sda = 1;
}
/**************Ӧ���ź�**************/
void ack_24c04()
{
	uchar i= 255;
	scl = 1;
	while(sda && i--);
	scl = 0;
}
/**************I2C���߳�ʼ��*********/
void init_24c04(void)
{
	sda = 1;
	scl = 1;
}
/**************��ȡһ���ֽ�**************/
uchar read_onebyte_24c04(void)
{
	uchar i ,dat;
	sda = 1;//�ͷ�����
	for(i = 0;i < 8;i++)
	{
		scl = 1;
		dat = dat<<1;
		if(sda)dat = dat|0x01;//�ȶ�ȡ��λ���ŵ�dat �ĵ�λ��
		scl = 0;		
	}
	sda = 1;
	scl = 0;
	return (dat);
}
/*************д��һ���ֽ�**************/
void write_onebyte_24c04(uchar dat)
{
	uchar i;
	for(i = 0;i < 8;i++)
	{
		sda = (bit)(dat & 0x80);
		dat = dat << 1;
		scl = 1;
		scl = 0;
	}
	sda = 1;
	scl = 0;
}

//����ַ�����ݺ���
//0x40��ʾ0��ͨ����0x41��ʾ1��ͨ����
uchar read_pcf8591(uchar sh)
{
	uchar temp;

	star_24c04();		 //������ʼ�ź�
	write_onebyte_24c04(0x90);//PCF8591��ַ  �൱�������ź�
	ack_24c04();			 //��Ӧ
	write_onebyte_24c04(sh);//0x40��ʾ0��ͨ����//0x43 ����  //0x40  ���� //0x41 ����
	ack_24c04();			 //��Ӧ					

	star_24c04();		 //�ٴη�����ʼ�ź�					
	write_onebyte_24c04(0x91);//������ȡ��Ӧ8951ģ��AD���ź�					
	ack_24c04();			 //��Ӧ
	temp=read_onebyte_24c04();//��ȡ����
	stop_24c04();			 //ֹͣ
	return(temp);	 //��������
}
//void DA_PCF8591(uchar dat)			 ///	DAת��
//{
//	star_24c04();
//	write_onebyte_24c04(0x90);
//	ack_24c04();
//	write_onebyte_24c04(0x40);
//		ack_24c04();
//	write_onebyte_24c04(dat);
//		ack_24c04();
//	stop_24c04();
//}			