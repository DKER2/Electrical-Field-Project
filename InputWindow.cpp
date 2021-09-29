#include "InputWindow.h"

SDL_Rect* InputWindow::inputDstrect = new SDL_Rect;
SDL_Rect* InputWindow::inputSrcrect = new SDL_Rect;
InputWindow::InputWindow(){
	TTF_Init();
	inputSrcrect->x = 0;
	inputSrcrect->y = 0;
	inputSrcrect->w = 128;
	inputSrcrect->h = 64;
	inputDstrect->x = 0;
	inputDstrect->y = 0;
	inputDstrect->w = 128;
	inputDstrect->h= 64;
	buffer = new Uint32[inputDstrect->w * inputDstrect->h];

}
SDL_Rect* InputWindow::returnPointerInputSrcect() {
	return inputSrcrect;
};
SDL_Rect* InputWindow::returnPointerInputDstrect() {
	return inputDstrect;
}

SDL_Texture* InputWindow::plotInputWindow(SDL_Renderer* renderer) {
	
	TTF_Font* font;
	font = TTF_OpenFont("arial.ttf", 16);
	SDL_StartTextInput();

	
	SDL_Color color = { 0, 0, 0 };
	SDL_Surface* surface = TTF_RenderText_Solid(font,"Enter the value of new charge: ", color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &inputDstrect->w, &inputDstrect->h);
	return texture;
};
void InputWindow::updatePosition(int x, int y) {
	
	inputDstrect->x = x;
	inputDstrect->y = y;
	
}
void InputWindow::clean() {
	delete[] buffer;
}


