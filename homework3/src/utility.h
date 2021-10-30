#pragma once
#include "shape.h"
#include "iterator/iterator.h"

template <class ShapeConstraint>
// you should define a template class or type `ShapeConstraint`
Shape* selectShape(Shape* shape, ShapeConstraint constraint) { 
    Iterator* it = shape->createIterator();
    Shape* result = nullptr;

    for(it->first();!it->isDone();it->next()){
        if(constraint(it->currentItem())){
            result = it->currentItem();
            break;
        }
    }

    return result;
}