#include "Player.h"

void Player::Update()
{
	if (IsKeyDown(keyDown)) {
		if(posY > 0) posY -= speed;
	}
	else if (IsKeyDown(keyUp)) {
		if(posY + size < screenHeight) posY += speed;
	}
	hitbox.x = posX;
	hitbox.y = posY;
}

void Player::Render() {
	DrawRectangle(posX, posY, 5, size, WHITE);
}

Player::Player(int px, int py, int kD, int kU)
{
	posX = px; posY = py; keyDown = kD; keyUp = kU;
	startPosX = px; startPosY = py;
	hitbox = Rectangle{ float(px), float(py), 5, float(size)};
}
