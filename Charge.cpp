#include "Charge.h"
int Charge::numOfCharge = 0;
Charge::Charge(double charge, int xpos, int ypos) {
	this->charge = charge;
	this->xpos = xpos;
	this->ypos = ypos;
}
int Charge::getxpos() {
	return xpos;
}
int Charge::getypos() {
	return ypos;
}
int Charge::getcharge() {
	return charge;
}
std::vector<std::vector<int>> Charge::initialPosition(int numOfCharge1, int ScreenWidth, int ScreenHigh) {
	int element;
	std::vector<std::vector<int>> position(numOfCharge1, std::vector<int>(3));
	for (int i = 0; i < numOfCharge1; i++) {
		std::cout << "Enter the magnitude of charge Of " << i + 1 << "th charges \n";

		std::cin >> element;
		position[i][0] = element;
		std::cout << "Enter the coordinates Of " << i + 1 << "th charges(Enter data in format \"x y\"\n";

		std::cin >> element;
		position[i][1] = element;

		std::cin >> element;
		position[i][2] = element;

		if (position[i][1] >= ScreenWidth || position[i][1] < 0) {
			std::cout << "Not Applicable. Please Enter Another Charge\n";
			i--;

		}
		else if (position[i][2] >= ScreenHigh || position[i][2] < 0) {
			std::cout << "Not Applicable. Please Enter Another Charge\n";
			i--;

		}
	}
	numOfCharge = numOfCharge1;
	return position;
}
void Charge::updatePosition( int ScreenWidth, int ScreenHigh, std::vector<std::vector<int>>* position,  int xposOfMouse, int yposOfMouse) {
	if (xposOfMouse >= 0 && xposOfMouse < ScreenWidth && yposOfMouse >= 0 && yposOfMouse < ScreenHigh) {
		std::cout << "Enter the value of charge want to add" << std::endl;
		int charge;
		std::cin >> charge;
		position->push_back({ charge, xposOfMouse, yposOfMouse });
		numOfCharge++;
	}
}