#pragma once
#include<SDL.h>
#include <cmath>
#include<iostream>
#include<SDL_ttf.h>
class InputWindow

{
public: 
	InputWindow();
	SDL_Rect* returnPointerInputSrcect();
	SDL_Rect* returnPointerInputDstrect();
	SDL_Texture* plotInputWindow(SDL_Renderer* renderer);
	static void updatePosition(int x, int y);
	void clean();
	static SDL_Rect* inputSrcrect;
	static SDL_Rect* inputDstrect;
	
private:
	Uint32* buffer;
	
};

