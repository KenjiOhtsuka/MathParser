///-----------------------------------------------------------------
///
/// @file      MathSpecialToken.cpp
/// @author    Sandro Steffen
///
///------------------------------------------------------------------

#include "MathSpecialToken.h"

int MathSpecialToken::getType()
{
	return MathSpecialToken::TYPE;
}

MathSpecialToken* MathSpecialToken::tryParseSpecialToken(string data, int& index) {

	if((data[index] == '(') || (data[index] == ')') || (data[index] == ',')) {
		MathSpecialToken *tok = new MathSpecialToken();
		tok->value = data[index];
		index++;

		return tok;
	}

	return 0;
}

