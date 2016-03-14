#include "include/Incidences/Incidence.h"

using namespace Incidences;

Incidence::Incidence(IncidenceType type,
                     std::shared_ptr<Materials::Material> A,
                     std::shared_ptr<Materials::Material> B,
                     Versor interfaceVersor) :
    type(type), A(A), B(B), interfaceVersor(interfaceVersor)
{

}
