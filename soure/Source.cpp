#include"Screen.h"
#include"MouseInput.h"
#include"InputWindow.h"
#include<string>
#include<vector>
#include<iostream>


#define ScreenWidth 1500
#define ScreenHigh 800

Screen* screen1 = nullptr;
int main(int argc, char* argv[]) {
	SDL_Event event;
	std::string inputString ="";
	MouseInput* mouseInput = new MouseInput;
	int xposOfMouse= 100, yposOfMouse = 200;
	bool renderInputWindow;
	int numOfCharge,element;
	std::cout << "Enter number of Charges: \n";
	std::cin >> numOfCharge;
	std::vector<std::vector<int>> position(numOfCharge, std::vector<int>(3));
	position = Charge::initialPosition(numOfCharge,ScreenWidth,ScreenHigh);
	bool isRunning = true;
	screen1 = new Screen(ScreenWidth, ScreenHigh);
	screen1->update(position,false);
	//below is for keep the window from update screen
	
	while (isRunning) {
		
		if(SDL_WaitEvent(&event) == 1 ) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				renderInputWindow = mouseInput->DoubleClickDetected(&xposOfMouse, &yposOfMouse, event);
				if (renderInputWindow) {
					InputWindow::updatePosition(xposOfMouse, yposOfMouse);
					screen1->update(position, true);
					renderInputWindow = false;
				}
			}
			else if (event.type == SDL_TEXTINPUT) {
				inputString += event.text.text;
				
				InputWindow::updateTexture(inputString);
				
				screen1->update(position, true);	
			}
			else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE && inputString.size()) {
				inputString.pop_back();
				InputWindow::updateTexture(inputString);

				screen1->update(position, true);
			}
			else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == 13) {
				std::cout << "enter detected" << std::endl;
				Charge::updatePosition(ScreenWidth, ScreenHigh, &position, xposOfMouse, yposOfMouse,inputString);
				screen1->update(position, false);
				inputString = "";
				InputWindow::updateTexture(inputString);
			}
			
	}
		if (event.type == SDL_QUIT) {

			isRunning = false;
		}
		
	}
	

	screen1->clean();
	return 0;
}