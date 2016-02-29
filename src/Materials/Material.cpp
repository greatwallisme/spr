#include "Materials/Material.h"
#include "GeneralClasses/PhysicalConstants.h"

Material::Material()
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
