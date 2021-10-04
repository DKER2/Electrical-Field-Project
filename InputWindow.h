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
	SDL_Surface* surface;
	SDL_Texture* texture;
	
	static void updatePosition(int x, int y);
	static void updateTexture(std::string stringInput);
	void clean();
	static SDL_Rect* inputSrcrect;
	static SDL_Rect* inputDstrect;
	
private:
	static std::string stringInput;
	Uint32* buffer;
	
};

