#include <REGX52.H>

sbit EN1A=P1^6;
sbit EN1B=P1^5;
sbit PWM=P3^7;

unsigned char PWMR=0,PWML=0,angle=0;
/**
   *@brief 定时器0初始化，1毫秒@11.0592MHz
   *@param 无
   *@retval 无
   */
void Timer0_Init()
{
	TMOD|=0x01;
	TF0=0;
	TR0=1;
	TH0=0xFE;
	TL0=0x33;
	ET0=1;
	EA=1;
	PT0=0;
}


void Timer0_Routine() interrupt 1
{
	static unsigned int t=0;
	TH0=0xFE;
	TL0=0x33;
	t++;
	if (t<PWML){EN1B=1;}
	else{EN1B=0;}
	
	if (t<PWMR){EN1A=1;}
	else{EN1A=0;}
	
	if (t<angle){PWM=1;}
	else{PWM=0;}
	
	if(t>40){t=0;}
}