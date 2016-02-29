#ifndef PHYSICALCONSTANTS_H
#define PHYSICALCONSTANTS_H

#include <cmath>

class PhysicalConstants
{
    static constexpr double c = 299792458;
    static constexpr double epsilon0 = 8.85418782e-12;
    static constexpr double mu0 = 4e-7 * std::acos(-1);
};

#endif // PHYSICALCONSTANTS_H
