///-----------------------------------------------------------------
///
/// @file      MathNumberToken.cpp
/// @author    Sandro Steffen
///
///------------------------------------------------------------------

#include <cstdlib>
#include <string>
#include "MathNumberToken.h"

MathNumberToken::MathNumberToken() {
	this->value = 0.0;
	this->isVariable = false;
}

MathNumberToken::MathNumberToken(double value) {
	this->value = value;
	this->isVariable = false;
}

MathNumberToken* MathNumberToken::tryParseNumberToken(string data, int& index) {

	string temp("");
	while (((data[index] >= '0') && (data[index] <= '9'))
			|| (data[index] == '.')) {
		temp += data[index++];
	}

	if (temp.length() > 0) {
		MathNumberToken* x = new MathNumberToken();
		x->value = atof(temp.data());
		return x;

	} else {

		if (data[index] == 'x') {
			index++;
			MathNumberToken* x = new MathNumberToken();
			x->value = 0.0;
			x->isVariable = true;
			return x;

		}

		return NULL;
	}

}

int MathNumberToken::getType() {
	return MathNumberToken::TYPE;
}
