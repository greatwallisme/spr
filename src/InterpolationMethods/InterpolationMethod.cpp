#include "include/InterpolationMethods/InterpolationMethod.h"

using namespace Interpolation;

InterpolationMethod::InterpolationMethod(std::set<double, double> knownValues)
    : knownValues(knownValues)
{

}
