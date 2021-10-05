#pragma once

#include <iostream>
#include "shape.h"
#include <string>
#include <cmath>

using namespace std;

class Rectangle : public Shape {
public: 
    Rectangle(double length, double width): _length(length),_width(width) { 
        if(length <= 0 || width <= 0){
            throw std::string ("This is not rectangle.");
        }
    }

    double area() const { 
        return _length*_width;
    }

    double perimeter() const { 
        return (_length+_width)*2;
    }
    
    std::string info() const { 
        double round_length = round(_length*100.0)/100.0;
        double round_width = round(_width*100.0)/100.0;
        std::string strlength = std::to_string(round_length);
        std::string strwidth = std::to_string(round_width);
        decimalplace(strlength, 2);
        decimalplace(strwidth, 2);
        return "Rectangle ("+strlength+" "+strwidth+")";
    }

    void decimalplace(std::string& str, int index) const {
        for(int i=0; i<str.length();i++){
            if(str[i]=='.'){
                str.erase(i+index+1);
                break;
            }
        }
    }



private:
    double _length;
    double _width;
};
