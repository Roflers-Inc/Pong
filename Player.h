#pragma once
#include "Consts.h"
#include <raylib.h>

class Player{
	friend class pingpong;
private:
	int startPosX = 0, startPosY = 0;
	int posX, posY, size = 100;
	int keyDown, keyUp;
	int speed = 15;
	Rectangle hitbox;
public:
	int score = 0;

	Player() {
		posX = 0; posY = 0; keyDown = 0; keyUp = 0; hitbox = Rectangle{ 0,0,0,0 };
	}
	Player(int px, int py, int kD, int kU);

	void Render();
	void Update();
	void Restart() {
		posX = startPosX;
		posY = startPosY;
	}
};

