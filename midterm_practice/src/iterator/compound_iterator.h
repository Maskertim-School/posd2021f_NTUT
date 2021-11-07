#pragma once

#include "iterator.h"
#include "../shape.h"

template <class ForwardIterator>
class CompoundIterator: public Iterator{
public:
    ~CompoundIterator(){}

    CompoundIterator(ForwardIterator begin, ForwardIterator end): _begin(begin), _end(end), _current(begin){}

    void first() override{
        if(isDone()){
            throw std::string("There is no elements in compound shapes.");
        }else{
            _current = _begin;
        }
    }

    Shape* currentItem() override{
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

    bool isDone() override{
        return _current==_end;
    }
private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
    
};