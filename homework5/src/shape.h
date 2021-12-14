#pragma once

#include <string>
#include "visitor/shape_visitor.h"

class Iterator;

class Shape {
public:
    virtual ~Shape() {}
    
    Shape() {}

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    virtual Iterator* createIterator() = 0;

    virtual void addShape(Shape* shape){
        throw std::string("can't add shape");
    }

    virtual void deleteShape(Shape* shape){
        throw std::string("can't delete shape");
    }

    virtual void accept(ShapeVisitor* visitor) = 0;
};