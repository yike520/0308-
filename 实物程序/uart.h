#ifndef __UART_H__
/*****************************************************************************
Copyright: 1988-1999, Cheese Tech. Co., Ltd.
File name: uart.c
Description: STCϵ�е�Ƭ���Ĵ��ڹ��ܴ���
Author: ��־˶
Version: V0.0.1
Date: 2020.01.13
History: �޸���ʷ��¼�б� ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ�����
		2020.01.13	�Դ����ĳ��δ���	�޸��ߣ���־˶
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
//#include <stdio.h>				//����printf����printf��ӳ�䵽����



void uart_init();						//����1�ĳ�ʼ��
void SendData(unsigned char dat);		//���͵��ֽ�����
void SendString(unsigned char *s);		//�����ı�����

#endif