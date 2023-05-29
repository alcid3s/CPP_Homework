#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    Shape();
    Shape(const std::string& color, bool filled);
    std::string getColor() const;
    void setColor(const std::string& color);
    bool isFilled() const;
    void setFilled(bool filled);
    std::string toString() const;

private:
    std::string color;
    bool filled;
};

#endif
