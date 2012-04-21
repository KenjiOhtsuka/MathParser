#ifndef _MATH_SPECIAL_TOKEN_H_
#define _MATH_SPECIAL_TOKEN_H_

#include <string>
#include "..\MathToken.h"

class MathSpecialToken: public MathToken {

private:
public:
	int getType();
	char value;

	static MathSpecialToken* tryParseSpecialToken(string, int&);

};

#endif /* _MATH_SPECIAL_TOKEN_H_ */
