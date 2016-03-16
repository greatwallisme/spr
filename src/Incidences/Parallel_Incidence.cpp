#include "include/Incidences/Parallel_Incidence.h"

using namespace Interfaces;

Parallel_Incidence::Parallel_Incidence(std::shared_ptr<Materials::Material> A,
                                       std::shared_ptr<Materials::Material> B,
                                       Versor v) : Interface(parallel, A, B, v)
{

}

Waves::PlaneWave Parallel_Incidence::createIncidentWave
(Frequency &freq, Versor &k, double magn)
{
    auto lambda = A->getWavelength(freq);
    auto impedance = A->getImpedance(lambda);

    Versor aH = interfaceVersor * k;
    Versor aE = - k * aH;

    auto elecField = std::make_shared<Fields::ElectricalField>
                     (magn, aE, freq, A->getGamma(lambda));
    auto magnField = std::make_shared<Fields::MagneticField>
                     (magn / impedance, aH, freq, A->getGamma(lambda));

    return Waves::PlaneWave(freq, A, elecField, magnField);
}
