#include <cmath>
#include "TrigFunctions.h"

double TrigFunctions::Sin(double *params, int paramsCount) {
	return sin(*params);
}

double TrigFunctions::ASin(double *params, int paramsCount) {
	return asin(*params);
}

double TrigFunctions::Cos(double *params, int paramsCount) {
	return cos(*params);
}

double TrigFunctions::ACos(double *params, int paramsCount) {
	return acos(*params);
}

double TrigFunctions::Tan(double *params, int paramsCount) {
	return tan(*params);
}

double TrigFunctions::ATan(double *params, int paramsCount) {
	return atan(*params);
}
