#include "include/Fields/HarmonicField.h"

using namespace Fields;

HarmonicField::HarmonicField(double magnitude,
                             double phase,
                             Versor direction,
                             Frequency &freq,
                             complex gamma) :
    magnitude(magnitude), phase(phase), direction(direction.getVersor()),
    freq(freq), gamma(gamma)
{

}

Vector HarmonicField::getField(double x, double y, double z, double t)
{
    double len = Vector(x, y, z) % direction;
    auto j = complex(0, 1);

    return direction * std::real(magnitude * std::exp(j * gamma * len +
                                 j * freq.get(Frequency::rad_per_sec) * t + j * phase));
}

Versor HarmonicField::getDirection() const
{
    return direction;
}

double HarmonicField::getMagnitude() const
{
    return magnitude;
}
