#include "include/GeneralClasses/Vector.h"
#include "include/GeneralClasses/Versor.h"
#include <boost/assert.hpp>

Vector::Vector(double x, double y, double z)
{
    vec = {x, y, z};
}

Vector::Vector(const Versor &versor, double abs)
{
    vec = {versor.x() * abs, versor.y() * abs, versor.z() * abs};
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

Vector Vector::operator *(const double k) const
{
    return Vector(k * x(), k * y(), k * z());
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

Vector Vector::operator /(const double k) const
{
    BOOST_ASSERT_MSG(k != 0, "Impossible to divide a vector by zero.");
    return operator *(1.0 / k);
}

bool Vector::isNull() const
{
    return (abs() == 0);
}

Versor Vector::getVersor() const
{
    return Versor(*this);
}
