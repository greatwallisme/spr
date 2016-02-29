#ifndef MATERIAL_GOLD_H
#define MATERIAL_GOLD_H

#include "Material.h"

namespace Materials
{
class Material_Gold : public Material
{
public:
    Material_Gold();

    complex getPermittivity(const Length &lambda) const;
    complex getPermeability(const Length &lambda) const;
};
}

#endif // MATERIAL_GOLD_H
