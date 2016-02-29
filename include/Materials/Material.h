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

    virtual complex getPermittivity(const Length &lambda) const = 0;
    complex getRelativePermittivity(const Length &lambda) const;

    virtual complex getPermeability(const Length &lambda) const = 0;
    complex getRelativePermeability(const Length &lambda) const;

    static std::shared_ptr<Material> createMaterial(MaterialType type);

private:
    MaterialType Type;

};
}

#endif // MATERIAL_H
