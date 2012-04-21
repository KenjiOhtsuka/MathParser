#ifndef _MATH_NUMBER_TOKEN_H_
#define _MATH_NUMBER_TOKEN_H_

#include <string>

#include "..\MathToken.h"

class MathNumberToken: public MathToken {

private:

public:
	static const int TYPE = 1;

	MathNumberToken();
	MathNumberToken(double);

	// gets or sets the value
	//double getValue() { return this->value; }
	//void setValue(double value) { this->value = value; }
	double value;
	bool isVariable;

	int getType();

	static MathNumberToken* tryParseNumberToken(string, int&);

};

#endif /* _MATH_NUMBER_TOKEN_H_ */
