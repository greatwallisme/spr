#include "include/Incidences/Parallel_Incidence.h"

using namespace Interfaces;
using namespace Waves;

Parallel_Incidence::Parallel_Incidence(std::shared_ptr<Materials::Material> A,
                                       std::shared_ptr<Materials::Material> B,
                                       Versor v) : Interface(parallel, A, B, v)
{

}

PlaneWave Parallel_Incidence::createIncidentWave
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

    return PlaneWave(freq, A, elecField, magnField);
}

PlaneWave Parallel_Incidence::getReflectedWave(const PlaneWave &incidentWave)
{
    auto lambdaA = A->getWavelength(incidentWave.freq);
    auto lambdaB = B->getWavelength(incidentWave.freq);

    //Finds the direction of the reflected wave by reflecting the incident Vector
    //around the interface versor.
    Vector incidentVector = incidentWave.direction;
    double parallelComponent = incidentVector % interfaceVersor;
    Vector perpComponent = incidentVector - interfaceVersor * parallelComponent;
    Versor k = (interfaceVersor * parallelComponent - perpComponent).getVersor();

    //Calculates the directions of the E and H fields of the reflected wave
    Versor aH = interfaceVersor * k;
    Versor aE = - k * aH;

    double thetaIncide = std::acos(interfaceVersor % incidentWave.direction);
    double thetaTransm = std::asin(A->getRefractiveIndex(lambdaA) *
                                   std::sin(thetaIncide) /
                                   B->getRefractiveIndex(lambdaB)); //Snell Law

    auto impedanceA = A->getImpedance(lambdaA);
    auto impedanceB = B->getImpedance(lambdaB);

    //Computes the reflection coefficient
    complex reflecCoefficient =
        (impedanceB * std::cos(thetaTransm) - impedanceA * std::cos(thetaIncide))
        / (impedanceB * std::cos(thetaTransm) + impedanceA * std::cos(thetaIncide));

    //Calculates the E and H fields for the reflected wave.
    auto elecField = std::make_shared<Fields::ElectricalField>
                     (reflecCoefficient * incidentWave.magnitude, aE,
                      incidentWave.freq, A->getGamma(lambdaA));
    auto magnField = std::make_shared<Fields::MagneticField>
                     (reflecCoefficient * incidentWave.magnitude / impedanceA, aH,
                      incidentWave.freq, A->getGamma(lambdaA));

    return PlaneWave(incidentWave.freq, A, elecField, magnField);
}
