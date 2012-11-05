#pragma once
#ifndef SOCCERGAME_FIELD_H
#define SOCCERGAME_FIELD_H

class CField
{
public:
	CField(int fieldHeight_, int fieldWidth_);
	~CField(void);
	int getFieldWidth();
	int getFieldHeight();

private:
	int fieldHeight;
	int fieldWidth;
};

#endif /* SOCCERGAME_FIELD_H */