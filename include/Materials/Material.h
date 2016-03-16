#ifndef MATERIAL_H
#define MATERIAL_H

#include "GeneralClasses/Length.h"
#include "GeneralClasses/Frequency.h"
#include "GeneralClasses/Complex.h"
#include <memory>

using namespace Misc;

namespace Materials
{
class Material
{
public:
#define MATERIALS \
    X(gold, Material_Gold) \
    X(vacuum, Material_Vacuum) \
    X(water, Material_Water)

    enum MaterialType
    {
#define X(a,b) a,
        MATERIALS
#undef X
    };

    Material(MaterialType);

    complex getPermittivity(const Length &lambda) const;
    virtual complex getRelativePermittivity(const Length &lambda) const = 0;

    complex getPermeability(const Length &lambda) const;
    virtual complex getRelativePermeability(const Length &lambda) const = 0;

    virtual double getRefractiveIndex(const Length &lambda) const = 0;
    virtual double getExtinctionCoefficient(const Length &lambda) const = 0;

    complex getImpedance(const Length &lambda) const;
    complex getGamma(const Length &lambda) const;

    Frequency getFrequency(const Length &lambda);
    Length getWavelength(const Frequency &freq);

    static std::shared_ptr<Material> createMaterial(MaterialType type);

private:
    MaterialType Type;

};
}

#endif // MATERIAL_H
