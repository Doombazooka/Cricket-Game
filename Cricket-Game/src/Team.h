#include"Player.h"
#include<vector>
class Team{
public:
	std::string name;
	Team();
	int totalRunsScored;
	int wicketLost;
	int totalBallsBowled;
	std::vector<Player>player_vector;
};
