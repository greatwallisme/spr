#ifndef INTERFACE_H
#define INTERFACE_H

#include "GeneralClasses/Versor.h"
#include "Waves/PlaneWave.h"
#include "Materials/Material.h"

using namespace Misc;

namespace Interfaces
{
class Interface
{
#define INCIDENCETYPE \
    X(parallel, Parallel_Incidence) \
    X(perpendicular, Perpendicular_Indicence)

public:
    enum IncidenceType
    {
#define X(a,b) a,
        INCIDENCETYPE
#undef X
    };

    Interface(IncidenceType, std::shared_ptr<Materials::Material>,
              std::shared_ptr<Materials::Material>, Versor = Versor::ay);

    virtual Waves::PlaneWave createIncidentWave(Frequency &, Versor &, double) = 0;
    virtual Waves::PlaneWave getReflectedWave(Waves::PlaneWave indicentWave) = 0;
    virtual Waves::PlaneWave getTransmittedWave(Waves::PlaneWave incidentWave) = 0;

    std::shared_ptr<Interface> reverseInterface();

    static std::shared_ptr<Interface> createIncidence(IncidenceType,
            std::shared_ptr<Materials::Material>,
            std::shared_ptr<Materials::Material>,
            Versor = Versor::ay);

protected:
    IncidenceType type;
    std::shared_ptr<Materials::Material> A;
    std::shared_ptr<Materials::Material> B;
    Versor interfaceVersor;
};
}

#endif // INTERFACE_H
