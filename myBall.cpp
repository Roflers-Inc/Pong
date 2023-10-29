#include "myBall.h"
#include <math.h>

pingpong::pingpong(int sX, int sY)
{
	xSpeed = sX; ySpeed = sY;
	posX = screenWidth / 2;
	posY = screenHeight / 2;
}

void pingpong::Update(Player& p1, Player&p2) {
	if (!shouldGameOver) {
		if (posY - size < 0 || posY + size > screenHeight) {
			ySpeed = -ySpeed;
		}
		if (posX - size <= p1.posX + 5 || posX + size >= p2.posX) {
			if (CheckCollisionCircleRec(Vector2{float(posX), float(posY)}, size + 5, p1.hitbox)
				|| CheckCollisionCircleRec(Vector2{ float(posX), float(posY) }, size + 5, p2.hitbox))
			{
				xSpeed = -1.05 * xSpeed;
				ySpeed = 7 * cos(float(p2.posY - posY) / p2.size);
			}
			else {
				shouldGameOver = true;
				if (posX < screenWidth / 2) p2.score += 1;
				else p1.score++;
			}
		}
		posX += int(xSpeed);
		posY += ySpeed;
	}
}

void pingpong::Render() {
	DrawCircle(posX, posY, size, RAYWHITE);
}