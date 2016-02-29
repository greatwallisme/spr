#include "include/InterpolationMethods/CubicHermiteInterpolator.h"
#include <cmath>

using namespace Interpolation;

CubicHermiteInterpolator::CubicHermiteInterpolator
(std::set<double, double> knownValues) : InterpolationMethod(knownValues)
{

}

double CubicHermiteInterpolator::interpolate(double x)
{

}

double CubicHermiteInterpolator::h00(double t)
{
    return 2 * std::pow(t, 3) - 3 * std::pow(t, 2) + 1;
}

double CubicHermiteInterpolator::h01(double t)
{
    return - 2 * std::pow(t, 3) + 3 * std::pow(t, 2);
}

double CubicHermiteInterpolator::h10(double t)
{
    return std::pow(t, 3) - 2 * std::pow(t, 2) + t;
}

double CubicHermiteInterpolator::h11(double t)
{
    return std::pow(t, 3) - std::pow(t, 2);
}
