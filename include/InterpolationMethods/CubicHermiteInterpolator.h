#ifndef CUBICHERMITEINTERPOLATOR_H
#define CUBICHERMITEINTERPOLATOR_H

#include "InterpolationMethod.h"

namespace Interpolation
{
class CubicHermiteInterpolator : public InterpolationMethod
{
public:
    CubicHermiteInterpolator(std::set<knownPoint> knownValues);
    CubicHermiteInterpolator() {}

    double interpolate(double x) const;

private:
    //Parameter Scaling
    double get_t(double x, knownPoint &begin, knownPoint &end) const;

    //Hermite Functions
    double h00(double t) const;
    double h01(double t) const;
    double h10(double t) const;
    double h11(double t) const;

    //Tangents
    double m(knownPoint &point) const;
};
}

#endif // CUBICHERMITEINTERPOLATOR_H
