#include "include/Fields/MagneticField.h"

using namespace Fields;

MagneticField::MagneticField(complex magnitude,
                             Versor direction,
                             Frequency &freq,
                             complex gamma) : HarmonicField(magnitude, direction, freq, gamma)
{

}
