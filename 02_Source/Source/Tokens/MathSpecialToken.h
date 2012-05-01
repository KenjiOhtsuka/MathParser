///-----------------------------------------------------------------
///
/// @file      MathSpecialToken.h
/// @author    Sandro Steffen
///
///------------------------------------------------------------------

#ifndef _MATH_SPECIAL_TOKEN_H_
#define _MATH_SPECIAL_TOKEN_H_

#include <string>
#include "..\MathToken.h"

class MathSpecialToken: public MathToken {

private:
public:
	static const int TYPE = 3;
	char value;

	int getType();
	static MathSpecialToken* tryParseSpecialToken(string, int&);

};

#endif /* _MATH_SPECIAL_TOKEN_H_ */
