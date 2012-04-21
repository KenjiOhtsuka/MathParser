#ifndef _MATH_OPERATOR_TOKEN_H_
#define _MATH_OPERATOR_TOKEN_H_

#include <string>
#include "..\MathToken.h"

class MathOperatorToken: public MathToken {

private:
	char symbol;
public:
	static const int TYPE = 2;

	int params;
	double (*evaluate)(double*, int);
	int getType();
	bool isFunction;

	static MathOperatorToken* tryParseOperatorToken(string, int&);
	static bool isPrecendent(MathOperatorToken*, MathOperatorToken*);
};

#endif /* _MATH_OPERATOR_TOKEN_H_ */
