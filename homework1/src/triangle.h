#pragma once

#include "shape.h"
#include "two_dimensional_vector.h"
#include <iostream>
#include <cmath>

using namespace std;

class Triangle: public Shape {
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2): _vec1(vec1),_vec2(vec2){
        if(vec1.cross(vec2)==0){
            throw string ("This is not a triangle.");
        }else{
            _vec1 = vec1;
            _vec2 = vec2;
        }
    }

    double area() const {
        // Helon formula
        double vec3length = _vec1.substract(_vec2).length();
        double s = (_vec1.length()+_vec2.length()+vec3length)/2.0;
        return sqrt(s*(s-_vec1.length())*(s-_vec2.length())*(s-vec3length));
    }

    double perimeter() const { 
        return _vec1.length()+_vec2.length()+_vec1.substract(_vec2).length();
    }

    std::string info() const { 
        return "Triangle ("+_vec1.info()+" "+_vec2.info()+")";
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
    TwoDimensionalVector _vec1;
    TwoDimensionalVector _vec2;
};