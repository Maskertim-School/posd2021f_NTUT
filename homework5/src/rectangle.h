#pragma once

#include "shape.h"
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include "visitor/shape_visitor.h"
#include <math.h>

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
        return "Rectangle ("+decimalpoint(_width, 2)+" "
                    +decimalpoint(_length, 2)+")";
    };

    Iterator* createIterator() override{
        return new NullIterator();
    };

    void accept(ShapeVisitor* visitor) override{
        visitor->visitRectangle(this);
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
    double _width;
    double _length;
};