#ifndef MAGNETICFIELD_H
#define MAGNETICFIELD_H

#include "HarmonicField.h"

namespace Fields
{
class MagneticField : public HarmonicField
{
public:
    MagneticField(complex magnitude,
                  Versor direction,
                  const Frequency &freq,
                  complex gamma);
};
}

#endif // MAGNETICFIELD_H
