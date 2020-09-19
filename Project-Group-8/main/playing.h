#pragma once
#ifndef PLAYING_
#define PLAYING_
#include <iostream>
#pragma comment(lib, "winmm.lib")
#include <MMsystem.h>
#include "FindTheWay.h"

using namespace std;

static char key;   // Ấn phím

class coor {
private:
	int m_x, m_y;
public:
	void set_x_y(int x, int y);
	int get_x() {
		return m_x;
	}
	int get_y() {
		return m_y;
	}
	

};


class board
{
	friend class coor;
private:
	long turn;         // Luọt chơi

	int x, y;          // Hoành độ, tung độ

	int _o = 0;        // Số lần O thắng

	int _x = 0;        // Số lần X thắng

	char a[100][100];  // Mảng 2 chiều

	int pr_x, pr_y; // vi tri ve x hoac o trc do
	int pr_x_ai, pr_y_ai;//trong ai day la nuoc di cua nguoi choi
	bool turn_back = true; //han che so lan quay lai

	coor line[6];




public:

	board();
	void play();                  // Hàm Playing
	void playWithComputer();    // ham choi voi may
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
	void sound_kick();
	void sound_succeeded();
	void sound_winner();
	void color_succeede();
	void pause();
	board &load(const board &temp);
	board save();
	void re_new();
};
#endif
