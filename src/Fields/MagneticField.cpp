#include "include/Fields/MagneticField.h"

using namespace Fields;

MagneticField::MagneticField(complex magnitude,
                             Versor direction,
                             const Frequency &freq,
                             complex gamma) : HarmonicField(magnitude, direction, freq, gamma)
{

}
