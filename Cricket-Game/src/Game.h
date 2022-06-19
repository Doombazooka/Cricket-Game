#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include"Team.h"

class Game{
public:
	Game();
	int playerPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];


	bool isFirstInning;
	Team *bowlingTeam;
	Team *battingTeam;
	Team teamA;
	Team teamB;
	Player *bowler;
	Player *batsman;
	void welcome();
	void showPlayers();
	int  getNum();
	void selectPlayers();
	bool validplayer(int);
	void showTeamA();
	void showTeamB();
	void Toss();
	void TossChoice(Team);
	void startFirstInnings();
	void instilizePlayer();
	void playInnings();
	void bat();
	bool validateInningScore();
	void showGameCard();
	void startSecondInning();
	void swap();
	void gameEnd();
	void result();
	void showResultCard();
};
