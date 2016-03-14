#include "include/Materials/Material_Gold.h"
#include "include/GeneralClasses/Length.h"
#include "include/GeneralClasses/PhysicalConstants.h"

using namespace Materials;

Material_Gold::Material_Gold() : Material(gold)
{
    std::set<Interpolation::InterpolationMethod::knownPoint> refIndexPoints;
#define X(a,b,c) refIndexPoints.insert({Length(a,Length::micrometer).get(), b});
    GOLD_LAMBDAum_REFINDEX_EXTCOEFF
#undef X
    refractiveIndex.setValues(refIndexPoints);

    std::set<Interpolation::InterpolationMethod::knownPoint> extCoeffPoints;
#define X(a,b,c) extCoeffPoints.insert({Length(a,Length::micrometer).get(), c});
    GOLD_LAMBDAum_REFINDEX_EXTCOEFF
#undef X
#undef GOLD_LAMBDAum_REFINDEX_EXTCOEFF
    extinctionCoefficient.setValues(extCoeffPoints);
}

complex Material_Gold::getRelativePermeability(const Length &) const
{
    return 1;
}

complex Material_Gold::getRelativePermittivity(const Length &lambda) const
{
    double n = getRefractiveIndex(lambda);
    double k = getExtinctionCoefficient(lambda);

    return complex(n * n - k * k, -2 * n * k);
}

double Material_Gold::getRefractiveIndex(const Length &lambda) const
{
    return refractiveIndex.interpolate(lambda.get());
}

double Material_Gold::getExtinctionCoefficient(const Length &lambda) const
{
    return extinctionCoefficient.interpolate(lambda.get());
}
