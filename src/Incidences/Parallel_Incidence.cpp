#include "include/Incidences/Parallel_Incidence.h"

using namespace Incidences;

Parallel_Incidence::Parallel_Incidence(std::shared_ptr<Materials::Material> A,
                                       std::shared_ptr<Materials::Material> B,
                                       Versor v) : Incidence(parallel, A, B, v)
{

}
