#include "Game.h"

using namespace std;

int main() {
	Game game(1080, 720, "Pong!");
	while (!game.GameShouldClose()) game.Tick();
	return 0;
}