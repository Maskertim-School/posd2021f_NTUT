#pragma once
#include "iterator.h"
#include "../shape.h"
#include <iostream>
#include "../circle.h"

// you should define a template class or type `ForwardIterator`
template <class ForwardIterator>
class CompoundIterator : public Iterator{
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end): _begin(begin),_end(end),_current(begin) { }

    void first() override { 
        _current = _begin;
    }

    Shape* currentItem() const override {
        if(!isDone()){
            return *_current;
        }else{
            throw std::string("The element is done at the end point.");
        }
    }

    void next() override {
        // if not the last element, just go ahead
        if(!isDone()){
            _current++;
        }else{
            throw std::string("No next element can iterate.");
        }
    }

    bool isDone() const override {
        // it is null or not 
        return _current == _end;
    }

private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
};