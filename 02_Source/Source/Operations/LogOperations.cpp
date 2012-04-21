#include <cmath>
#include "LogOperations.h"

double LogOperations::Log(double *params, int paramsCount) {
	return log(params[0]) / log(params[1]);
}

double LogOperations::Ln(double *params, int paramsCount) {
	return log(params[0]);
}
