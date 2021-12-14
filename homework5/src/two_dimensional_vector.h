#pragma once

#include "math.h"
#include <string>

class TwoDimensionalVector{
public:
    TwoDimensionalVector(double x, double y): _x(x),_y(y){
        if(x==0.0 && y==0.0){
            throw std::string("Vector's value can't all be zero.");
        }
    }

    double x() const{
        return _x;
    };

    double y() const{
        return _y;
    };

    // Pythagorean theorem
    double length() const{
        return sqrt(pow(_x,2)+pow(_y,2));
    };

    // x1*x2+y1*y2 (dot product)
    double dot(TwoDimensionalVector vec) const{
        return _x*vec.x()+_y*vec.y();
    };

    //  x1*y2 - y1*x2 (cross product)
    double cross(TwoDimensionalVector vec) const{
        return _x*vec.y()-_y*vec.x();
    };

    // x1-x2, y1-y2
    TwoDimensionalVector subtract(TwoDimensionalVector vec) const{
        TwoDimensionalVector new_vec(_x-vec.x(),_y-vec.y());
        return new_vec;
    };

    std::string info() const{
        // return "TwoDimensionalVector ("+decimalpoint(_x, 2)+", "+decimalpoint(_y, 2)+")";
        return "["+decimalpoint(_x, 2)+","+decimalpoint(_y, 2)+"]";
    };

    /* return string that decimal will be leaved only # of points */
    std::string decimalpoint(double real, int point) const{
        // shift left two points, and double turns into string type
        std::string str_real = std::to_string(round(real*pow(10.0, point)));

        for(unsigned i=0; i<str_real.length(); i++){
            if(str_real.at(i)=='.'){
                str_real.erase(i, str_real.length()-i);
                if(str_real.length() > point){
                    str_real.insert(str_real.length()-point,".");
                }else{
                    int original_length = str_real.length();
                    for(int i=0; i<(point+1-original_length);i++){
                        str_real = "0" + str_real;
                    }
                    str_real.insert(str_real.length()-point,".");
                }
                break;
            }
        }

        return str_real;
    }
private:
    double _x;
    double _y;
};