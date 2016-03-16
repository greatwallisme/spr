#include "include/GeneralClasses/Versor.h"

using namespace Misc;

Versor Versor::ax(1, 0, 0);
Versor Versor::ay(0, 1, 0);
Versor Versor::az(0, 0, 1);

Versor::Versor(double x, double y, double z) :
    Vector(Vector(x, y, z) / Vector(x, y, z).abs())
{

}

Versor::Versor(const Vector &vec) : Vector(vec.getVersor())
{

}

Versor Versor::operator +(const Versor &v) const
{
    return (*this + v).getVersor();
}

Versor Versor::operator -() const
{
    return (-*this).getVersor();
}

Versor Versor::operator -(const Versor &v) const
{
    return (*this - v).getVersor();
}

Versor Versor::operator *(const Versor &v) const
{
    return ((*this) * v).getVersor();
}

Vector Versor::operator *(const double mag) const
{
    return Vector(*this, mag);
}
