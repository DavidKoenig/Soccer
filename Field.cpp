#include "Field.h"


CField::CField(int fieldHeight_, int fieldWidth_) :
	    fieldHeight(fieldHeight_), 
		fieldWidth(fieldWidth_)

{
}

CField::~CField(void)
{
}

int CField::getFieldWidth()
{
	return fieldWidth;
}

int CField::getFieldHeight()
{
	return fieldHeight;
}
