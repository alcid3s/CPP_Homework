#include "Shape.h"
using namespace std;

Shape::Shape() :
    color("white"), filled(false) {
}

Shape::Shape(const std::string& color, bool filled) :
    color(color), filled(filled) {
}

std::string Shape::getColor() const {
    return color;
}

void Shape::setColor(const std::string& color) {
    this->color = color;
}

bool Shape::isFilled() const {
    return filled;
}

void Shape::setFilled(bool filled) {
    this->filled = filled;
}

std::string Shape::toString() const {
    return "Shape";
}
