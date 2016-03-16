#include "include/Incidences/Perpendicular_Incidence.h"

using namespace Interfaces;

Perpendicular_Incidence::Perpendicular_Incidence(
    std::shared_ptr<Materials::Material> A,
    std::shared_ptr<Materials::Material> B,
    Versor v) : Interface(perpendicular, A, B, v)
{

}
