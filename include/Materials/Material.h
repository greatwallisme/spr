#ifndef MATERIAL_H
#define MATERIAL_H

#include "GeneralClasses/Length.h"
#include "GeneralClasses/Complex.h"

class Material
{
public:
    Material();

    virtual complex getPermittivity(const Length &lambda) const = 0;
    complex getRelativePermittivity(const Length &lambda) const;

    virtual complex getPermeability(const Length &lambda) const = 0;
    complex getRelativePermeability(const Length &lambda) const;
};

#endif // MATERIAL_H
