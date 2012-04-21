#include "..\Operators\DefaultOperators.h"
#include "MathOperatorToken.h"

MathOperatorToken* MathOperatorToken::tryParseOperatorToken(string data, int& index) {

	if(data[index] == '+') {
		index++;
		MathOperatorToken *x = new MathOperatorToken();
		x->symbol = '+';
		x->params = 2;
		x->evaluate = DefaultOperators::Add;
		return x;
	}
	if(data[index] == '-') {
		index++;
		MathOperatorToken *x = new MathOperatorToken();
		x->symbol = '-';
		x->params = 2;
		x->evaluate = DefaultOperators::Sub;
		return x;
	}
	if(data[index] == '*') {
		index++;
		MathOperatorToken *x = new MathOperatorToken();
		x->symbol = '*';
		x->params = 2;
		x->evaluate = DefaultOperators::Mul;
		return x;
	}
	if(data[index] == '/') {
		index++;
		MathOperatorToken *x = new MathOperatorToken();
		x->symbol = '/';
		x->params = 2;
		x->evaluate = DefaultOperators::Div;
		return x;
	}
	if(data[index] == '^') {
		index++;
		MathOperatorToken *x = new MathOperatorToken();
		x->symbol = '^';
		x->params = 2;
		x->evaluate = DefaultOperators::Pow;
		return x;
	}

	return NULL;
}

int calcPrecedence(char c)
{
	switch(c) {
		case '+':
		case '-':
			return 1;

		case '*':
		case '/':
			return 2;

		case '^':
			return 3;

		default:
			return 0;
    }
}

bool MathOperatorToken::isPrecendent(MathOperatorToken *a, MathOperatorToken *b) {

	int p1 = calcPrecedence(a->symbol);
	int p2 = calcPrecedence(b->symbol);
	return (p1 > p2);
}

int MathOperatorToken::getType()
{
	return 2;
}
