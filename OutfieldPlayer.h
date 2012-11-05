#pragma once
#ifndef SOCCERGAME_OUTFIELDPLAYER_H
#define SOCCERGAME_OUTFIELDPLAYER_H

#include "Field.h"

class CTeam;

class COutfieldPlayer
{
private:
	//enum EPassResult {PASSED, BADPASS, GOALSHOT};

public:
	COutfieldPlayer(CTeam* team_);
	~COutfieldPlayer(void);

	void doPositioning(CField *field_);		// implemented
	void checkPositioning();
	void printPosition();										// implemented
	bool getBall();												// implemented
	void setBall(bool ownsBall_);								// implemented
	int getNumber();											// implemented
	void setNumber(int number_);								// implemented
	int getXPosition();											// implemented
	void setXPosition(int positionX_);							// implemented
	int getYPosition();											// implemented
	void setYPosition(int PositionY_);							// implemented
	COutfieldPlayer* getFirstNearestPlayer();								
	COutfieldPlayer* getSecondNearestPlayer();
	void setFirstNearestPlayer(COutfieldPlayer* player_);
	void setSecondNearestPlayer(COutfieldPlayer* player_);
	void setAbleToPass (bool ableToPass_);
	int getDistance(COutfieldPlayer player);
	int doPass(COutfieldPlayer* player_);		//implemented, but not tested
	COutfieldPlayer* doPass(CTeam* team_, COutfieldPlayer* tempPlayer_, int chance_);
	COutfieldPlayer* doShot(CTeam* team_, COutfieldPlayer* tempPlayer_, int chance_);
	void doCapture();
	void printStatus();
	CTeam* getTeam();

private:
	bool ownsBall;
	int positionX;
	int positionY;
	int number;
	bool ableToPass;
	COutfieldPlayer* firstNearestPlayer;
	COutfieldPlayer* secondNearestPlayer;
    CTeam* team;
};

#endif /* SOCCERGAME_OUTFIELDPLAYER_H */
