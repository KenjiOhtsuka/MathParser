#include <iostream>
#include <string>

#include "MathParser.h"

int main() {

	string input;

	// read
	cout << "Parser 1.0: Unterstützt werden Klammern und die Operationen +-*/^ ohne Leerzeichen\n" << flush;
	//cin >> input;
	input = "1+x^2-3*(x+1)";

	// calc
	MathParser *parser = new MathParser();
	parser->parse(input);
	double res = parser->evaluate(2.0);

	res = parser->evaluate(2.0);
	res = parser->evaluate(3.0);
	res = parser->evaluate(4.0);
	res = parser->evaluate(100.0);

	cout << "\nResultat: " << res << flush;

	// wait
	cin >> input;

	return 0;
}
