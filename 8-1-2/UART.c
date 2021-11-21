#include <REGX52.H>

void UART_Init() //4800bps@12.000MHz
{
		SCON = 0x50;
		PCON |= 0x80;		//使能波特率倍速位SMOD
	
		TMOD &= 0xF0; // 设置定时器模式
	  TMOD |= 0x20;  // 设定定时器1为8位自动重装方式
		TL1 = 0xF3;		//设定定时初值
		TH1 = 0xF3;		//设定定时器重装
		ET1 = 0;		//禁止定时器1中断
		TR1 = 1;		//启动定时器1
	
	EA = 1;
	ES = 1;
}

void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);
	TI = 0;
}

// 串口中断模板
/**
void UATT_Routine() interrupt 4
{
	if(RI ==1){
	   P2= ~SBUF;
		UART_SendByte(SBUF);
		RI = 0;
	}
	
}

**/