#pragma once

#include "shape.h"
#include <string>
#include <cmath>
#include "utility.h"
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"

class Circle: public Shape{
public:
    ~Circle(){};

    Circle(double radius): _radius(radius){
        if(radius <= 0.0){
            throw std::string("Radius can't be negative and zero.");
        }
    };

    double area() const override{
        return _radius*_radius*M_PI;
    };
    
    double perimeter() const override{
        return _radius*2*M_PI;
    };

    std::string info() const override{
        return "Circle ("+ decimalpoint(_radius, 2) +")";
    };

    Iterator* createIterator() override{
        return new NullIterator();
    };

    void accept(ShapeVisitor* visitor) override{
        visitor->visitCircle(this);
    }
private:
    double _radius;
};