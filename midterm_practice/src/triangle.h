#pragma once

#include "shape.h"
#include "twoDimensionVector.h"
#include "utility.h"
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"

class Triangle: public Shape{
public:
    ~Triangle(){}

    Triangle(TwoDimensionVector vec1, TwoDimensionVector vec2): _vec1(vec1), _vec2(vec2){
        if(vec1.cross(vec2)==0){
            throw std::string("Vectors can't be parallel.");
        }
    }

    // Helon formula
    double area() const override{
        double vec3length = _vec1.subtract(_vec2).length();
        double s = (_vec1.length()+_vec2.length()+vec3length)/2.0;
        return sqrt(s*(s-_vec1.length())*(s-_vec2.length())*(s-vec3length));
    };

    double perimeter() const override{
        return _vec1.length()+_vec2.length()+_vec1.subtract(_vec2).length();
    };

    std::string info() const override{
        return "Triangle (" + decimalpoint(_vec1.x(), 2) +", "+ decimalpoint(_vec1.y(), 2)
                    +") ("+decimalpoint(_vec2.x(), 2)+", "+decimalpoint(_vec2.y(), 2)+")";
    };

    Iterator* createIterator() override{
        return new NullIterator();
    };

    void accept(ShapeVisitor* visitor) override{
        visitor->visitTriangle(this);
    }
private:
    TwoDimensionVector _vec1;
    TwoDimensionVector _vec2;
};