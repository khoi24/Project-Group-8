#pragma once
#include <iostream>
using namespace std;

static long turn;         // Luọt chơi

static int x, y;          // Hoành độ, tung độ

static int _o = 0;        // Số lần O thắng

static int _x = 0;        // Số lần X thắng

static char a[100][100];  // Mảng 2 chiều

static char key, again;   // Ấn phím

class playing
{
private:
	static bool even_odd(long turn);     // Xét chẵn lẻ
	static void hiddenCursor();          // Ẩn con trỏ
	static void appearCursor();          // Hiện con trỏ
	static void BlankMatrix();           // Tạo ma trận trống
	static void Edge(int& x, int& y);    // Xử lý chạm biên
	static char checkOX(long turn);      // Check O hoặc X
	static void drawOX(long x, long y);  // Vẽ O hoặc X
	static bool winX();                  // Điều kiện X win
	static bool winO();                  // Điều kiện O win
public:
	static void play();                  // Hàm Playing
};