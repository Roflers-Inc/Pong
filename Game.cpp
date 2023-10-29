#include "Game.h"

Game::Game(const int screenWidth, const int screenHeight, std::string name)
{
	assert(!GetWindowHandle());
	InitWindow(screenWidth, screenHeight, name.c_str());
	SetTargetFPS(60);
	p1 = Player(30, screenHeight / 2, KEY_W, KEY_S);
	p2 = Player(screenWidth - 30, screenHeight / 2, KEY_UP, KEY_DOWN);
	b = pingpong(7, 7);
}

Game::~Game() noexcept {
	assert(GetWindowHandle());
	CloseWindow();
}

bool Game::GameShouldClose() const {
	return WindowShouldClose();
}

void Game::Tick() {
	Update();
	BeginDrawing();
	Render();
	EndDrawing();
}

void Game::Update() {
	if (!isGameOver) {
		p1.Update();
		p2.Update();
		b.Update(p1, p2);
		if (b.shouldGameOver) isGameOver = true;
	}
	else {
		if (IsKeyPressed(KEY_R)) {
			p1.Restart();
			p2.Restart();
			b.Restart();
			isGameOver = false;
		}
	}
}

void Game::Render() {
	ClearBackground(BLACK);
	if (!isGameOver) {
		p1.Render();
		p2.Render();
		b.Render();
		DrawText(std::to_string(p1.score).c_str(), screenWidth / 2 - 100, 10, 20, WHITE);
		DrawText(std::to_string(p2.score).c_str(), screenWidth / 2 + 100, 10, 20, WHITE);
	}
	else {
		DrawText("Game over!\nPress R to restart", 0, GetScreenHeight() / 2, 100, WHITE);
	}
}