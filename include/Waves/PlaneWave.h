#ifndef PLANEWAVE_H
#define PLANEWAVE_H

#include "GeneralClasses/Versor.h"
#include "GeneralClasses/Frequency.h"
#include "Fields/ElectricalField.h"
#include "Fields/MagneticField.h"
#include "Materials/Material.h"
#include <memory>

using namespace Misc;

namespace Waves
{
class PlaneWave
{
public:
    PlaneWave(const Frequency &freq, std::shared_ptr<Materials::Material> material,
              std::shared_ptr<Fields::ElectricalField> elecField,
              std::shared_ptr<Fields::MagneticField> magnField);

    complex magnitude;
    Versor direction;
    Frequency freq;

private:
    std::shared_ptr<Materials::Material> material;
    std::shared_ptr<Fields::ElectricalField> elecField;
    std::shared_ptr<Fields::MagneticField> magnField;
};
}

#endif // PLANEWAVE_H
