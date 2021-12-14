#pragma once

#include "iterator.h"
#include "../shape.h"

template <class ForwardIterator>
class CompoundIterator: public Iterator{
public:
    ~CompoundIterator(){}

    CompoundIterator(ForwardIterator begin, ForwardIterator end): _begin(begin), _end(end){
        first();
    }

    void first() override{
        _current = _begin;
    }

    Shape* currentItem() const override{
        if(isDone()){
            throw std::string("There is no elements in compound shapes.");
        }
        return *_current;
    }

    void next() override{
        if(isDone()){
            throw std::string("There is no elements in compound shapes.");
        }else{
            _current++;
        }
    }

    bool isDone() const override{
        return _current==_end;
    }
private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
    
};