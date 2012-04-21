#ifndef _MATH_OPERATOR_TOKEN_H_
#define _MATH_OPERATOR_TOKEN_H_

#include <string>
#include "..\MathToken.h"

typedef struct {
		string Ident;
		int Params;
		int Precendence;
		bool Infix;
		double (*Ref)(double*, int);
	} MathOperatorSignature;

class MathOperatorToken: public MathToken {

private:
	const static MathOperatorSignature operations[];
	const MathOperatorSignature *function;

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
