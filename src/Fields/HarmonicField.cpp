#include "include/Fields/HarmonicField.h"

using namespace Fields;

HarmonicField::HarmonicField(double absValue,
                             double phase,
                             Versor direction,
                             Length &lambda,
                             complex gamma) :
    absValue(absValue), phase(phase), direction(direction.getVersor()),
    lambda(lambda), gamma(gamma)
{

}

Vector HarmonicField::getField(double x, double y, double z)
{
    double len = Vector(x, y, z) % direction;
    auto j = complex(0, 1);

    return direction * std::real(absValue * std::exp(j * gamma * len + j * phase));
}
