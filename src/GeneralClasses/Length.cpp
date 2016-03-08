#include "include/GeneralClasses/Length.h"

std::map<Length::Unit, double> Length::conversionFactorToMeter =
{
#define X(a,b) {a,b},
    LENGTHUNITS
#undef X
};

Length::Length(double length, Unit unit) : length(convertToMeter(length, unit))
{

}

double Length::convertToMeter(const double length, const Unit unit) const
{
    return length * conversionFactorToMeter.at(unit);
}

double Length::get(Unit unit) const
{
    return length / conversionFactorToMeter.at(unit);
}
