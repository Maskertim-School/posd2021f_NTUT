#pragma once
#include "shape.h"
#include "string"
#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include <cmath>

class Rectangle : public Shape {
public: 
    Rectangle(double length, double width): _length(length),_width(width) {
        // the length and width don't allow a negative value
        if(length<=0 || width <=0){
            throw std::string("The negative or zero length or width isn't allow.");
        }
    }

    // the calculation is length * width
    double area() const override {
        return _length*_width;
    }

    // the calculation is 2*(length+width)
    double perimeter() const override { 
        return 2*(_length+_width);
    }
    
    // show the information of rectangle with decimal point of two
    std::string info() const override { 
        double round_length = round(_length*100.0)/100.0;
        double round_width = round(_width*100.0)/100.0;
        std::string strlength = std::to_string(round_length);
        std::string strwidth = std::to_string(round_width);
        decimalplace(strlength, 2);
        decimalplace(strwidth, 2);
        return "Rectangle (" +strlength+" "+strwidth+")";
    }

    Iterator* createIterator() override { 
        return new NullIterator();
    }

private:
    double _length;
    double _width;
};
