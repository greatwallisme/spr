#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <map>

namespace Misc
{
class Frequency
{
#define FREQUNITS \
    X(Hz, 1) \
    X(kHz, 1e3) \
    X(MHz, 1e6) \
    X(GHz, 1e9) \
    X(THz, 1e12) \
    X(rad_per_sec, 0.15915494309) \
    X(krad_per_sec, 0.15915494309e3) \
    X(Mrad_per_sec, 0.15915494309e6) \
    X(Grad_per_sec, 0.15915494309e9)

public:
    enum Unit
    {
#define X(a,b) a,
        FREQUNITS
#undef X
    };

    Frequency(double freq, Unit unit);
    double get(Unit unit = Unit::Hz) const;

private:
    double freq;

    static std::map<Unit, double> conversionFactorToHertz;
    double convertToHertz(const double freq, const Unit unit) const;
};
}

#endif // FREQUENCY_H
