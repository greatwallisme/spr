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

    double abs() const;

    Vector getVersor() const;

    Vector operator+(const Vector&) const;
    Vector operator-() const;
    Vector operator-(const Vector&) const;
    Vector operator*(const double) const; //Scalar Product
    Vector operator*(const Vector&) const; //Vectorial Product
    double operator%(const Vector&) const; //Dot Product
    Vector operator/(const double) const;

    bool isNull() const;

    //Versors
    static Vector ax;
    static Vector ay;
    static Vector az;

private:
    arma::rowvec vec;
};

#endif // VECTOR_H
