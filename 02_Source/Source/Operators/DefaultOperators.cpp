/*
 * DefaultOperators.cpp
 *
 *  Created on: 21.04.2012
 *      Author: Max Muster
 */

#include <cmath>
#include "DefaultOperators.h"

double DefaultOperators::Add(double *params, int paramsCount) {
	if(paramsCount == 2) {
		return params[0] + params[1];
	} else {
		return 0.0;
	}
}

double DefaultOperators::Sub(double *params, int paramsCount) {
	if(paramsCount == 2) {
		return params[0] - params[1];
	} else {
		return 0.0;
	}
}

double DefaultOperators::Mul(double *params, int paramsCount) {
	if(paramsCount == 2) {
		return params[0] * params[1];
	} else {
		return 0.0;
	}
}

double DefaultOperators::Div(double *params, int paramsCount) {
	if(paramsCount == 2) {
		return params[0] / params[1];
	} else {
		return 0.0;
	}
}

double DefaultOperators::Pow(double *params, int paramsCount) {
	if(paramsCount == 2) {
		return pow(params[0], params[1]);
	} else {
		return 0.0;
	}
}
