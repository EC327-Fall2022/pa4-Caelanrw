#ifndef POINT2D_H
#define POINT2D_H

#include "Vector2D.h"
#include <iostream>
using namespace std;

class Point2D
{
    public:
    double x;
    double y;
    Point2D();
    Point2D(double in_x, double in_y);
};

double GetDistanceBetween(Point2D , Point2D);

ostream& operator << (ostream& input, const Point2D& point);

const Point2D operator+(const Point2D point, const Vector2D vec); 

const Vector2D operator- (const Point2D p1,const Point2D p2);


#endif