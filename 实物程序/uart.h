#ifndef __UART_H__
/*****************************************************************************
Copyright: 1988-1999, Cheese Tech. Co., Ltd.
File name: uart.c
Description: STC系列单片机的串口功能代码
Author: 宋志硕
Version: V0.0.1
Date: 2020.01.13
History: 修改历史记录列表， 每条修改记录应包括修改日期、修改者及修改内容简述。
		2020.01.13	对代码块的初次创建	修改者：宋志硕
*****************************************************************************/
#ifdef 	__UART_H__
#define __UART_H__

//#define STC89CXX

//#ifdef STC89CXX

//#ifdefine STC12CXX

//#else
//#include <reg51.h>

//#endif // STC89CXX

//#include <STC89C5xRC.H>
//#include <intrins.h>
//#include <stdio.h>				//启用printf，将printf重映射到串口



void uart_init();						//串口1的初始化
void SendData(unsigned char dat);		//发送单字节数据
void SendString(unsigned char *s);		//发送文本数据

#endif