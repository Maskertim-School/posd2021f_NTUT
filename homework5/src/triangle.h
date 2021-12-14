#pragma once

#include "shape.h"
#include "two_dimensional_vector.h"
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"
#include <math.h>

class Triangle: public Shape{
public:
    ~Triangle(){}

    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2): _vec1(vec1), _vec2(vec2){
        if(vec1.cross(vec2)==0.0){
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
        // return "Triangle ([" + decimalpoint(_vec1.x(), 2) +", "+ decimalpoint(_vec1.y(), 2)
        //             +"] ["+decimalpoint(_vec2.x(), 2)+", "+decimalpoint(_vec2.y(), 2)+"])";
        return "Triangle ("+ _vec1.info() + " " + _vec2.info() + ")";
    };

    Iterator* createIterator() override{
        return new NullIterator();
    };

    void accept(ShapeVisitor* visitor) override{
        visitor->visitTriangle(this);
    }

    /* return string that decimal will be leaved only # of points */
    std::string decimalpoint(double real, int point) const{
        // shift left two points, and double turns into string type
        std::string str_real = std::to_string(round(real*pow(10.0, point)));

        for(unsigned i=0; i<str_real.length(); i++){
            if(str_real.at(i)=='.'){
                str_real.erase(i, str_real.length()-i);
                str_real.insert(str_real.length()-point,".");
                break;
            }
        }

        return str_real;
    }
private:
    TwoDimensionalVector _vec1;
    TwoDimensionalVector _vec2;
};