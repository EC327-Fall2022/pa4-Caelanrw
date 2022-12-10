#include "Point2D.h"
#include <cmath>

#include <iostream>
using namespace std;

Point2D::Point2D()
{
    x=0.0;
    y=0.0;
}

Point2D::Point2D(double in_x, double in_y)
{
    x=in_x;
    y=in_y;
}


double GetDistanceBetween(Point2D p1, Point2D p2)  //finds distance between points
{
    double distance,xdiff,ydiff;
    xdiff=p2.x-p1.x;
    ydiff=p2.y - p1.y;
    distance=sqrt(pow(xdiff,2)+pow(ydiff,2));
    return distance;
}

ostream& operator << (ostream& output, const Point2D& point)
{
    output<<"("<<point.x<<","<<point.y<<")"<<endl;
    return output;
}

const Point2D operator+(const Point2D point, const Vector2D vec)
{
    double newX= point.x+vec.x;
    double newY= point.y+vec.y;
    Point2D result(newX,newY);
    return result;
}

const Vector2D operator- (const Point2D p1,const Point2D p2)
{
    double newX=p1.x-p2.x;
    double newY=p1.y-p2.y;
    Vector2D result(newX,newY);
    return result;
}
