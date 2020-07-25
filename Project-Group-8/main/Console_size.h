#pragma once
#include <windows.h>
#include<iostream>

using namespace std;

// set size console
void set_console_size(SHORT width, SHORT height);

// set size map
void set_map_size(SHORT width, SHORT height);

void const_console_size();

void ignore_mouse();

void console_set_up(SHORT width, SHORT height);

void hind_roll(BOOL Show);

void Hidden_Mouse();