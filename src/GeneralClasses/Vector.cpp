#include "include/GeneralClasses/Vector.h"

Vector::Vector(double x, double y, double z)
{
    vec = {x, y, z};
}

double Vector::x() const
{
    return vec[0];
}

double Vector::y() const
{
    return vec[1];
}

double Vector::z() const
{
    return vec[2];
}

double Vector::abs() const
{
    return std::sqrt(operator %(*this));
}

Vector Vector::operator +(const Vector &other) const
{
    return Vector(x() + other.x(), y() + other.y(), z() + other.z());
}

Vector Vector::operator -() const
{
    return Vector(-x(), -y(), -z());
}

Vector Vector::operator -(const Vector &other) const
{
    return operator +(-other);
}

Vector Vector::operator *(const Vector &other) const
{
    return Vector(y() * other.z() - z() * other.y(),
                  z() * other.x() - x() * other.z(),
                  x() * other.y() - y() * other.z());
}

double Vector::operator %(const Vector &other) const
{
    return (x() * other.x()) + (y() * other.y()) + (z() * other.z());
}
