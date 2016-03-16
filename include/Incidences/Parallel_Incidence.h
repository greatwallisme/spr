#ifndef PARALLEL_INCIDENCE_H
#define PARALLEL_INCIDENCE_H

#include "Incidence.h"

namespace Incidences
{
class Parallel_Incidence : public Incidence
{
public:
    Parallel_Incidence(std::shared_ptr<Materials::Material> A,
                       std::shared_ptr<Materials::Material> B,
                       Versor v = Versor::ay);
};
}

#endif // PARALLEL_INCIDENCE_H
