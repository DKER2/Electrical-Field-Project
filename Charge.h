#pragma once
#include<iostream>
#include<vector>
#include<string>
class Charge
{
public:
	
	Charge(double charge, int xpos, int ypos);
	int getxpos();
	int getypos();
	int getcharge();
	static int numOfCharge;
	//update position funtion
	static std::vector<std::vector<int>> initialPosition(int numOfCharge1,int ScreenWidth,int ScreenHigh);
	static void updatePosition( int ScreenWidth, int ScreenHigh, std::vector<std::vector<int>>* position, int xposOfMouse, int yposOfMouse, std::string inputString);
private:
	double charge;
	int xpos, ypos;
};

