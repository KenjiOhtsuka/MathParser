#include <cmath>
#include "TrigOperations.h"

double TrigOperations::Sin(double *params, int paramsCount) {
	return sin(*params);
}

double TrigOperations::ASin(double *params, int paramsCount) {
	return asin(*params);
}

double TrigOperations::Cos(double *params, int paramsCount) {
	return cos(*params);
}

double TrigOperations::ACos(double *params, int paramsCount) {
	return acos(*params);
}

double TrigOperations::Tan(double *params, int paramsCount) {
	return tan(*params);
}

double TrigOperations::ATan(double *params, int paramsCount) {
	return atan(*params);
}
