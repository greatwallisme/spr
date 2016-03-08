#include "include/InterpolationMethods/InterpolationMethod.h"

using namespace Interpolation;

InterpolationMethod::InterpolationMethod (std::set<knownPoint> knownValues)
    : knownValues(knownValues)
{
    minRange = knownValues.begin()->first;
    maxRange = knownValues.rbegin()->first;
}

void InterpolationMethod::setValues(std::set<knownPoint> knownValues)
{
    this->knownValues = knownValues;
    minRange = knownValues.begin()->first;
    maxRange = knownValues.rbegin()->first;
}
