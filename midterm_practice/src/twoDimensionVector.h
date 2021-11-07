#pragma once

#include "math.h"
#include <string>
#include "utility.h"

class TwoDimensionVector{
public:
    ~TwoDimensionVector(){};

    TwoDimensionVector(double x, double y): _x(x),_y(y){
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
    double dot(TwoDimensionVector vec) const{
        return _x*vec.x()+_y*vec.y();
    };

    //  x1*y2 - y1*x2 (cross product)
    double cross(TwoDimensionVector vec) const{
        return _x*vec.y()-_y*vec.x();
    };

    // x1-x2, y1-y2
    TwoDimensionVector subtract(TwoDimensionVector vec) const{
        TwoDimensionVector new_vec(_x-vec.x(),_y-vec.y());
        return new_vec;
    };

    std::string info() const{
        return "TwoDimensionVector ("+decimalpoint(_x, 2)+", "+decimalpoint(_y, 2)+")";
    };

private:
    double _x;
    double _y;
};