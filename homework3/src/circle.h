#pragma once
#include "shape.h"
#include "string"
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include <cmath>

class Circle : public Shape {
public:
    Circle(double radius): _radius(radius) {
        // Radius don't allow negative.
        if(radius<=0){
            throw std::string("The negative or zero radius isn't allowed.");
        }
    }

    // the calculation is radius*radius*PI
    double area() const override { 
        return _radius*_radius*M_PI;
    }

    // the calculation is radius*2*PI
    double perimeter() const override { 
        return _radius*2*M_PI;
    }

    std::string info() const override { 
        double round_radius = round(_radius*100.0)/100.0;
        std::string strradius = std::to_string(round_radius);
        decimalplace(strradius, 2);
        return "Circle ("+strradius+")";
    }

    Iterator* createIterator() override { 
        return new NullIterator();
    }
private:
    double _radius;
};