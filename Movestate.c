#include <REGX52.H>
#include "MotoDriver.h"

void cargo(void)
{RightMotoForward();LeftMotoForward();}

void carback(void)
{RightMotoBackward();LeftMotoBackward();}

void carright(void)
{RightMotoStop();LeftMotoForward();}	

void carleft(void)
{RightMotoForward();LeftMotoStop();}

void carstop(void)
{RightMotoStop();LeftMotoStop();}