#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
using namespace std;

class Vector2D
{
    public:
    double x;
    double y;
    Vector2D();
    Vector2D(double,double);
};

const Vector2D operator* (const Vector2D v1,const double d);

const Vector2D operator/(const Vector2D v1, const double d);

ostream& operator << (ostream& output, const Vector2D& vec);


#endif