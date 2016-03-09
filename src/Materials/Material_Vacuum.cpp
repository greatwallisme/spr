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
