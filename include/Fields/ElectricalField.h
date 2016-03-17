#ifndef ELECTRICALFIELD_H
#define ELECTRICALFIELD_H

#include "HarmonicField.h"

namespace Fields
{
class ElectricalField : public HarmonicField
{
public:
    ElectricalField(complex magnitude,
                    Versor direction,
                    const Frequency &freq,
                    complex gamma);
};
}

#endif // ELECTRICALFIELD_H
