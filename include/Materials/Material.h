#ifndef MATERIAL_H
#define MATERIAL_H

#include "GeneralClasses/Length.h"

class Material
{
public:
    Material();
    virtual double getPermittivity(Length lambda) = 0;
    virtual double getPermeability(Length lambda) = 0;
};

#endif // MATERIAL_H
