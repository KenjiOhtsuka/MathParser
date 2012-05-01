///-----------------------------------------------------------------
///
/// @file      MathOperatorToken.cpp
/// @author    Sandro Steffen
///
///------------------------------------------------------------------

#include <string>
#include "..\Operations\BasicOperations.h"
#include "..\Operations\LogOperations.h"
#include "..\Operations\TrigOperations.h"

#include "MathOperatorToken.h"

const MathOperatorSignature MathOperatorToken::operations[] = {
		// ident, params, precendence, infix, reference
		// standard operations
		{ "+",    2,  1, true,  BasicOperations::Add },
		{ "-",    2,  1, true,  BasicOperations::Sub },
		{ "*",    2,  2, true,  BasicOperations::Mul },
		{ "/",    2,  2, true,  BasicOperations::Div },
		{ "^",    2,  3, true,  BasicOperations::Pow },
		// logarithmic operations
		{ "log",  2, -1, false, LogOperations::Log },
		{ "ln",   1, -1, false, LogOperations::Ln },
		// trigonometric operations
		{ "sin",  1, -1, false, TrigOperations::Sin },
		{ "asin", 1, -1, false, TrigOperations::ASin },
		{ "cos",  1, -1, false, TrigOperations::Cos },
		{ "acos", 1, -1, false, TrigOperations::ACos },
		{ "tan",  1, -1, false, TrigOperations::Tan },
		{ "atan", 1, -1, false, TrigOperations::ATan },
		{ "",     0,  0, false, 0 }
};

MathOperatorToken* MathOperatorToken::tryParseOperatorToken(string data, int &index) {

	string temp("");
	while (((data[index] >= 'a') && (data[index] <= 'z'))
			|| ((data[index] >= 'A') && (data[index] <= 'Z'))) {
		temp += data[index++];
	}

	if (temp.size() == 0) {
		temp = data[index];
	}

	// find operation...
	const MathOperatorSignature *func = operations;
	while (func->Ref != 0) {
		if (temp.compare(func->Ident) == 0) {

			MathOperatorToken *mot = new MathOperatorToken();
			mot->function = func;
			mot->params = func->Params;
			mot->evaluate = func->Ref;
			mot->isFunction = !func->Infix;

			if (func->Ident.length() == 1) {
				index++;
			}

			return mot;
		}
		func++;
	}

	return NULL;
}

bool MathOperatorToken::isPrecendent(MathOperatorToken *a,
		MathOperatorToken *b) {

	int p1 = a->function->Precendence;
	int p2 = b->function->Precendence;
	return (p1 > p2);
}

int MathOperatorToken::getType() {
	return MathOperatorToken::TYPE;
}
