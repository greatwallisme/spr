#ifndef PERPENDICULAR_INCIDENCE_H
#define PERPENDICULAR_INCIDENCE_H

#include "Incidence.h"

namespace Incidences
{
class Perpendicular_Incidence : public Incidence
{
public:
    Perpendicular_Incidence(std::shared_ptr<Materials::Material> A,
                            std::shared_ptr<Materials::Material> B,
                            Versor v = Versor::ay);
};
}

#endif // PERPENDICULAR_INCIDENCE_H
