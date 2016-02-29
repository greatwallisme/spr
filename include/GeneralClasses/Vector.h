#ifndef VECTOR_H
#define VECTOR_H

#include <armadillo>

class Vector
{
public:
    Vector(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

    Vector operator+(const Vector&) const;
    Vector operator-() const;
    Vector operator-(const Vector&) const;

    Vector operator*(const Vector&) const; //Vectorial Product
    double operator%(const Vector&) const; //Dot Product

private:
    arma::rowvec vec;
};

#endif // VECTOR_H
