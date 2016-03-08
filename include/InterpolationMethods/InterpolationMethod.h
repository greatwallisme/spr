#ifndef INTERPOLATIONMETHOD_H
#define INTERPOLATIONMETHOD_H

#include <set>

namespace Interpolation
{
class InterpolationMethod
{
public:
    typedef std::pair<double, double> knownPoint;

    InterpolationMethod(std::set<knownPoint> knownValues);
    InterpolationMethod() {}
    void setValues(std::set<knownPoint> knownValues);

    virtual double interpolate(double) const = 0;

protected:
    std::set<knownPoint> knownValues;
    double minRange;
    double maxRange;
};
}

#endif // INTERPOLATIONMETHOD_H
