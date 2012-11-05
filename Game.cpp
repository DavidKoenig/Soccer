#include "Game.h"
#include "OutfieldPlayer.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

CGame::CGame(void)
{
}


CGame::~CGame(void)
{
}

void CGame::runGame()
{
	int passResult = 0;
	int randomBeginner  = 0;
	srand(time(0));
	int lastPlayer = 0;
	int currentPlayer = 0;

	calcRandom(5, 11);

	CField* currentField = new CField(100, 130);

	CTeam* team1 = new CTeam("Team1", 0);
	CTeam* team2 = new CTeam("Team2", 1);



	createOutfieldPlayers(team1, currentField);
	createGoalKeeper(team1);

	createOutfieldPlayers(team2, currentField);
	createGoalKeeper(team2);

	CTeam team[2] = {*team1, *team2};
	std::cout << std::endl << team[0].getOutfieldPlayer(0)->getTeam()->getName();
	std::cout << std::endl << team[1].getOutfieldPlayer(0)->getTeam()->getName();

	for(int indexPlayer = 0; indexPlayer <= 9; ++indexPlayer)
	{
		std::cout << std::endl << "Team1\t Player: " << indexPlayer;
		std::cout << "\tPositionX: " << team1->getOutfieldPlayer(indexPlayer)->getXPosition() << "\t PositionY: " << team1->getOutfieldPlayer(indexPlayer)->getYPosition();

		std::cout << std::endl << "Team2\t Player: " << indexPlayer;
		std::cout << "\tPositionX: " << team2->getOutfieldPlayer(indexPlayer)->getXPosition() << "\t PositionY: " << team2->getOutfieldPlayer(indexPlayer)->getYPosition();
	}

	team1->setNearestPlayers();
	team2->setNearestPlayers();

	COutfieldPlayer* playerAtBall = begin(team);
	COutfieldPlayer tempPlayer = *playerAtBall;
	

	while(team[0].getGoalCount() <= 10 || team[1].getGoalCount() <= 10)
	{
		playerAtBall = doTurn(team, playerAtBall, &tempPlayer);
		setPass(&tempPlayer, team);
	}

	std::cout << std::endl << "Game is Won... biatch!";

	delete team1;
	delete team2;
	delete playerAtBall;
}

void CGame::setPass(COutfieldPlayer* player_, CTeam* team_)
{
	for(int indexTeam = 0; indexTeam <= 1; ++indexTeam)
		for(int indexPlayer = 0; indexPlayer <= 9; ++indexPlayer) {
			if((team_[indexTeam].getOutfieldPlayer(indexPlayer)->getNumber() != player_->getNumber()) || team_[indexTeam].getOutfieldPlayer(indexPlayer)->getTeam() != player_->getTeam()) {
				team_[indexTeam].getOutfieldPlayer(indexPlayer)->setAbleToPass(true);
			}
		}
}

COutfieldPlayer* CGame::begin(CTeam* team_)
{
	int randomBeginner = calcRandom(0, 1);
	cout << "\nBeginner: " << randomBeginner;
	COutfieldPlayer *currentPlayer = team_[randomBeginner].getOutfieldPlayer(calcRandom(0, 9));
	std::cout << std::endl << currentPlayer->getNumber();
	return currentPlayer;
}

COutfieldPlayer* CGame::doTurn(CTeam* team_, COutfieldPlayer* player_, COutfieldPlayer* tempPlayer_)
{
	if(calcRandom(0, 100) >= 90)
		player_ = doPass(team_, player_, tempPlayer_);
	else
		player_ = doShotOnGoal(team_, tempPlayer_, player_);

	return player_;
}

COutfieldPlayer* CGame::doPass(CTeam* team_, COutfieldPlayer* player_, COutfieldPlayer* tempPlayer_)
{
	player_ = player_->doPass(team_ , tempPlayer_, calcRandom(0, 100));
	tempPlayer_->setAbleToPass(false);
	return player_;
}

COutfieldPlayer* CGame::doShotOnGoal(CTeam* team_, COutfieldPlayer* tempPlayer_, COutfieldPlayer* player_)
{
	player_ = player_->doShot(team_, tempPlayer_, calcRandom(0, 100));
	return player_;
}


void CGame::createOutfieldPlayers(CTeam* team_, CField *field_)
{
	for(int indexPlayer = 0; indexPlayer <= 9; ++indexPlayer)
	{
		COutfieldPlayer* player = new COutfieldPlayer(team_);
		player->doPositioning(field_);

		/*std::cout << std::endl << "PositionX: " << player->getXPosition() << "\t PositionY: " << player->getYPosition();*/

		player->setNumber(indexPlayer+2);
		team_->setOutfieldPlayer(player, indexPlayer);
		
		/*std::cout << team_->getName();*/
		//std::cout << std::endl << "PositionX: " << team_.getOutfieldPlayer(indexPlayer)->getXPosition() << "\t PositionY: " << team_.getOutfieldPlayer(indexPlayer)->getYPosition();

		
	}
}

void CGame::createGoalKeeper(CTeam* team_)
{
	CGoalKeeper* keeper = new CGoalKeeper(team_);

    team_->setGoalKeeper(keeper);

	if(team_->getPosition())
		keeper->setXPosition(0);
	else
		keeper->setXPosition(130);
}

int CGame::calcRandom(int from_, int to_)
{
	return (rand() % (to_ - from_ + 1) + from_);
}


int CGame::searchForBall(CTeam* team_)
{
	int whoOwnsBall = 10;
	bool hasBall = false;
	
	for(int indexPlayer = 0; indexPlayer <= 9; ++indexPlayer){
		hasBall = team_->getOutfieldPlayer(indexPlayer)->getBall();
		if(hasBall) whoOwnsBall = indexPlayer;
	}

	return whoOwnsBall;
}