//#include "uart.h"
#define FOSC            11059200UL
#define BRT             (65536 - FOSC / 115200 / 4)

bit busy;

/*************************************************
Function: uart_init
Description: ���ڵĳ�ʼ��
Input: NULL
Output: NULL
Return: void
Others: 
*************************************************/
void uart_init()		//9600bps@12.000MHz
{
	SCON |= 0x50;	//���ô���ͨ�ſ��ƼĴ�����������ʽ1�������ڽ�������
	TMOD |= 0x20;	//�趨��ʱ��T1��������ʽ2���Զ�װ��ֵ
	TH1 = 0xfd;		//�趨������Ϊ9600bps��������ʽ2���Զ�װ��ֵ��9600
	TL1 = 0xfd;		

//TI = 1;
//	TI = 0;
	TR1 = 1;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	ES = 0;			//�����жϿ���λ��
	 


}




/*************************************************
Function: SendData
Description: ���ڷ��͵��ֽں���
Input: 
	dat����Ҫ���͵ĵ��ֽ�����
Output: NULL
Return: void
Others:
*************************************************/
void SendData(unsigned char dat)
{
		SBUF = dat;				//�����ݸ�ֵ���Ĵ���׼������
		while(!TI);				
		TI = 0;					//д���ݵ�UART���ݼĴ���
}

/*************************************************
Function: SendString
Description: ���ڷ����ַ�������
Input:
	dat����Ҫ���͵��ַ�������
Output: NULL
Return: void
Others:
*************************************************/
void SendString(unsigned char *s)
{
    while (*s)                  //����ַ���������־
    {
        SendData(*s++);         //���͵�ǰ�ַ�
    }
}
