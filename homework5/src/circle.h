#pragma once

#include "shape.h"
#include <string>
#include <cmath>
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"
#include <math.h>

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
    double _radius;
};