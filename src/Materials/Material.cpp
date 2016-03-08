#include "Materials/Material.h"
#include "GeneralClasses/PhysicalConstants.h"
#include "include/Materials.h"

using namespace Materials;

Material::Material(MaterialType Type) : Type(Type)
{

}

complex Material::getPermeability(const Length &lambda) const
{
    return getRelativePermeability(lambda) * PhysicalConstants::mu0;
}

complex Material::getPermittivity(const Length &lambda) const
{
    return getRelativePermittivity(lambda) * PhysicalConstants::epsilon0;
}

std::shared_ptr<Material> Material::createMaterial(MaterialType type)
{
    std::shared_ptr<Material> material;

    switch (type)
        {
#define X(a,b) case a: material = std::make_shared<b>(); break;
            MATERIALS
#undef X
        }

    return material;
}
