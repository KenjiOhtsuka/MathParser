#include <cmath>
#include "LogFunctions.h"

double LogFunctions::Log(double *params, int paramsCount) {

	return log(params[0]) / log(params[1]);

}
