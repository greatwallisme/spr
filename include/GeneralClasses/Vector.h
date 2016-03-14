#ifndef VECTOR_H
#define VECTOR_H

#include <armadillo>

namespace Misc
{
class Versor;

class Vector
{
public:
    Vector(double x, double y, double z);
    Vector(const Versor &versor, double abs);

    double x() const;
    double y() const;
    double z() const;

    double abs() const;

    Versor getVersor() const;

    Vector operator+(const Vector&) const;
    Vector operator-() const;
    Vector operator-(const Vector&) const;
    Vector operator*(const double) const; //Scalar Product
    Vector operator*(const Vector&) const; //Vectorial Product
    double operator%(const Vector&) const; //Dot Product
    Vector operator/(const double) const;

    bool isNull() const;

private:
    arma::rowvec vec;
};
}

#endif // VECTOR_H
