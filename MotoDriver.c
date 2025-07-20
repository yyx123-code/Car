#include <REGX52.H>

sbit IN11=P1^4;
sbit IN12=P1^3;

sbit IN13=P1^2;
sbit IN14=P1^1;

void RightMotoForward(void)
{IN11=0;IN12=1;}

void RightMotoBackward(void)
{IN11=1;IN12=0;}

void RightMotoStop(void)
{IN11=0;IN12=0;}//右轮运动状态定义

void LeftMotoForward(void)
{IN13=0;IN14=1;}

void LeftMotoBackward(void)
{IN13=1;IN14=0;}

void LeftMotoStop(void)
{IN13=0;IN14=0;}//左轮运动状态定义