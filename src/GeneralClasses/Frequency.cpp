#include "include/GeneralClasses/Frequency.h"

using namespace Misc;

std::map<Frequency::Unit, double> Frequency::conversionFactorToHertz =
{
#define X(a,b) {a,b},
    FREQUNITS
#undef X
};

Frequency::Frequency(double freq, Unit unit) : freq(convertToHertz(freq, unit))
{

}

double Frequency::convertToHertz(const double freq, const Unit unit) const
{
    return freq * conversionFactorToHertz.at(unit);
}

double Frequency::get(Unit unit) const
{
    return freq / conversionFactorToHertz.at(unit);
}
