#include "include/Materials/Material_Vacuum.h"

using namespace Materials;

Material_Vacuum::Material_Vacuum() : Material(vacuum)
{

}

complex Material_Vacuum::getRelativePermeability(const Length &) const
{
    return 1.0;
}

complex Material_Vacuum::getRelativePermittivity(const Length &) const
{
    return 1.0;
}

double Material_Vacuum::getRefractiveIndex(const Length &) const
{
    return 1.0;
}

double Material_Vacuum::getExtinctionCoefficient(const Length &) const
{
    return 0.0;
}
