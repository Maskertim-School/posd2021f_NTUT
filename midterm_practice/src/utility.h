#pragma once

#include "iterator/iterator.h"
#include "iterator/null_iterator.h"
#include <string>
#include "shape.h"

/* return string that decimal will be leaved only # of points */
std::string decimalpoint(double real, int point){
    // shift left two points, and double turns into string type
    std::string str_real = std::to_string(real*pow(10.0, point));

    for(unsigned i=0; i<str_real.length(); i++){
        if(str_real.at(i)=='.'){
            str_real.erase(i, str_real.length()-i);
            str_real.insert(str_real.length()-point,".");
            break;
        }
    }

    return str_real;
}

template <class ShapeConstraint>
Shape* SelectFirstShape(Shape* shape, ShapeConstraint constraint){
    Iterator* it = shape->createIterator();
    // if nulliterator, just return original shape
    // else recursively filter the shape
    if(typeid(*it)==typeid(NullIterator)){
        return shape;
    }else{
        for(it->first(); !it->isDone(); it->next()){
            if(constraint(it->currentItem())){
                return it->currentItem();
            }
        }
    }

    return nullptr;
}