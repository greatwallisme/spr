#include "include/Fields/ElectricalField.h"

using namespace Fields;

ElectricalField::ElectricalField(double absValue,
                                 double phase,
                                 Versor direction,
                                 Frequency &freq,
                                 complex gamma) : HarmonicField(absValue, phase, direction, freq, gamma)
{

}
