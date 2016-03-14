#include "include/Fields/MagneticField.h"

using namespace Fields;

MagneticField::MagneticField(double absValue,
                             double phase,
                             Versor direction,
                             Length &lambda,
                             complex gamma) : HarmonicField(absValue, phase, direction, lambda, gamma)
{

}
