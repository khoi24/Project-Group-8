#include "Console_size.h"
void set_console_size(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void set_map_size(SHORT width, SHORT height)
{
    HANDLE hand_to = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD size;
    size.X = width;
    size.Y = height;

    SetConsoleScreenBufferSize(hand_to, size);
}

void const_console_size()
{
    HWND hand_to = GetConsoleWindow();
    SetWindowLong(hand_to, GWL_STYLE, GetWindowLong(hand_to, GWL_STYLE) & ~WS_SIZEBOX);
}

void ignore_mouse()
{
    HANDLE hand_to = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleMode(hand_to, ~ENABLE_QUICK_EDIT_MODE);
}

void hind_roll(BOOL Show)
{
    HWND hand_to = GetConsoleWindow();
    ShowScrollBar(hand_to, SB_BOTH, Show);
}

void console_set_up(SHORT width, SHORT height){

    hind_roll(0);
     //set size console
     set_console_size(width, height);

    // set size map
    set_map_size(width, height);

     const_console_size();

    ignore_mouse();

}