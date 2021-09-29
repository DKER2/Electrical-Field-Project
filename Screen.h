#pragma once
#include"FieldLine.h"
#include"InputWindow.h"
#include"Charge.h"
class Screen
{
private: 
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* mainScreen;
	SDL_Texture* inputTexture;
	int ScreenWidth;
	int ScreenHeight;
public:
	Screen(int ScreeWidth, int ScreenHeight);
	void update(std::vector<std::vector<int>> position, bool takeInputFromInputWindow);
	void clean();
};

