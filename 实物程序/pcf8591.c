#include<intrins.h>
sbit scl = P2^0;
sbit sda = P2^1;

/*************起始信号**************/
//工作条件sda 产生下降沿 scl 为高电平；
void star_24c04 ()
{
	sda = 1;
	scl = 1;
	sda = 0;
	scl = 0;				 //时钟信号复位
}
/*************终止信号**************/
//终止条件sda数据信号产生下降沿 scl 时钟信号为高电平
void stop_24c04()
{
	sda = 0;
	scl = 1;
	sda = 1;
}
/**************应答信号**************/
void ack_24c04()
{
	uchar i= 255;
	scl = 1;
	while(sda && i--);
	scl = 0;
}
/**************I2C总线初始化*********/
void init_24c04(void)
{
	sda = 1;
	scl = 1;
}
/**************读取一个字节**************/
uchar read_onebyte_24c04(void)
{
	uchar i ,dat;
	sda = 1;//释放总线
	for(i = 0;i < 8;i++)
	{
		scl = 1;
		dat = dat<<1;
		if(sda)dat = dat|0x01;//先读取高位，放到dat 的低位；
		scl = 0;		
	}
	sda = 1;
	scl = 0;
	return (dat);
}
/*************写入一个字节**************/
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

//读地址、数据函数
//0x40表示0号通道；0x41表示1号通道；
uchar read_pcf8591(uchar sh)
{
	uchar temp;

	star_24c04();		 //发出开始信号
	write_onebyte_24c04(0x90);//PCF8591地址  相当于握手信号
	ack_24c04();			 //响应
	write_onebyte_24c04(sh);//0x40表示0号通道；//0x43 滑变  //0x40  光敏 //0x41 热敏
	ack_24c04();			 //响应					

	star_24c04();		 //再次发出开始信号					
	write_onebyte_24c04(0x91);//发出读取对应8951模块AD的信号					
	ack_24c04();			 //响应
	temp=read_onebyte_24c04();//读取数据
	stop_24c04();			 //停止
	return(temp);	 //返回数据
}
//void DA_PCF8591(uchar dat)			 ///	DA转换
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