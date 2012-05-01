///-----------------------------------------------------------------
///
/// @file      MathNumberToken.h
/// @author    Sandro Steffen
///
///------------------------------------------------------------------

#ifndef _MATH_NUMBER_TOKEN_H_
#define _MATH_NUMBER_TOKEN_H_

#include <string>

#include "..\MathToken.h"

class MathNumberToken: public MathToken {

private:

public:
	static const int TYPE = 1;

	bool isVariable;
	double value;


	MathNumberToken();
	MathNumberToken(double);

	int getType();
	static MathNumberToken* tryParseNumberToken(string, int&);

};

#endif /* _MATH_NUMBER_TOKEN_H_ */
