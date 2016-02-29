#include "Materials/Material.h"
#include "GeneralClasses/PhysicalConstants.h"
#include "include/Materials.h"

using namespace Materials;

Material::Material(MaterialType Type) : Type(Type)
{

}

complex Material::getRelativePermeability(const Length &lambda) const
{
    return getPermeability(lambda) / PhysicalConstants::mu0;
}

complex Material::getRelativePermittivity(const Length &lambda) const
{
    return getPermittivity(lambda) / PhysicalConstants::epsilon0;
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
