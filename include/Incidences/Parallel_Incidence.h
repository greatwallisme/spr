#ifndef PARALLEL_INCIDENCE_H
#define PARALLEL_INCIDENCE_H

#include "Interface.h"

namespace Interfaces
{
class Parallel_Incidence : public Interface
{
public:
    Parallel_Incidence(std::shared_ptr<Materials::Material> A,
                       std::shared_ptr<Materials::Material> B,
                       Versor v = Versor::ay);

    Waves::PlaneWave createIncidentWave(Frequency &freq, Versor &k, double magn);
    Waves::PlaneWave getReflectedWave(const Waves::PlaneWave &incidentWave);
};
}

#endif // PARALLEL_INCIDENCE_H
