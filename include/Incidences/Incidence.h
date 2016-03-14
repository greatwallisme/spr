#ifndef INCIDENCE_H
#define INCIDENCE_H

#include "GeneralClasses/Versor.h"
#include "Waves/PlaneWave.h"
#include "Materials/Material.h"

using namespace Misc;

namespace Incidences
{
class Incidence
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

    Incidence(IncidenceType, std::shared_ptr<Materials::Material>,
              std::shared_ptr<Materials::Material>, Versor = Versor::ay);

    virtual Waves::PlaneWave createIndicentPlaneWave(Frequency &, double magn) = 0;
    virtual Waves::PlaneWave getReflectedWave(Waves::PlaneWave indicentWave) = 0;
    virtual Waves::PlaneWave getTransmittedWave(Waves::PlaneWave incidentWave) = 0;

protected:
    IncidenceType type;
    std::shared_ptr<Materials::Material> A;
    std::shared_ptr<Materials::Material> B;
    Versor interfaceVersor;
};
}

#endif // INCIDENCE_H
