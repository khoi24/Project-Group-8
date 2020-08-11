// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "layout.h"
#include "playing.h"
#include "Console_size.h"
#include "menu.h"
using namespace std;

int main()
{
	console_set_up(80, 50);

	Menu game;
	game.run();

	return 0;
}