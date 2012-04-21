#include <cstdlib>
#include <string>
#include "MathNumberToken.h"

MathNumberToken* MathNumberToken::tryParseNumberToken(string data, int& index) {

	string temp("");
	while(((data[index] >= '0') && (data[index] <= '9')) || (data[index] == '.')) {
		temp += data[index++];
	}

	if(temp.length() > 0) {

		MathNumberToken* x = new MathNumberToken();
		x->value = atof(temp.data());
		return x;

	} else {
		return NULL;
	}

}

int MathNumberToken::getType()
{
	return 1;
}
