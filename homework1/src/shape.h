#pragma once

#include <iostream>

// you don't have to modify this class
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
};
