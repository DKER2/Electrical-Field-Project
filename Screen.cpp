#include "Screen.h"
FieldLine* fieldLine = nullptr;
InputWindow* inputWindow = nullptr;
Screen::Screen(int ScreenWidth, int ScreenHeight) {
	this->ScreenWidth = ScreenWidth;
	this->ScreenHeight = ScreenHeight;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Electrical field project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	// need to change SDL_TEXTUREACCESS_STATIC to SDL_TEXTUREACCESS_STREAMING after complete Input Coding
	mainScreen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, ScreenWidth, ScreenHeight);
	inputWindow = new InputWindow;
	
	fieldLine = new FieldLine(ScreenWidth, ScreenHeight);
	
	
};
void Screen::update( std::vector<std::vector<int>> position,bool takeInputFromInputWindow) {
	if (takeInputFromInputWindow) {

		
		SDL_RenderCopy(renderer, inputWindow->plotInputWindow(renderer), NULL, InputWindow::inputDstrect);
		
	}
	else {
		SDL_RenderClear(renderer);
		Charge* arrayOfCharge[10];
		for (int i = 0; i < position.size(); i++) {
			arrayOfCharge[i] = new Charge(position[i][0], position[i][1], position[i][2]);
		}

		SDL_UpdateTexture(mainScreen, NULL, fieldLine->plotField(arrayOfCharge), ScreenWidth * sizeof(Uint32));

		SDL_RenderCopy(renderer, mainScreen, NULL, NULL);
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);
};
void Screen::clean() {
	SDL_DestroyTexture(mainScreen);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	fieldLine->clean();
	inputWindow->clean();
};