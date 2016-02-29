#ifndef CUBICHERMITEINTERPOLATOR_H
#define CUBICHERMITEINTERPOLATOR_H

#include "InterpolationMethod.h"

namespace Interpolation
{
class CubicHermiteInterpolator : public InterpolationMethod
{
public:
    CubicHermiteInterpolator(std::set<double, double> knownValues);
    double interpolate(double x);

private:
    //Hermite Functions
    double h00(double t);
    double h01(double t);
    double h10(double t);
    double h11(double t);
};
}

#endif // CUBICHERMITEINTERPOLATOR_H
