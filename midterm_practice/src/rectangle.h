#pragma once

#include "shape.h"
#include "utility.h"
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"

class Rectangle: public Shape{
public:
    ~Rectangle(){}

    Rectangle(double width, double length): _width(width), _length(length){
        if(width <= 0 || length <= 0){
            throw std::string("Width or length can't be negative or zero.");
        }
    };

    double area() const override{
        return _width*_length;
    };

    double perimeter() const override{
        return (_width+_length)*2;
    };

    std::string info() const override{
        return "Rectangle ("+decimalpoint(_width, 2)+", "
                    +decimalpoint(_length, 2)+")";
    };

    Iterator* createIterator() override{
        return new NullIterator();
    };

    void accept(ShapeVisitor* visitor) override{
        visitor->visitRectangle(this);
    }
private:
    double _width;
    double _length;
};