#ifndef _MATH_NUMBER_TOKEN_H_
#define _MATH_NUMBER_TOKEN_H_

#include <string>

#include "..\MathToken.h"

class MathNumberToken: public MathToken {

private:
public:
	double value;
	int getType();

	static MathNumberToken* tryParseNumberToken(string, int&);

};

#endif /* _MATH_NUMBER_TOKEN_H_ */
