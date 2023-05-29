#include "Triangle.h"
#include <cmath>

// A constructor with no arguments, creating a triangle with each side set to 1.0
Triangle::Triangle() : side1(1.0), side2(1.0), side3(1.0)
{

}

// A constructor where you can specify each side.
Triangle::Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3)
{

}

Triangle::~Triangle()
{
}

// A constant function named getArea() that returns the area of the triangle.
double Triangle::getArea()
{
	double s = (side1 + side2 + side3) / 2.0;
	return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

// A constant function named getPerimeter() that returns the perimeter of the triangle.
double Triangle::getPerimeter()
{
	return side1 + side2 + side3;
}
