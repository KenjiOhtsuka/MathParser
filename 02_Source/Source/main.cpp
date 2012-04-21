#include <iostream>
#include <string>

#include "MathParser.h"

int main() {

	string input;

	// read
	cout << "Parser 1.0: Unterstützt werden die Operationen +-*/^ ohne Klammern und Leerzeichen\n" << flush;
	cin >> input;

	// calc
	MathParser *parser = new MathParser();
	parser->parse(input);
	cout << "\nResultat: " << parser->evaluate(0.0) << flush;

	return 0;
}
