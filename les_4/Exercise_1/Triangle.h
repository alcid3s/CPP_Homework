#pragma once
#include "Shape.h"

class Triangle : public Shape {
public:

	// A constructor with no arguments, creating a triangle with each side set to 1.0
	Triangle();

	// A constructor where you can specify each side.
	Triangle(double side1, double side2, double side3);

	~Triangle();

	// Constant accessor functions for all three data fields
	inline double getSide1() const { return side1; }
	inline double getSide2() const { return side2; }
	inline double getSide3() const { return side3; }

	// A constant function named getArea() that returns the area of the triangle.
	double getArea();

	// A constant function named getPerimeter() that returns the perimeter of the triangle.
	double getPerimeter();

protected:

	// Three double variables named side1, side2 and side3 to denote three sides of the triangle.
	double side1;
	double side2;
	double side3;
};