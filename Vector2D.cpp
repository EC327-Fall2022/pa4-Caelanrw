#include "Vector2D.h"

#include <iostream>
using namespace std;

Vector2D:: Vector2D()
{
    x=0.0;
    y=0.0;
}

Vector2D:: Vector2D(double in_x,double in_y)
{
    x=in_x;
    y=in_y;
}

const Vector2D operator* (const Vector2D v1, const double d)  //overload * operator
{
    double newX= v1.x*d;
    double newY= v1.y*d;
    Vector2D result(newX,newY);
    return result;
}

const Vector2D operator/ (const Vector2D v1, const double d)  //overload / operator
{
    if (d==0)
    {
        return v1;
    }
    double newX= v1.x/d;
    double newY= v1.y/d;
    Vector2D result(newX,newY);
    return result;
}

ostream& operator << (ostream& output, const Vector2D& vec)  //overload << operator
{
    output<<"("<<vec.x<<","<<vec.y<<")"<<endl;
    return output;
}

