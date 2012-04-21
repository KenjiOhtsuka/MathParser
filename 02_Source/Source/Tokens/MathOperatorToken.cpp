#include "..\Operators\DefaultOperators.h"
#include "..\Functions\TrigFunctions.h"
#include "..\Functions\LogFunctions.h"
#include "MathOperatorToken.h"

MathOperatorToken* MathOperatorToken::tryParseOperatorToken(string data,
		int& index) {

	// operators
	if (data[index] == '+') {
		index++;
		MathOperatorToken *x = new MathOperatorToken();
		x->symbol = '+';
		x->params = 2;
		x->evaluate = DefaultOperators::Add;
		x->isFunction = false;
		return x;
	}
	if (data[index] == '-') {
		index++;
		MathOperatorToken *x = new MathOperatorToken();
		x->symbol = '-';
		x->params = 2;
		x->evaluate = DefaultOperators::Sub;
		x->isFunction = false;
		return x;
	}
	if (data[index] == '*') {
		index++;
		MathOperatorToken *x = new MathOperatorToken();
		x->symbol = '*';
		x->params = 2;
		x->evaluate = DefaultOperators::Mul;
		x->isFunction = false;
		return x;
	}
	if (data[index] == '/') {
		index++;
		MathOperatorToken *x = new MathOperatorToken();
		x->symbol = '/';
		x->params = 2;
		x->evaluate = DefaultOperators::Div;
		x->isFunction = false;
		return x;
	}
	if (data[index] == '^') {
		index++;
		MathOperatorToken *x = new MathOperatorToken();
		x->symbol = '^';
		x->params = 2;
		x->evaluate = DefaultOperators::Pow;
		x->isFunction = false;
		return x;
	}

	// functions
	string temp("");
	while (((data[index] >= 'a') && (data[index] >= 'z'))
			|| ((data[index] >= 'A') && (data[index] >= 'Z'))) {

		temp += data[index++];
	}

	if (temp == "sin") {
		MathOperatorToken *x1 = new MathOperatorToken();
		x1->symbol = 0;
		x1->params = 1;
		x1->evaluate = TrigFunctions::Sin;
		x1->isFunction = true;
		return x1;
	}

	if (temp == "cos") {
		MathOperatorToken *x2 = new MathOperatorToken();
		x2->symbol = 0;
		x2->params = 1;
		x2->evaluate = TrigFunctions::Cos;
		x2->isFunction = true;
		return x2;
	}

	if (temp == "log") {
		MathOperatorToken *x2 = new MathOperatorToken();
		x2->symbol = 0;
		x2->params = 2;
		x2->evaluate = LogFunctions::Log;
		x2->isFunction = true;
		return x2;
	}

	return NULL;
}

int calcPrecedence(char c) {
	switch (c) {
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;

	default:
		return -1;
	}
}

bool MathOperatorToken::isPrecendent(MathOperatorToken *a,
		MathOperatorToken *b) {

	int p1 = calcPrecedence(a->symbol);
	int p2 = calcPrecedence(b->symbol);
	return (p1 > p2);
}

int MathOperatorToken::getType() {
	return MathOperatorToken::TYPE;
}
