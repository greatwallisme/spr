#ifndef PERPENDICULAR_INCIDENCE_H
#define PERPENDICULAR_INCIDENCE_H

#include "Interface.h"

namespace Interfaces
{
class Perpendicular_Incidence : public Interface
{
public:
    Perpendicular_Incidence(std::shared_ptr<Materials::Material> A,
                            std::shared_ptr<Materials::Material> B,
                            Versor v = Versor::ay);
};
}

#endif // PERPENDICULAR_INCIDENCE_H
