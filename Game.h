#pragma once
#include <string>
#include <vector>
#include <assert.h>
#include "myBall.h"
#include "Player.h"

class Game
{
private:
	Player p1;
	Player p2;
	pingpong b;
	bool isGameOver = false;
	void Render();
	void Update();
public:
	Game() {};
	Game(const int screenWidth, const int screenHeight, std::string name);
	~Game() noexcept;
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	
	bool GameShouldClose() const;
	void Tick();
};

