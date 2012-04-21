#include <cmath>
#include "BasicOperations.h"

double BasicOperations::Add(double *params, int paramsCount) {
	if(paramsCount == 2) {
		return params[0] + params[1];
	} else {
		return 0.0;
	}
}

double BasicOperations::Sub(double *params, int paramsCount) {
	if(paramsCount == 2) {
		return params[0] - params[1];
	} else {
		return 0.0;
	}
}

double BasicOperations::Mul(double *params, int paramsCount) {
	if(paramsCount == 2) {
		return params[0] * params[1];
	} else {
		return 0.0;
	}
}

double BasicOperations::Div(double *params, int paramsCount) {
	if(paramsCount == 2) {
		return params[0] / params[1];
	} else {
		return 0.0;
	}
}

double BasicOperations::Pow(double *params, int paramsCount) {
	if(paramsCount == 2) {
		return pow(params[0], params[1]);
	} else {
		return 0.0;
	}
}
