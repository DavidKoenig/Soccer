#include "GoalKeeper.h"
#include <stdlib.h>

CGoalKeeper::CGoalKeeper(CTeam* team_) :
	ownsBall(false),
	positionX(0),
	positionY(50),
	number(0),
	team(team_)
{
}

CGoalKeeper::~CGoalKeeper(void)
{
}

void CGoalKeeper::setXPosition(int positionX_)
{
	positionX = positionX_;
}

int CGoalKeeper::getXPosition()
{
	return positionX;
}

void CGoalKeeper::setYPosition(int positionY_)
{
	positionY = positionY_;
}

int CGoalKeeper::getYPosition()
{
	return positionY;
}

bool CGoalKeeper::shotOnGoal()
{
	ownsBall = true; 

	bool goal = false;
	int goalChance = 0;
	srand(rand());

	goalChance = rand() % 100 + 1;

	if(goalChance > 0 && goalChance <= 75){
		goal = false;
	}
	else goal = true;

	return goal;
}

void CGoalKeeper::doPass()
{
	ownsBall = false;
}