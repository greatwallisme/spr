#include "include/Waves/PlaneWave.h"

using namespace Waves;

PlaneWave::PlaneWave
(const Frequency &freq, std::shared_ptr<Materials::Material> material,
 std::shared_ptr<Fields::ElectricalField> elecField,
 std::shared_ptr<Fields::MagneticField> magnField) :
    magnitude(elecField->getMagnitude()),
    direction(elecField->getDirection() * magnField->getDirection()),
    freq(freq),
    material(material),
    elecField(elecField),
    magnField(magnField)
{

}
