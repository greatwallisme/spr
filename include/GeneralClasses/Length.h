#ifndef LENGTH_H
#define LENGTH_H

#include <map>

class Length
{
public:
#define LENGTHUNITS \
    X(meter, 1) \
    X(millimeter, 1e-3) \
    X(micrometer, 1e-6) \
    X(nanometer, 1e-9) //X(unitName, conversion factor to meter).

    enum Unit
    {
#define X(a,b) a,
        LENGTHUNITS
#undef X
    };

    Length(double length, Unit unit);
    double getLength(Unit unit = Unit::meter);

private:
    double length;

    static std::map<Unit, double> conversionFactorToMeter;
    double convertToMeter(const double length, const Unit unit) const;
};

#endif // LENGTH_H
