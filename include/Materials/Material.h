#ifndef MATERIAL_H
#define MATERIAL_H

#include "GeneralClasses/Length.h"
#include "GeneralClasses/Complex.h"
#include <memory>

namespace Materials
{
class Material
{
public:
#define MATERIALS \
    X(gold, Material_Gold)

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

    static std::shared_ptr<Material> createMaterial(MaterialType type);

private:
    MaterialType Type;

};
}

#endif // MATERIAL_H
