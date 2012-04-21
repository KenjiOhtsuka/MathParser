#include <iostream>
#include <string>
#include <cmath>

#include "MathParser.h"

int main() {

	string input;

	// read
	cout << "Parser 1.0: Unterstützt werden Klammern und die Operationen +-*/^ ohne Leerzeichen\n" << flush;
	//cin >> input;
	input = "1+log(cos(x),7)*2";

	// calc
	MathParser *parser = new MathParser();
	parser->parse(input);
	double res = parser->evaluate(6.2);

	res = parser->evaluate(2.0);
	res = parser->evaluate(3.0);
	res = parser->evaluate(4.0);
	res = parser->evaluate(100.0);

	cout << "\nResultat: " << res << flush;

	// wait
	cin >> input;

	return 0;
}
