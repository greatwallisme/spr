#include "include/InterpolationMethods/CubicHermiteInterpolator.h"
#include <algorithm>
#include <boost/assert.hpp>
#include <cmath>

using namespace Interpolation;

CubicHermiteInterpolator::CubicHermiteInterpolator
(std::set<knownPoint>knownValues) : InterpolationMethod(knownValues)
{

}

double CubicHermiteInterpolator::interpolate(double x) const
{
    BOOST_ASSERT_MSG((x >= minRange) && (x <= maxRange),
                     "Interpolation value outside x range.");
    for (auto &known : knownValues)
        {
        if (known.first == x)
            {
            return known.second;
            }
        }

    knownPoint p0 = *std::find_if(knownValues.rbegin(), knownValues.rend(),
                                  [&x](const knownPoint val)
        {
        return val.first <= x;
        });
    knownPoint p1 = *std::find_if(knownValues.begin(), knownValues.end(),
                                  [&x](const knownPoint val)
        {
        return val.first >= x;
        });

    double t = get_t(x, p0, p1);

    return h00(t) * p0.second + h10(t) * (p1.first - p0.first) * m(p0) +
           h01(t) * p1.second + h11(t) * (p1.first - p0.first) * m(p1);
}

double CubicHermiteInterpolator::get_t
(double x, knownPoint &begin, knownPoint &end) const
{
    return (x - begin.first) / (end.first - begin.first);
}

double CubicHermiteInterpolator::h00(double t) const
{
    return 2 * std::pow(t, 3) - 3 * std::pow(t, 2) + 1;
}

double CubicHermiteInterpolator::h01(double t) const
{
    return - 2 * std::pow(t, 3) + 3 * std::pow(t, 2);
}

double CubicHermiteInterpolator::h10(double t) const
{
    return std::pow(t, 3) - 2 * std::pow(t, 2) + t;
}

double CubicHermiteInterpolator::h11(double t) const
{
    return std::pow(t, 3) - std::pow(t, 2);
}

double CubicHermiteInterpolator::m(knownPoint &point) const
{
    auto iter = std::find(knownValues.begin(), knownValues.end(), point);
    BOOST_ASSERT_MSG(iter != knownValues.end(), "Unknown point to find tangent");
    double m = 0;

    if (iter != knownValues.begin())
        {
        m += 0.5 * (iter->second - std::prev(iter)->second) /
             (iter->first - std::prev(iter)->first);
        }
    if (iter != std::prev(knownValues.end()))
        {
        m += 0.5 * (std::next(iter)->second - iter->second) /
             (std::next(iter)->first - iter->first);
        }

    return m;
}
