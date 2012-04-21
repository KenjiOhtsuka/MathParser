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

	double a = log(0.996542);
	double b = log(7);
	double c = a / b;

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
