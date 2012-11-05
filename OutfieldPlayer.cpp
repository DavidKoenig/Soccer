#include "OutfieldPlayer.h"

#include <stdlib.h>
#include <iostream>
#include "Team.h"

using namespace std;

COutfieldPlayer::COutfieldPlayer(CTeam* team_) :
	ownsBall(false), 
	positionX(0), 
	positionY(0), 
	number(0), 
	ableToPass(true), 
	firstNearestPlayer(NULL), 
	secondNearestPlayer(NULL),
    team(team_)
{

}


COutfieldPlayer::~COutfieldPlayer(void)
{
}

void COutfieldPlayer::doPositioning(CField* field_)
{
	srand ( rand() % rand() );
	positionX = rand() % field_->getFieldWidth() +1;		// z.B. Zahl % 3 = {0, 1, 2}, deswegen rand() % (130+1). Zusätzliche + 1, weil von 1 - 130.
	positionY = rand() % field_->getFieldHeight() + 1;

	/*std::cout	<< std::endl << "PositionX: " << positionX << "\t PositionY: " << positionY;*/
}

void COutfieldPlayer::printPosition() 
{
	std::cout << std::endl << "Position of Player " << number << " is x,y(" << positionX << "," << positionY << ").";
}

bool COutfieldPlayer::getBall()
{
	return ownsBall;
}

void COutfieldPlayer::setBall(bool ownsBall_)
{
	ownsBall = ownsBall_;
}

int COutfieldPlayer::getNumber() 
{
	return number;
}

void COutfieldPlayer::setNumber(int number_)
{
	number = number_;
}

int COutfieldPlayer::getXPosition()
{
	return positionX;
}

void COutfieldPlayer::setXPosition(int positionX_)
{
	positionX = positionX_;
}

int COutfieldPlayer::getYPosition()
{
	return positionY;
}

void COutfieldPlayer::setYPosition(int positionY_)
{
	positionY = positionY_;
}

COutfieldPlayer* COutfieldPlayer::getFirstNearestPlayer()
{
	return firstNearestPlayer;
}

COutfieldPlayer* COutfieldPlayer::getSecondNearestPlayer()
{
	return secondNearestPlayer;
}

void COutfieldPlayer::setFirstNearestPlayer(COutfieldPlayer* player_)
{
	firstNearestPlayer = player_;
}

void COutfieldPlayer::setSecondNearestPlayer(COutfieldPlayer* player_)
{
	secondNearestPlayer = player_;
}


void COutfieldPlayer::setAbleToPass (bool ableToPass_)
{
	ableToPass = ableToPass_;
}

void COutfieldPlayer::printStatus()
{
	std::cout << std::endl << "\nPosition of Player " << number << " is x,y(" << positionX << "," << positionY << ").";
	std::cout << std::endl << "Is able to pass: " << ableToPass << " Owns Ball: " << ownsBall;
	std::cout << std::endl << "First nearest player: " << firstNearestPlayer + 1 << " second nearest player: " << secondNearestPlayer + 1;
}

COutfieldPlayer* COutfieldPlayer::doPass(CTeam* team_, COutfieldPlayer* tempPlayer_, int chance_)
{
	COutfieldPlayer* returnPlayer = this;

	if(chance_ <= 70) {
		if(this->firstNearestPlayer->ableToPass) 
			returnPlayer = firstNearestPlayer;

		else if (this->secondNearestPlayer->ableToPass) 
			returnPlayer = secondNearestPlayer;
	}
	else {
		if(this->team->getName() == "Team1")
			returnPlayer = team_[1].getOutfieldPlayer(rand() % 10);
		else if(this->team->getName() == "Team2")
			returnPlayer = team_[0].getOutfieldPlayer(rand() % 10);
	}

	returnPlayer->ownsBall = true;
	this->ableToPass = false;
	this->ownsBall = false;
	*tempPlayer_ = *this;

	return returnPlayer;
}

COutfieldPlayer* COutfieldPlayer::doShot(CTeam* team_, COutfieldPlayer* tempPlayer_, int chance_)
{
	COutfieldPlayer* returnPlayer = this;
	if(chance_ <= 20) {
		if(this->team->getName() == "Team1")
			team_[0].incrementGoalCount();
		else if(this->team->getName() == "Team2")
			team_[1].incrementGoalCount();
	}
	
	if(this->team->getName() == "Team1")
		returnPlayer = team_[1].getOutfieldPlayer(rand() % 10);
	else
		returnPlayer = team_[0].getOutfieldPlayer(rand() % 10);
	
	returnPlayer->ownsBall = true;
	this->ableToPass = false;
	this->ownsBall = false;
	*tempPlayer_ = *this;

	return returnPlayer;
}

CTeam* COutfieldPlayer::getTeam()
{
	return team;
}
