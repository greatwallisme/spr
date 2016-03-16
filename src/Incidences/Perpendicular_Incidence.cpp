#include "include/Incidences/Perpendicular_Incidence.h"

using namespace Incidences;

Perpendicular_Incidence::Perpendicular_Incidence(
    std::shared_ptr<Materials::Material> A,
    std::shared_ptr<Materials::Material> B,
    Versor v) : Incidence(perpendicular, A, B, v)
{

}
