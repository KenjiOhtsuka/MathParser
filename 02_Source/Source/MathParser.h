#ifndef _MATH_PARSER_H_
#define _MATH_PARSER_H_

#include <queue>
#include <string>
#include "MathToken.h"

using namespace std;

class MathParser {

private:
	// this is the mathematical expression in reverse polish notation
	queue<MathToken*> *expression;

public:
	void parse(string);
	double evaluate(double);

};

#endif /* _MATH_PARSER_H_ */
