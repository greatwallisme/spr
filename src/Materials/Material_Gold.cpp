#include "include/Materials/Material_Gold.h"

using namespace Materials;

Material_Gold::Material_Gold() : Material(gold)
{

}

complex Material_Gold::getPermeability(const Length &) const
{
    return 1;
}

complex Material_Gold::getPermittivity(const Length &) const
{
    return 1;
}
