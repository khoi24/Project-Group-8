// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "layout.h"
#include "playing.h"
#include "Console_size.h"
using namespace std;

int main()
{
	console_set_up(80, 50);
	
	// comment
	int a, b;
	// test

	layout caro;
	caro.run();
	return 0;
}