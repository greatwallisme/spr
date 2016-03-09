#ifndef HARMONICFIELD_H
#define HARMONICFIELD_H

#include "GeneralClasses/Length.h"
#include "GeneralClasses/Complex.h"
#include "GeneralClasses/Vector.h"

namespace Fields
{
class HarmonicField
{
public:
    HarmonicField(double absValue,
                  double phase,
                  Vector direction,
                  Length &lambda,
                  complex gamma);

    Vector getField(double x, double y, double z = 0);

protected:
    double absValue;
    double phase;
    Vector direction;
    Length lambda;
    complex gamma;
};
}

#endif // HARMONICFIELD_H
