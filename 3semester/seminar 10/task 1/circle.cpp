#include <iostream>
#include <cmath>

#include "point.h"
#include "point.cpp"
#include "circle.h"


Circle::Circle(const Point& acenter, float aradius):center(acenter),radius(aradius)
{
}


Circle::Circle():center(Point {0, 0}),radius(1.0)
{
}

Point& Circle::getCenter() const
{
    return (Point&)center;
}

float Circle::getRadius() const
{
    return radius;
}

void Circle::setCenter(const Point& acenter)
{
    center = acenter;
}

void Circle::setRadius(float aradius)
{   
    if (aradius <= 0)
        radius = 0;
    else
        radius = aradius;
}

float Circle::getArea() const
{
    return M_PI * radius * radius;
}

float Circle::getDistance(const Point& p) const
{
    float dist = center.distance(p);
    return dist - radius;
}

bool Circle::isColliding(const Circle& c) const
{
    float dist = center.distance(c.center);
    float doubleradius = radius + c.radius;

    if (dist - doubleradius > 0)
        return true;
    else
        return false;
}

void Circle::move(const Point& p)
{
    center = center + p; 
}

