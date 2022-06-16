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
