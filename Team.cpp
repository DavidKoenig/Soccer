#include "Team.h"
#include <iostream>

CTeam::CTeam(std::string name_, bool position_) :
		goalCount(0),
		name(name_),
		position(position_)
{
}


CTeam::~CTeam(void)
{
}

void CTeam::createOutfieldPlayers(CField* field_, CTeam* team_)
{
	for(int indexPlayer = 0; indexPlayer <= 9; ++indexPlayer)
    {
        fieldPlayers[indexPlayer]->doPositioning(field_);
    }
}

CGoalKeeper* CTeam::createGoalKeeper(CTeam* team_)
{
	CGoalKeeper *goalKeeper = new CGoalKeeper(team_);
    
    team_->keeper = goalKeeper;

	if(position)
		goalKeeper->setXPosition(0);
	else
		goalKeeper->setXPosition(130);

	return goalKeeper;
}

void CTeam::setGoalKeeper(CGoalKeeper*	keeper_)
{
    keeper = keeper_;
}

CGoalKeeper* CTeam::getGoalKeeper(){
	return keeper;
}

void CTeam::setOutfieldPlayer(COutfieldPlayer* player_, int number_)
{
	fieldPlayers[number_] = player_;
}

COutfieldPlayer* CTeam::getOutfieldPlayer(int number_)
{
	//std::cout << std::endl << "PositionX: " << fieldPlayers[number_]->getXPosition() << " PositionY: " << fieldPlayers[number_]->getYPosition();
	return fieldPlayers[number_];
}

int CTeam::getGoalCount()
{
	return goalCount;
}

void CTeam::incrementGoalCount()
{
	++goalCount;
}

std::string CTeam::getName()
{
	return name;
}

void CTeam::doWin()
{
	std::cout << std::endl << std::endl;
	std::cout << "================================================" << std::endl;
	std::cout << "\t Team: " << name << " hat gewonnen" << std::endl;
	std::cout << "================================================" << std::endl;
}

bool CTeam::getPosition()
{
	return position;
}

void CTeam::setNearestPlayers()
{
	COutfieldPlayer* dummyOne = new COutfieldPlayer(fieldPlayers[0]->getTeam());
	dummyOne->setXPosition(999);
	dummyOne->setYPosition(999);
	dummyOne->setNumber(42);

	for(int indexPlayer = 0; indexPlayer <= 9; ++indexPlayer)
	{
		fieldPlayers[indexPlayer]->setFirstNearestPlayer(dummyOne);
		fieldPlayers[indexPlayer]->setSecondNearestPlayer(dummyOne);

		for(int indexPlayer2 = 0; indexPlayer2 <= 9; ++indexPlayer2)
		{
			if(indexPlayer == indexPlayer2) indexPlayer2++;
			if(indexPlayer2 > 9) break;

			COutfieldPlayer *player = fieldPlayers[indexPlayer];
			COutfieldPlayer *nextPlayer = fieldPlayers[indexPlayer2];

			if(getDistance(player, nextPlayer) <= getDistance(player, player->getFirstNearestPlayer()))
				player->setFirstNearestPlayer(nextPlayer);

			else if(getDistance(player, nextPlayer) <= getDistance(player, player->getSecondNearestPlayer()))
				if(nextPlayer->getNumber() != player->getFirstNearestPlayer()->getNumber())
					player->setSecondNearestPlayer(nextPlayer);

		}

		std::cout << std::endl << std::endl;
		std::cout << "Team: " << name << std::endl;
		std::cout << "Player: " << indexPlayer+2 << " First nearest Player: " << fieldPlayers[indexPlayer]->getFirstNearestPlayer()->getNumber()
			<< " Second nearest Player: " << fieldPlayers[indexPlayer]->getSecondNearestPlayer()->getNumber();
	}
}

int CTeam::getDistance(COutfieldPlayer* player1, COutfieldPlayer* player2)
{
	//std::cout << player1->getXPosition() << std::endl;
	//std::cout << player2->getXPosition() << std::endl;
	if(((player1->getXPosition() + player1->getYPosition()) - (player2->getXPosition() + player2->getYPosition())) < 0)
		return ((player1->getXPosition() + player1->getYPosition()) - (player2->getXPosition() + player2->getYPosition())) * -1;
	
	return ((player1->getXPosition() + player1->getYPosition()) - (player2->getXPosition() + player2->getYPosition()));
}

COutfieldPlayer* CTeam::getPlayerArray()
{
	return *fieldPlayers;
}