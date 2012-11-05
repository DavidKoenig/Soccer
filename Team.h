#pragma once
#ifndef SOCCERGAME_TEAM_H
#define SOCCERGAME_TEAM_H

#include <iostream>
#include <string>
#include "OutfieldPlayer.h"
#include "GoalKeeper.h"
#include "Field.h"

class CTeam
{
public:
	CTeam(std::string name_, bool position_);
	~CTeam(void);
	void createOutfieldPlayers(CField* field_, CTeam* team_);	               // implementiert
	CGoalKeeper* createGoalKeeper(CTeam* team_);							// implementiert
    void setGoalKeeper(CGoalKeeper*	keeper_);
	CGoalKeeper* getGoalKeeper();
	int getGoalCount();														// implementiert
	void incrementGoalCount();												// implementiert
	std::string getName();													// implementiert
	void doWin();															// implementiert
    void setOutfieldPlayer(COutfieldPlayer* player_, int number_);
    COutfieldPlayer* getOutfieldPlayer(int number_);
	bool getPosition();
	void setNearestPlayers();
	int getDistance(COutfieldPlayer* player, COutfieldPlayer* player2);
	COutfieldPlayer* getPlayerArray();

private:
	int              goalCount;
	std::string		 name;
	bool		     position;
	COutfieldPlayer* fieldPlayers[10];	// prefer pointer to player
	CGoalKeeper*	 keeper;			// prefer pointer to player
};

#endif /* SOCCERGAME_TEAM_H */