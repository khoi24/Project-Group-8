#pragma once
#ifndef MENU_
#define MENU_
#include "layout.h"
#include "Menu.h"
#include "Console_size.h"

class Menu
{
private:
	layout m_layout;
public:
	void run();
	void drawLoading();
	int option();
	void drawGomoku_run();
	void choosen();
};
#endif


