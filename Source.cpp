#include"Screen.h"
#include"MouseInput.h"
#include"InputWindow.h"
#include<vector>
#include<iostream>

#define ScreenWidth 1500
#define ScreenHigh 800
Screen* screen1 = nullptr;
int main(int argc, char* argv[]) {
	SDL_Event event;
	MouseInput* mouseInput = new MouseInput;
	int xposOfMouse= 100, yposOfMouse = 200;
	bool takeInputFromInputWindow;
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
		
		
		if(SDL_PollEvent(&event) == 1) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				takeInputFromInputWindow = mouseInput->DoubleClickDetected(&xposOfMouse, &yposOfMouse, event);
				if (takeInputFromInputWindow) {
					InputWindow::updatePosition(xposOfMouse, yposOfMouse);
					screen1->update(position, takeInputFromInputWindow);
					
					Charge::updatePosition(ScreenWidth, ScreenHigh, &position, xposOfMouse, yposOfMouse);
					takeInputFromInputWindow = false;
					screen1->update(position, takeInputFromInputWindow);

				}
				
			}
			
		}
		if (event.type == SDL_QUIT) {

			isRunning = false;
		}
		SDL_Delay(100);
	}
	

	screen1->clean();
	return 0;
}