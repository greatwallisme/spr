#include "include/Fields/MagneticField.h"

using namespace Fields;

MagneticField::MagneticField(double absValue,
                             double phase,
                             Versor direction,
                             Frequency &freq,
                             complex gamma) : HarmonicField(absValue, phase, direction, freq, gamma)
{

}
