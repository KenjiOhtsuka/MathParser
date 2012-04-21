#include <stack>
#include <string>

#include "Tokens\MathFunctionToken.h"
#include "Tokens\MathNumberToken.h"
#include "Tokens\MathOperatorToken.h"
#include "Tokens\MathSpecialToken.h"

#include "MathParser.h"

void MathParser::parse(string data) {

	expression = new queue<MathToken*>();
	stack<MathToken*> *operatorStack = new stack<MathToken*>();
	string temp("");

	MathToken *tok = NULL;

	int index = 0;
	while (index < data.length()) {

		// parse special tokens...
		tok = MathSpecialToken::tryParseSpecialToken(data, index);
		if (tok != NULL) {

			MathSpecialToken *spez = (MathSpecialToken*)tok;
			if(spez->value == '(') {
				operatorStack->push(tok);
				continue;
			}
			if(spez->value == ')') {
				// pop operators until '(' found...
				MathToken *xx;
				do {
					xx = operatorStack->top(); operatorStack->pop();
					if(xx->getType() != 5) {
						expression->push(xx);
					} else {
						break;
					}

				} while(true);

			}


		}

		// parse numbers...
		tok = MathNumberToken::tryParseNumberToken(data, index);
		if (tok != NULL) {
			// push to output stack
			expression->push(tok);
			continue;
		}

		// parse operators...
		tok = MathOperatorToken::tryParseOperatorToken(data, index);
		if (tok != NULL) {
			while (operatorStack->size() > 0) {

				MathOperatorToken *onStack =
						(MathOperatorToken*) operatorStack->top();

				if (MathOperatorToken::isPrecendent((MathOperatorToken*) tok,
						onStack) == false) {
					operatorStack->pop();
					expression->push(onStack);
				} else
					break;
			}
			operatorStack->push(tok);
			continue;
		}
	}

	// push the rest of the operators...
	while (operatorStack->size() > 0) {
		MathOperatorToken *onStack = (MathOperatorToken*) operatorStack->top();
		operatorStack->pop();
		expression->push(onStack);
	}
}

double MathParser::evaluate(double x) {

	stack<MathToken*> *temp = new stack<MathToken*>();

	while (expression->size() > 0) {

		// number -> stack
		// operator -> execute

		MathToken *tok = expression->front();
		expression->pop();

		if (tok->getType() == 2) {
			int size = 2;
			double *list = new double[size]();
			for (int i = 1; i >= 0 ; i--) {
				list[i] = ((MathNumberToken*)(temp->top()))->value;
				temp->pop();
			}
			double result = ((MathOperatorToken*)tok)->evaluate(list, size);

			MathNumberToken *newnumber= new MathNumberToken();
			newnumber->value = result;
			temp->push(newnumber);

			continue;
		}

		if (tok->getType() == 1) {
			temp->push(tok);
			continue;
		}

	}

	return ((MathNumberToken*)(temp->top()))->value;

}
