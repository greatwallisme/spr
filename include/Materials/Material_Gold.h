#ifndef MATERIAL_GOLD_H
#define MATERIAL_GOLD_H

#include "Material.h"
#include "../InterpolationMethods/CubicHermiteInterpolator.h"

namespace Materials
{
class Material_Gold : public Material
{
public:
    Material_Gold();

    complex getRelativePermeability(const Length &lambda) const;
    complex getRelativePermittivity(const Length &lambda) const;
    double getRefractiveIndex(const Length &lambda) const;
    double getExtinctionCoefficient(const Length &lambda) const;

private:
    Interpolation::CubicHermiteInterpolator refractiveIndex;
    Interpolation::CubicHermiteInterpolator extinctionCoefficient;
};
}

#define GOLD_LAMBDAum_REFINDEX_EXTCOEFF \
    X(0.1879, 1.28, 1.188) \
    X(0.1916, 1.32, 1.203) \
    X(0.1953, 1.34, 1.226) \
    X(0.1993, 1.33, 1.251) \
    X(0.2033, 1.33, 1.277) \
    X(0.2073, 1.30, 1.304) \
    X(0.2119, 1.30, 1.350) \
    X(0.2164, 1.30, 1.387) \
    X(0.2214, 1.30, 1.427) \
    X(0.2262, 1.31, 1.460) \
    X(0.2313, 1.30, 1.497) \
    X(0.2371, 1.32, 1.536) \
    X(0.2426, 1.32, 1.577) \
    X(0.2490, 1.33, 1.631) \
    X(0.2551, 1.33, 1.688) \
    X(0.2616, 1.35, 1.749) \
    X(0.2689, 1.38, 1.803) \
    X(0.2761, 1.43, 1.847) \
    X(0.2844, 1.47, 1.869) \
    X(0.2924, 1.49, 1.878) \
    X(0.3009, 1.53, 1.889) \
    X(0.3107, 1.53, 1.893) \
    X(0.3204, 1.54, 1.898) \
    X(0.3315, 1.48, 1.883) \
    X(0.3425, 1.48, 1.871) \
    X(0.3542, 1.50, 1.866) \
    X(0.3679, 1.48, 1.895) \
    X(0.3815, 1.46, 1.933) \
    X(0.3974, 1.47, 1.952) \
    X(0.4133, 1.46, 1.958) \
    X(0.4305, 1.45, 1.948) \
    X(0.4509, 1.38, 1.914) \
    X(0.4714, 1.31, 1.849) \
    X(0.4959, 1.04, 1.833) \
    X(0.5209, 0.62, 2.081) \
    X(0.5486, 0.43, 2.455) \
    X(0.5821, 0.29, 2.863) \
    X(0.6168, 0.21, 3.272) \
    X(0.6595, 0.14, 3.697) \
    X(0.7045, 0.13, 4.103) \
    X(0.7560, 0.14, 4.542) \
    X(0.8211, 0.16, 5.083) \
    X(0.8920, 0.17, 5.663) \
    X(0.9840, 0.22, 6.350) \
    X(1.0880, 0.27, 7.150) \

#endif // MATERIAL_GOLD_H
