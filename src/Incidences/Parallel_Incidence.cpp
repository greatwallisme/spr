#include "include/Incidences/Parallel_Incidence.h"

using namespace Interfaces;

Parallel_Incidence::Parallel_Incidence(std::shared_ptr<Materials::Material> A,
                                       std::shared_ptr<Materials::Material> B,
                                       Versor v) : Interface(parallel, A, B, v)
{

}

Waves::PlaneWave Parallel_Incidence::createIncidentWave
(Frequency &freq, Versor &dir, double magn)
{

}
