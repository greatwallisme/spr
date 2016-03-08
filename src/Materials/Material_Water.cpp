#include "include/Materials/Material_Water.h"

using namespace Materials;

Material_Water::Material_Water() : Material(water)
{
    std::set<Interpolation::InterpolationMethod::knownPoint> refIndexPoints;
#define X(a) refIndexPoints.insert({Length(a, Length::micrometer).get(), getN(a)});
    WATER_LAMBDAum
#undef X
    refractiveIndex.setValues(refIndexPoints);
}

complex Material_Water::getRelativePermeability(const Length &) const
{
    return 1;
}

complex Material_Water::getRelativePermittivity(const Length &lambda) const
{
    double n = refractiveIndex.interpolate(lambda.get());
    double k = 0;

    return complex(n * n - k * k, 2 * n * k);
}

double Material_Water::getN(double l) const
{
    return std::sqrt(
               1 +
               ((A1 * l * l) / (l * l - L1)) +
               ((A2 * l * l) / (l * l - L2)) +
               ((A3 * l * l) / (l * l - L3)) +
               ((A4 * l * l) / (l * l - L4)));
}
