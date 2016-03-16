#include "include/Incidences/Interface.h"
#include "include/Incidences.h"

using namespace Interfaces;

Interface::Interface(IncidenceType type,
                     std::shared_ptr<Materials::Material> A,
                     std::shared_ptr<Materials::Material> B,
                     Versor interfaceVersor) :
    type(type), A(A), B(B), interfaceVersor(interfaceVersor)
{

}

std::shared_ptr<Interface> Interface::createIncidence(
    IncidenceType type,
    std::shared_ptr<Materials::Material> A,
    std::shared_ptr<Materials::Material> B,
    Versor v)
{
    std::shared_ptr<Interface> incidence;

    switch (type)
        {
        case parallel:
            //incidence = std::make_shared<Parallel_Incidence>(A, B, v);
            break;

        case perpendicular:
            //incidence = std::make_shared<Perpendicular_Incidence>(A, B, v);
            break;
        }

    return incidence;
}

std::shared_ptr<Interface> Interface::reverseInterface()
{
    return createIncidence(type, B, A, interfaceVersor);
}
