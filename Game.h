#pragma once
#ifndef SOCCERGAME_GAME_H
#define SOCCERGAME_GAME_H

#include "Team.h"

class CGame
{
public:
	CGame(void);
	~CGame(void);
	void runGame();
	void createOutfieldPlayers(CTeam* team_, CField* field_);
	void createGoalKeeper(CTeam* team_);
	int gameBegin(CTeam* team_, int randomPlayer_);
	int searchForBall(CTeam* team_);
	void badPass(CTeam* team_);
	bool goalShot(CTeam* team_);
	int calcRandom(int from_, int to_);
	COutfieldPlayer* begin(CTeam* team_);
	COutfieldPlayer* doTurn(CTeam* team_, COutfieldPlayer* player_, COutfieldPlayer* tempPlayer_);
	COutfieldPlayer* doPass(CTeam* team_, COutfieldPlayer* player_, COutfieldPlayer* tempPlayer_);
	COutfieldPlayer* doShotOnGoal(CTeam* team_, COutfieldPlayer* tempPlayer_, COutfieldPlayer* player_);
	void setPass(COutfieldPlayer* player_, CTeam* team_);

private:
};

#endif /* SOCCERGAME_GAME_H */