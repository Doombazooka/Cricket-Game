#include"Game.h"
int main() {
	Game game;
	game.welcome();
	game.showPlayers();
	game.selectPlayers();
	game.showTeamA();
	game.showTeamB();
	game.Toss();
	game.startFirstInnings();
	game.playInnings();
	game.startSecondInning();

	return 0;
}
