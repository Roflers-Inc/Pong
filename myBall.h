#pragma once
#include "Player.h"

class pingpong
{
	friend class Bot;
private:
	float xSpeed;
	int ySpeed;
	int size = 10;
	int posX, posY;
public:
	bool shouldGameOver = false;

	pingpong() {
		xSpeed = 0;
		ySpeed = 0;
		posX = 0;
		posY = 0;
	};
	pingpong(int sX, int sY);

	void Update(Player& p1, Player& p2);
	void Render();
	void Restart() {
		shouldGameOver = false;
		posX = screenWidth / 2;
		posY = screenHeight / 2;
		xSpeed = 7; ySpeed = 7;
	}
};

