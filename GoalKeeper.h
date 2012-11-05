#pragma once
#ifndef SOCCERGAME_GOALKEEPER_H
#define SOCCERGAME_GOALKEEPER_H

class CTeam;

class CGoalKeeper
{
public:
	CGoalKeeper(CTeam* team_);
	~CGoalKeeper(void);
	void setXPosition(int positionX_);
	int getXPosition();
	void setYPosition(int positionY_);
	int getYPosition();
	bool shotOnGoal();
	void doPass();
	

private:
	bool ownsBall;
	int positionX;
	int positionY;
	int number;
	CTeam* team;
};

#endif // GOALKEEPER_H
