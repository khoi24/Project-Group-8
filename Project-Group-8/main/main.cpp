// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "layout.h"
#include "playing.h"
using namespace std;
int main()
{
	WhiteConsole();
	layout::drawBoard();
	playing::play();
	return 0;
}


