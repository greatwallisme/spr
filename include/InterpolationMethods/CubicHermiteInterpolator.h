#ifndef CUBICHERMITEINTERPOLATOR_H
#define CUBICHERMITEINTERPOLATOR_H

#include "InterpolationMethod.h"

namespace Interpolation
{
class CubicHermiteInterpolator : public InterpolationMethod
{
public:
    CubicHermiteInterpolator(std::set<knownPoint> knownValues);
    double interpolate(double x);

private:
    //Parameter Scaling
    double get_t(double x, knownPoint &begin, knownPoint &end);

    //Hermite Functions
    double h00(double t);
    double h01(double t);
    double h10(double t);
    double h11(double t);

    //Tangents
    double m(knownPoint &point);
};
}

#endif // CUBICHERMITEINTERPOLATOR_H
