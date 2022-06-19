#include "Game.h"
using namespace std;
Game :: Game(){
	 playerPerTeam = 4;
	 maxBalls = 6;
	 totalPlayers = 11;
	 players[0]="Virat";
	 players[1]="Rohit";
	 players[2]="Dhawan";
	 players[3]="Pant";
	 players[4]="KLRahul";
	 players[5]="Jadeja";
	 players[6]="Hardik";
	 players[7]="Kunal";
	 players[8]="Bumrah";
	 players[9]="BKumar";
	 players[10]="Ishant";

	isFirstInning = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

}
bool Game::validplayer(int index){
	int n;
	vector<Player> player;
	player = teamA.player_vector;
	n=player.size();
	for(int i=0;i<n;i++){
		if(player[i].id==index){
			return false;
		}
	}
		player = teamB.player_vector;
		n=player.size();
	for(int i = 0; i < n; i++){
			if(player[i].id==index){
				return false;
			}
		}
	return true;
}
void Game::welcome(){
	cout<<("-------------------------------------------------------------------------------------------\n");
	cout<<("||                               |||Welcome to Cricket Craze!!|||                        ||");
	cout<<("\n||-------------------------------------------------------------------------------------------||");
	cout<<("\n\n\n\n");
	cout<<("-------------------------------------------------------------------------------------------\n");
	cout<<("|| 1. Create 2 Teams (Team A and Team B  with 4 players in each team) from "
			"\n||""given pool of 11 players||\n");
	cout<<("|| 2. Lead each the toss and decide the choice of play.||");
	cout<<("\n|| 3. Each innings will be of 6 balls.||\n");
	cout<<("-------------------------------------------------------------------------------------------\n");
	cout<<("\n\n\n\n");

}
void Game::showPlayers(){
	cout<<"Press Enter To continue "<<endl;
	getchar();
	cout<<"----------------------------------------------"<<endl;
	cout<<"|                                            |"<<endl;
	cout<<"|                                            |"<<endl;
	for(int i=0;i<11;i++){
		cout<<"|            "<<"["<<i<<"]"<<players[i]<<endl;
	}
	cout<<"|                                            |"<<endl;
	cout<<"|                                            |"<<endl;
	cout<<"----------------------------------------------"<<endl;
}
int Game::getNum(){
	int n;
	while(!(cin>>n)){
		cin.ignore();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"Invalid Input !Please Enter a number";
	}
		return n;
}
void Game::selectPlayers(){
	cout<<"Please Enter To continue ";
	cin.get();
	for(int i=0 ; i<playerPerTeam ; i++){
		cout<<endl;
		TeamSecltctionA:
		cout<<"Please Select Player "<<i+1<<" for Team A ";
		int PlayerIndexTeamA = getNum();
		if(PlayerIndexTeamA<0||PlayerIndexTeamA>10){
			cout<<"Please Enter The valid Number of The player! "<<endl;
			goto TeamSecltctionA;
		}
			else if(!(validplayer(PlayerIndexTeamA))){
				cout<<"The Player has Been Already Selected!";
				goto PlayerselectionB;
			}
		else{
		Player teamAplayer;
		teamAplayer.id = PlayerIndexTeamA;
		teamAplayer.playername=players[PlayerIndexTeamA];
		teamA.player_vector.push_back(teamAplayer);
		}
		cout<<"\n";


		PlayerselectionB:
		cout<<"Please Select Player "<<i+1<<" for Team B ";
		int PlayerIndexTeamB = getNum();
		if(PlayerIndexTeamB<0||PlayerIndexTeamB>10){
			cout<<"Please Enter The valid Number of The player! "<<endl;
			goto PlayerselectionB;
		}
			else if(!(validplayer(PlayerIndexTeamB))){
				cout<<"The Player has Been Already Selected!";
				goto PlayerselectionB;
			}
			else{
		Player teamBplayer;
		teamBplayer.id = PlayerIndexTeamB;
		teamBplayer.playername=players[PlayerIndexTeamB];
		teamB.player_vector.push_back(teamBplayer);
		}
	}
}
void Game::showTeamA(){
	cout<<endl<<endl;
	cout<<"Team A:"<<endl;
	for(int i=0 ; i<4 ; i++){
		cout<<"				["<<i+1<<"]  "<<teamA.player_vector[i].playername<<endl;
	}
}

void Game::showTeamB(){
	cout<<endl<<endl;
cout<<"Team B:"<<endl;
	for(int i =0 ; i<4 ; i++){
		cout<<"				["<<i+1<<"]  "<<teamB.player_vector[i].playername<<endl;
	}
}
void Game::Toss(){
	cin.ignore();
	cout<<"Press Enter for Toss A coin "<<endl;
	cin.get();
	int toss;
	srand(time(NULL));
	toss = rand() % 2;
	if(toss==0){
		cout<<"Team A Won The Toss "<<endl<<endl;
		TossChoice(teamA);
	}
	if(toss==1){
		cout<<"Team B Won The Toss"<<endl<<endl;
		TossChoice(teamB);
	}
}

void Game::TossChoice(Team TossWinnerTeam){
	cout<<"Press 1 for Bat or 2 for Ball "<<endl;
	cout<<"1. Bat"<<endl;
	cout<<"2. Ball"<<endl;
	int tossInput = getNum();
	switch(tossInput){
	case 1:
		cout<<TossWinnerTeam.name<<" Won The Toss And Choose To bat"<<endl;
		if(TossWinnerTeam.name.compare("Team-A")==0){
			battingTeam=&teamA;
			bowlingTeam=&teamB;
		}
		else{
			bowlingTeam=&teamA;
			battingTeam=&teamB;
		}
		break;
	case 2:
		cout<<TossWinnerTeam.name<<" Won The Toss And Choose To ball"<<endl;
		if(TossWinnerTeam.name.compare("Team-A")==0){
					bowlingTeam=&teamA;
					battingTeam=&teamB;
				}
				else{
					battingTeam=&teamA;
					bowlingTeam=&teamB;
				}
		break;
	default:
		cout<<"Please Enter A valid Input !";
		TossChoice(TossWinnerTeam);
		break;
	}
}

void Game::startFirstInnings(){
	cout<<"\n        ||| FIRST INNINGS STARTS  |||\n";
	isFirstInning = true;
	cout<<"\n\n";
	instilizePlayer();
}
void Game::instilizePlayer(){
	batsman = &battingTeam->player_vector[0];
	bowler = &bowlingTeam->player_vector[0];
	cout<<"\n"<<battingTeam->name<<" - "<<batsman->playername<<" is batting"<<endl;
	cout<<bowlingTeam->name<<" - "<<bowler->playername<<" is bowling"<<endl;
}
void Game::playInnings(){
	for(int i =0 ; i <maxBalls;i++){
		cin.get();
		cout<<"Press Enter To Bowling";
		cin.get();
		cout<<"\n Bowling....."<<endl;
		bat();
		if(!validateInningScore()){
			break;
		}
	}
}

void Game::bat(){
	srand(time(NULL));
	int runscoredd = rand() % 7;
	batsman->runScored = batsman->runScored + runscoredd;
	batsman->ballsPlayed = batsman->ballsPlayed +1;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runscoredd;


	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled +1;
	bowler->runsGiven = bowler->runsGiven + runscoredd;
	bowler->ballsBowled = bowler->ballsBowled + 1;
	showGameCard();
	if(runscoredd!=0){
	cout<<endl<<bowler->playername<<" To "<<batsman->playername<<" "<<runscoredd<<"   Runs!"<<endl<<endl;
	}
	else{
		cout<<endl<<bowler->playername<<" To "<<batsman->playername<<" "<<"   OUT!"<<endl<<endl;
		bowler->wicketsTaken =bowler-> wicketsTaken + 1;
		battingTeam->wicketLost = battingTeam->wicketLost +1;
		int nextplayerindex = battingTeam->wicketLost;
		batsman = &battingTeam->player_vector[nextplayerindex];
		showGameCard();
	}
}

bool Game::validateInningScore(){
	if(isFirstInning){
		if(battingTeam->wicketLost==playerPerTeam || bowlingTeam->totalBallsBowled==maxBalls){
			cout<<"\n";
			cout<<"              ||| END OF FIRST INNINGS "<<endl;
			cout<<"        "<<battingTeam->name<<" Scored Against "<<bowlingTeam->name<<" At a Lose of ";
			cout<<battingTeam->wicketLost<<" Wickets In "<<bowlingTeam->totalBallsBowled<<" Balls"<<endl;

			cout<<"        "<<bowlingTeam->name<<" Needs to Score "<<battingTeam->totalRunsScored+1<<" To Win!!";
			cout<<"\n\n\n\n               ||| START OF SECONG INNING \n";
			return false;
		}
	}

		else{

		}
		return true;
}

void Game::showGameCard(){
	cout<<"\n\n------------------------------------------------------------------------------------------------\n\n";
	cout<<"  "<<battingTeam->name<<"  "<<battingTeam->totalRunsScored<<"  - "<<battingTeam->wicketLost;
	cout<<" ("<<bowlingTeam->totalBallsBowled<<") | "<<batsman->playername<<" "<<batsman->runScored<<" ("<<batsman->ballsPlayed<<")";
	cout<<"        "<<bowler->playername<<" "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "<<bowler->wicketsTaken;
	cout<<"\n\n------------------------------------------------------------------------------------------------\n\n";
}

void Game::startSecondInning(){
	swap();
	instilizePlayer();
	isFirstInning = false;
	playInnings();
	gameEnd();
	result();
	showResultCard();

}
void Game::swap(){
	if(battingTeam->name.compare("Team-A")==0){
		battingTeam = &teamB;
		bowlingTeam = &teamA;
	}
	else if(battingTeam->name.compare("Team-B")==0){
		battingTeam = &teamA;
		bowlingTeam = &teamB;
	}
	else if(bowlingTeam->name.compare("Team-B")==0){
		battingTeam = &teamB;
		bowlingTeam = &teamA;
	}
	else{
		battingTeam = &teamA;
		bowlingTeam = &teamB;
	}
}

void Game::gameEnd(){
	cout<<"                      ||| END OF 2ND INNING |||"<<endl<<endl;
}
void Game::result(){

	if(bowlingTeam->totalRunsScored>battingTeam->totalRunsScored){
		cout<<bowlingTeam->name<<" WON THE MATCH"<<endl;
	}
	else if(battingTeam->totalRunsScored>bowlingTeam->totalRunsScored){
		cout<<battingTeam->name<<" WON THE MATCH"<<endl;
	}
	else{
		cout<<"IT'S A DRAW"<<endl;
	}
	cout<<"                   |||  MATCH ENDS |||"<<endl<<endl;
}
void Game::showResultCard(){
	cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "<<battingTeam->wicketLost<<"  ("<<bowlingTeam->totalBallsBowled<<")"<<endl;
	cout<<"==================================================="<<endl;
	cout<<"|  PLAYER            BATTING        BOWLING"<<endl;
	for(int i = 0 ; i <playerPerTeam ; i++){
		cout<<"|  ["<<i<<"] "<<battingTeam->player_vector[i].playername<<"      "<<"  "<<battingTeam->player_vector[i].runScored<<"("<<battingTeam->player_vector[i].ballsPlayed<<")         ";
		cout<<battingTeam->player_vector[i].ballsBowled<<"-"<<battingTeam->player_vector[i].runsGiven<<"-"<<battingTeam->player_vector[i].wicketsTaken<<"        |"<<endl;
	}
	cout<<"==================================================="<<endl;
	cout<<bowlingTeam->name<<" "<<bowlingTeam->totalRunsScored<<" - "<<bowlingTeam->wicketLost<<"  ("<<battingTeam->totalBallsBowled<<")"<<endl;
		cout<<"==================================================="<<endl;
		cout<<"|  PLAYER            BATTING        BOWLING"<<endl;
		for(int i = 0 ; i <playerPerTeam ; i++){
			cout<<"|  ["<<i<<"] "<<bowlingTeam->player_vector[i].playername<<"      "<<"  "<<bowlingTeam->player_vector[i].runScored<<"("<<bowlingTeam->player_vector[i].ballsPlayed<<")         ";
			cout<<bowlingTeam->player_vector[i].ballsBowled<<"-"<<bowlingTeam->player_vector[i].runsGiven<<"-"<<bowlingTeam->player_vector[i].wicketsTaken<<"        |"<<endl;
		}
	cout<<"==================================================="<<endl;
}
