#ifndef ELECTRICALFIELD_H
#define ELECTRICALFIELD_H

#include "HarmonicField.h"

namespace Fields
{
class ElectricalField : public HarmonicField
{
public:
    ElectricalField(double absValue,
                    double phase,
                    Versor direction,
                    Length &lambda,
                    complex gamma);
};
}

#endif // ELECTRICALFIELD_H