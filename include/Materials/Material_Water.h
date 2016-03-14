#ifndef MATERIAL_WATER_H
#define MATERIAL_WATER_H

#include "Material.h"
#include "InterpolationMethods/CubicHermiteInterpolator.h"

namespace Materials
{
class Material_Water : public Material
{
public:
    Material_Water();

    complex getRelativePermeability(const Length &lambda) const;
    complex getRelativePermittivity(const Length &lambda) const;
    double getRefractiveIndex(const Length &lambda) const;
    double getExtinctionCoefficient(const Length &) const;

private:
    Interpolation::CubicHermiteInterpolator refractiveIndex;

    static constexpr double A1 = 5.666959820e-1;
    static constexpr double A2 = 1.731900098e-1;
    static constexpr double A3 = 2.095951857e-2;
    static constexpr double A4 = 1.125228406e-1;
    static constexpr double L1 = 5.084151894e-3;
    static constexpr double L2 = 1.818488474e-2;
    static constexpr double L3 = 2.625439472e-2;
    static constexpr double L4 = 1.073842352e1;

    double getN(double) const;
};
}

#define WATER_LAMBDAum \
    X(0.1879) \
    X(0.1916) \
    X(0.1953) \
    X(0.1993) \
    X(0.2033) \
    X(0.2073) \
    X(0.2119) \
    X(0.2164) \
    X(0.2214) \
    X(0.2262) \
    X(0.2313) \
    X(0.2371) \
    X(0.2426) \
    X(0.2490) \
    X(0.2551) \
    X(0.2616) \
    X(0.2689) \
    X(0.2761) \
    X(0.2844) \
    X(0.2924) \
    X(0.3009) \
    X(0.3107) \
    X(0.3204) \
    X(0.3315) \
    X(0.3425) \
    X(0.3542) \
    X(0.3679) \
    X(0.3815) \
    X(0.3974) \
    X(0.4133) \
    X(0.4305) \
    X(0.4509) \
    X(0.4714) \
    X(0.4959) \
    X(0.5209) \
    X(0.5486) \
    X(0.5821) \
    X(0.6168) \
    X(0.6595) \
    X(0.7045) \
    X(0.7560) \
    X(0.8211) \
    X(0.8920) \
    X(0.9840) \
    X(1.0880)

#endif // MATERIAL_WATER_H
