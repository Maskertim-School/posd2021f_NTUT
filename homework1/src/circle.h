#pragma once

#include <iostream>
#include "shape.h"
#include <cmath>

using namespace std;

class Circle : public Shape {
public:
    Circle(double radius): _radius(radius) {
        if(radius <= 0){
            throw std::string ("This is not a circle.");
        }
     }

    double area() const {
        return pow(_radius, 2)*M_PI;
    }

    double perimeter() const { 
        return _radius*2*M_PI;
    }

    std::string info() const { 
        double round_radius = round(_radius*100.0)/100.0;
        std::string strradius = std::to_string(round_radius);
        decimalplace(strradius, 2);
        return "Circle ("+strradius+")";
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
    double _radius;
};
