#pragma once
#include "iterator.h"

class Shape;

class NullIterator : public Iterator {
public:
    void first() override { 
        throw std::string("The first method of Null Iterator is not allowed.");
    }

    Shape* currentItem() const override { 
        throw std::string("The currentItem method of Null Iterator is not allowed.");
    }

    void next() override { 
        throw std::string("The next method of Null Iterator is not allowed.");
    }

    bool isDone() const override { 
        return true;
    }
};