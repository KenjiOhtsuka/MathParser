#include <stack>
#include <string>

#include "Tokens\MathNumberToken.h"
#include "Tokens\MathOperatorToken.h"
#include "Tokens\MathSpecialToken.h"

#include "MathParser.h"

void MathParser::parse(string data) {

	expression = new vector<MathToken*>();
	stack<MathToken*> *operatorStack = new stack<MathToken*>();
	string temp("");

	MathToken *tok = NULL;

	int index = 0;
	while (index < data.length()) {

		// parse special tokens...
		tok = MathSpecialToken::tryParseSpecialToken(data, index);
		if (tok != NULL) {

			MathSpecialToken *spez = (MathSpecialToken*) tok;
			if (spez->value == '(') {
				operatorStack->push(tok);
				continue;
			}
			if (spez->value == ',') {
				// pop operators until '(' found...
				MathToken *xx;
				do {
					xx = operatorStack->top();
					//operatorStack->pop();
					if (xx->getType() != 5) {
						operatorStack->pop();
						expression->push_back(xx);
					} else {
						break;
					}

				} while (true);

				/*
				 xx = operatorStack->top();
				 if (((MathOperatorToken*) xx)->isFunction == true) {
				 operatorStack->pop();
				 expression->push_back(xx);
				 }*/
			}
			if (spez->value == ')') {
				// pop operators until '(' found...
				MathToken *xx;
				do {
					xx = operatorStack->top();
					operatorStack->pop();
					if (xx->getType() != 5) {
						expression->push_back(xx);
					} else {
						break;
					}

				} while (true);

				xx = operatorStack->top();
				if (((MathOperatorToken*) xx)->isFunction == true) {
					operatorStack->pop();
					expression->push_back(xx);
				}
			}

		}

		// parse numbers...
		tok = MathNumberToken::tryParseNumberToken(data, index);
		if (tok != NULL) {
			// push to output stack
			expression->push_back(tok);
			continue;
		}

		// parse operators...
		tok = MathOperatorToken::tryParseOperatorToken(data, index);
		if (tok != NULL) {

			MathOperatorToken *theOp = (MathOperatorToken*) tok;
			if (theOp->isFunction == true) {
				operatorStack->push(tok);
				continue;
			} else {

				while (operatorStack->size() > 0) {

					MathOperatorToken *onStack =
							(MathOperatorToken*) operatorStack->top();

					if (MathOperatorToken::isPrecendent(
							(MathOperatorToken*) tok, onStack) == false) {
						operatorStack->pop();
						expression->push_back(onStack);
					} else
						break;
				}
				operatorStack->push(tok);
				continue;

			}
		}
	}

	// push the rest of the operators...
	while (operatorStack->size() > 0) {
		MathOperatorToken *onStack = (MathOperatorToken*) operatorStack->top();
		operatorStack->pop();
		expression->push_back(onStack);
	}
}

double MathParser::evaluate(double x) {

	// init stack
	stack<MathToken*> *temp = new stack<MathToken*>();

	unsigned int index = 0;
	while (index < expression->size()) {

		// get token
		MathToken *token = expression->at(index++);

		// if token is a number -> push to stack
		if (token->getType() == MathNumberToken::TYPE) {

			// cast
			MathNumberToken *mnt = (MathNumberToken*) token;

			// if token is a variable, push x to stack
			// if token is no variable, push copy to stack
			if (mnt->isVariable == true) {
				temp->push(new MathNumberToken(x));
			} else {
				temp->push(new MathNumberToken(*mnt));
			}
		}

		// if token is an operator -> execute
		if (token->getType() == MathOperatorToken::TYPE) {

			// cast
			MathOperatorToken *mot = (MathOperatorToken*) token;

			// pop n numbers from stack
			double *param = new double[mot->params];
			for (int paramIndex = mot->params - 1; paramIndex >= 0;
					paramIndex--) {
				MathNumberToken *mnt = (MathNumberToken*) temp->top();
				temp->pop();
				param[paramIndex] = mnt->value;
				delete mnt;
			}

			// execute operation
			double result = mot->evaluate(param, mot->params);

			// push result to stack
			temp->push(new MathNumberToken(result));
		}
	}

	// the last element on the stack is the final result
	MathNumberToken *last = (MathNumberToken*) temp->top();
	temp->pop();
	double final = last->value;
	delete last;

	return final;
}
