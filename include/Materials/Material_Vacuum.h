#ifndef MATERIAL_VACUUM_H
#define MATERIAL_VACUUM_H

#include "Material.h"

namespace Materials
{
class Material_Vacuum : public Material
{
public:
    Material_Vacuum();
    complex getRelativePermeability(const Length &lambda) const;
    complex getRelativePermittivity(const Length &lambda) const;
};
}

#endif // MATERIAL_VACUUM_H
