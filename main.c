#include <REGX52.H>
#include "MotoDriver.h"
#include "Movestate.h"
#include "Timer0.h"

sbit MOS=P1^7;
unsigned char receiveData;

void UART_Init()		//9600bps@11.0592MHz
{

	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	SM0 = 0;
	SM1 = 1;
	REN = 1;
	ES  = 1;
	EA  = 1;
}

void main()
{
	UART_Init();
	Timer0_Init();
	while(1)
	{
		switch(receiveData)
		{
			case'G':
				PWML=10;PWMR=10;
				cargo();
				break;
			case'K':
				PWML=10;PWMR=10;
				carback();
				break;
			case'H':
				PWML=0;PWMR=10;
				carleft();
				break;
			case'J':
				PWML=10;PWMR=0;
				carright();
				break;
			case'I':
				PWML=0;PWMR=0;
				carstop();
				break;
			case'E':
				MOS=1;
				break;
			case'F':
				MOS=0;
				break;
			case'A':
//				angle=1;
//				MOS=1;
				PWML=30;PWMR=30;
				cargo();
				break;
			case'B':
				angle=2;
				MOS=1;
				break;
			case'C':
				angle=3;
				MOS=1;
				break;
			case'D':
				angle=4;
				MOS=1;
				break;
		}
	}
}

void UART_Routine()	interrupt 4
{
	if(RI==1)
	{
		P2=0xFF;
		RI=0;
		receiveData=SBUF;
	}
	SBUF=receiveData;
	while(!TI);
	TI=0;
}
