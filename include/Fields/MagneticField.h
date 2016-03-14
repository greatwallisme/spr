#ifndef MAGNETICFIELD_H
#define MAGNETICFIELD_H

#include "HarmonicField.h"

namespace Fields
{
class MagneticField : public HarmonicField
{
public:
    MagneticField(double absValue,
                  double phase,
                  Versor direction,
                  Frequency &freq,
                  complex gamma);
};
}

#endif // MAGNETICFIELD_H
