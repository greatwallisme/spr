#ifndef VERSOR_H
#define VERSOR_H

#include "Vector.h"

class Versor : public Vector
{
public:
    Versor(double x, double y, double z);
    Versor(const Vector &vec);

    //Versors
    static Versor ax;
    static Versor ay;
    static Versor az;
};

#endif // VERSOR_H
