#ifndef INTERPOLATIONMETHOD_H
#define INTERPOLATIONMETHOD_H

#include <set>

namespace Interpolation
{
class InterpolationMethod
{
public:
    InterpolationMethod(std::set<double, double> knownValues);
    virtual double interpolate(double) = 0;

private:
    std::set<double, double> knownValues;
};
}

#endif // INTERPOLATIONMETHOD_H
