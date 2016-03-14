#include "include/Fields/ElectricalField.h"

using namespace Fields;

ElectricalField::ElectricalField(double absValue,
                                 double phase,
                                 Versor direction,
                                 Length &lambda,
                                 complex gamma) : HarmonicField(absValue, phase, direction, lambda, gamma)
{

}
