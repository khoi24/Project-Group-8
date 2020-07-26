#pragma once
#include <iostream>
using namespace std;

static char key;   // Ấn phím

class board
{
private:
	long turn;         // Luọt chơi

	int x, y;          // Hoành độ, tung độ

	int _o=0;        // Số lần O thắng

	int _x=0;        // Số lần X thắng

	char a[100][100];  // Mảng 2 chiều

	int pr_x, pr_y; // vi tri ve x hoac o trc do

	bool turn_back = true; //han che so lan quay lai

	


public:
	void play();                  // Hàm Playing
	void drawBoard();
	bool even_odd();     // Xét chẵn lẻ
	char checkOX();      // Check O hoặc X
	void drawOX();  // Vẽ O hoặc X
	static void hiddenCursor();          // Ẩn con trỏ
	static void appearCursor();          // Hiện con trỏ
	bool winX();                  // Điều kiện X win
	bool winO();                  // Điều kiện O win
	void Oiswinner();                // Hiển thị O thắng cuộc
	void Xiswinner();                // Hiển thị X thắng cuộc
	void BlankMatrix();           // Tạo ma trận trống
	void Edge();    // Xử lý chạm biên
	void init();
	
	
};
