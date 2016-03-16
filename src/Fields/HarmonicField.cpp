#include "include/Fields/HarmonicField.h"

using namespace Fields;

HarmonicField::HarmonicField(complex magnitude,
                             Versor direction,
                             Frequency &freq,
                             complex gamma) :
    magnitude(magnitude), direction(direction.getVersor()), freq(freq), gamma(gamma)
{

}

Vector HarmonicField::getField(double x, double y, double z, double t)
{
    double len = Vector(x, y, z) % direction;
    auto j = complex(0, 1);

    return direction * std::real(magnitude * std::exp(j * gamma * len + j *
                                 freq.get(Frequency::rad_per_sec) * t));
}

Versor HarmonicField::getDirection() const
{
    return direction;
}

double HarmonicField::getMagnitude() const
{
    return std::abs(magnitude);
}
