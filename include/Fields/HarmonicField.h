#ifndef HARMONICFIELD_H
#define HARMONICFIELD_H

#include "GeneralClasses/Frequency.h"
#include "GeneralClasses/Complex.h"
#include "GeneralClasses/Versor.h"

using namespace Misc;

namespace Fields
{
class HarmonicField
{
public:
    HarmonicField(complex magnitude,
                  Versor direction,
                  Frequency &freq,
                  complex gamma);

    Vector getField(double x, double y, double z = 0, double t = 0);
    Versor getDirection() const;
    double getMagnitude() const;

protected:
    complex magnitude;
    Versor direction;
    Frequency freq;
    complex gamma;
};
}

#endif // HARMONICFIELD_H
