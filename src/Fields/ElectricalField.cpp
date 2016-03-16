#include "include/Fields/ElectricalField.h"

using namespace Fields;

ElectricalField::ElectricalField(complex magnitude,
                                 Versor direction,
                                 Frequency &freq,
                                 complex gamma) : HarmonicField(magnitude, direction, freq, gamma)
{

}
