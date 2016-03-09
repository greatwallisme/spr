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

complex Material::getImpedance(const Length &lambda) const
{
    double omega = PhysicalConstants::c / lambda.get();
    double epsilon = std::real(getPermittivity(lambda));
    double sigma = (-omega) * std::imag(getPermittivity(lambda));
    complex mu = getPermeability(lambda);
    complex j = complex(0, 1);

    return std::sqrt((j * omega * mu) / (sigma + j * omega * epsilon));
}
