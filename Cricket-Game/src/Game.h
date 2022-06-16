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
	Player batsman;
	void welcome();
	void showPlayers();
	int getNum();
	void selectPlayers();
	bool validplayer(int);
	void showTeamA();
	void showTeamB();
};
