#include "Triangle.h"
#include <iostream>

int main() {
    Triangle triangle1; 
    std::cout << "Triangle 1:\n";
    std::cout << "Side 1: " << triangle1.getSide1() << "\n";
    std::cout << "Side 2: " << triangle1.getSide2() << "\n";
    std::cout << "Side 3: " << triangle1.getSide3() << "\n";
    std::cout << "Area: " << triangle1.getArea() << "\n";
    std::cout << "Perimeter: " << triangle1.getPerimeter() << "\n";

    Triangle triangle2(4.0, 3.0, 5.0);
    std::cout << "\nTriangle 2:" << "\n";
    std::cout << "Side 1: " << triangle2.getSide1() << "\n";
    std::cout << "Side 2: " << triangle2.getSide2() << "\n";
    std::cout << "Side 3: " << triangle2.getSide3() << "\n";;
    std::cout << "Area: " << triangle2.getArea() << "\n";
    std::cout << "Perimeter: " << triangle2.getPerimeter() << "\n";

    return 0;
}
