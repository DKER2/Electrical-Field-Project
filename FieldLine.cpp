#include "FieldLine.h"
#include <cmath>
#include <string.h>
#include<iostream>
#include<vector>

bool FieldLine::test(int xCurrent, int yCurrent, Charge* arrayOfCharge[10],int currentCharge) {
	bool test = true;
	int numOfCharge = arrayOfCharge[0]->numOfCharge;
	std::vector<double> distanceTo(numOfCharge);
	std::vector<int> charge(numOfCharge), xpos(numOfCharge), ypos(numOfCharge);
	
	if (xCurrent >= 0 && yCurrent >= 0 && xCurrent < ScreenWidth && yCurrent < ScreenHeight) {
		for (int i = 0; i < numOfCharge; i++) {
			if (i != currentCharge) {
				xpos[i] = arrayOfCharge[i]->getxpos();
				ypos[i] = arrayOfCharge[i]->getypos();
				distanceTo[i] = sqrt(pow(xCurrent - xpos[i], 2) + pow(yCurrent - ypos[i], 2));
				if (distanceTo[i] < 5) {
					test = false;
				}
			}
		}
	}
	else
		test = false;
	return test;
};
FieldLine::FieldLine(int ScreenWidth, int ScreenHeight) {
	this->ScreenHeight = ScreenHeight;
	this->ScreenWidth = ScreenWidth;
	buffer = new Uint32[ScreenWidth * ScreenHeight];
	memset(buffer, 0xFFFFFFFF, ScreenWidth * ScreenHeight * sizeof(Uint32));
	// information for charge
}
Uint32* FieldLine::plotField(Charge* arrayOfCharge[10]) {
	memset(buffer, 0xFFFFFFFF, ScreenWidth * ScreenHeight * sizeof(Uint32));
	int color1 = 0x00000000;
	int numOfCharge = arrayOfCharge[0]->numOfCharge; 
	std::vector<int> charge(numOfCharge), xpos(numOfCharge), ypos(numOfCharge);
	

	for (int i = 0; i < numOfCharge; i++) {
		charge[i] = arrayOfCharge[i]->getcharge();
		xpos[i] = arrayOfCharge[i]->getxpos();
		ypos[i] = arrayOfCharge[i]->getypos();
	}
	for (int i = 0; i < numOfCharge; i++) {
		
		
		for (double alpha = M_PI / 128; alpha < 2 * M_PI; alpha += (M_PI / 64)) {
			double xCurrent = xpos[i];
			double yCurrent = ypos[i];
			double alphaCurrent = alpha;
			
			double xStrengthOfField = 0;
			double yStrengthOfField = 0;
			
			while (test(xCurrent, yCurrent, arrayOfCharge,i)) {
				std::vector<double> distanceTo(numOfCharge);
				xStrengthOfField = 0;
				yStrengthOfField = 0;
				
				xCurrent += cos(alphaCurrent)*2 ;
				yCurrent += sin(alphaCurrent)*2 ;
				//std::cout << xCurrent << " " << yCurrent << std::endl;
				for (int j = 0; j < numOfCharge; j++) {
					distanceTo[j] = sqrt(pow(xCurrent - xpos[j], 2) + pow(yCurrent - ypos[j], 2));
				}
				for (int j = 0; j < numOfCharge; j++) {
					xStrengthOfField +=  9*pow(10,-9)*charge[j] * (xCurrent - xpos[j]) / pow(distanceTo[j], 3);
				}
				for (int j = 0; j < numOfCharge; j++) {
					yStrengthOfField += 9 * pow(10, -9) *charge[j] * (yCurrent - ypos[j]) / pow(distanceTo[j], 3);
				}
				alphaCurrent = atan2(yStrengthOfField, xStrengthOfField);
				if(test(xCurrent, yCurrent, arrayOfCharge, i))
				buffer[int(xCurrent) + int(yCurrent) * ScreenWidth] = color1;
				
			}
			

		}
		
	}
	return buffer;
};

void FieldLine::clean(){
	delete[] buffer;
}