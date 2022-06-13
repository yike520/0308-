//#include "uart.h"
#define FOSC            11059200UL
#define BRT             (65536 - FOSC / 115200 / 4)

bit busy;

/*************************************************
Function: uart_init
Description: 串口的初始化
Input: NULL
Output: NULL
Return: void
Others: 
*************************************************/
void uart_init()		//9600bps@12.000MHz
{
	SCON |= 0x50;	//设置串口通信控制寄存器，工作方式1，允许串口接收数据
	TMOD |= 0x20;	//设定定时器T1，工作方式2，自动装初值
	TH1 = 0xfd;		//设定波特率为9600bps，工作方式2，自动装初值，9600
	TL1 = 0xfd;		

//TI = 1;
//	TI = 0;
	TR1 = 1;		//串口1选择定时器1为波特率发生器
	ES = 0;			//串口中断控制位开
	 


}




/*************************************************
Function: SendData
Description: 串口发送单字节函数
Input: 
	dat：将要发送的单字节数据
Output: NULL
Return: void
Others:
*************************************************/
void SendData(unsigned char dat)
{
		SBUF = dat;				//把数据赋值给寄存器准备发送
		while(!TI);				
		TI = 0;					//写数据到UART数据寄存器
}

/*************************************************
Function: SendString
Description: 串口发送字符串函数
Input:
	dat：将要发送的字符串数据
Output: NULL
Return: void
Others:
*************************************************/
void SendString(unsigned char *s)
{
    while (*s)                  //检测字符串结束标志
    {
        SendData(*s++);         //发送当前字符
    }
}
