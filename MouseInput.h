#pragma once
#include<SDL.h>
class MouseInput
{
public: 
	bool DoubleClickDetected(int* xposOfMouse,int* yposOfMouse,SDL_Event event);
};

