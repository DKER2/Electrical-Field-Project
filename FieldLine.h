#pragma once
#include"Charge.h"
#include<math.h>
#include<SDL.h>
class FieldLine
{
private:
	Uint32* buffer;
	int ScreenWidth, ScreenHeight;
	
public: 
	Uint32* plotField(Charge* arrayOfCharge[10]);
	FieldLine(int ScreenWidth, int ScreenHeight );
	bool test(int xCurrent, int yCurrent, Charge* arrayOfCharge[10], int currentCharge);
	void clean();
};

