#pragma once
#include "shape.h"
#include "string"
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include "two_dimensional_vector.h"

class Triangle: public Shape {
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2): _vec1(vec1),_vec2(vec2) {
        // this is not allowed that two vectors are parallel  
        if(vec1.cross(vec2)==0){
            throw std::string ("The parallel of two vectors don't form a triangle.");
        }
    }

    // calculate area of triangle using Helon formula
    double area() const override { 
        // Helon formula
        double vec3length = _vec1.subtract(_vec2).length();
        double s = (_vec1.length()+_vec2.length()+vec3length)/2.0;
        return sqrt(s*(s-_vec1.length())*(s-_vec2.length())*(s-vec3length));
    }

    // calculate perimeter of triangle
    double perimeter() const override { 
        return _vec1.length()+_vec2.length()+_vec1.subtract(_vec2).length();
    }

    // show triangle information
    std::string info() const override { 
        return "Triangle ("+_vec1.info()+" "+_vec2.info()+")";
    }

    Iterator* createIterator() override { 
        return new NullIterator();
    }
private:
    TwoDimensionalVector _vec1;
    TwoDimensionalVector _vec2;
};
