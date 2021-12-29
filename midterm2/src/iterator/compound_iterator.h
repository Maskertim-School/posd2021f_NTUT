#pragma once

#include "iterator.h"
#include "../article.h"

template <class ForwardIterator>
class CompoundIterator : public Iterator {
   public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end): _begin(begin), _end(end), _current(begin) {}

    void first() override {
        if(isDone()){
            throw std::string("Don't have any elements.");
        }
        _current = _begin;
    }

    Article* currentItem() const override {
        if(isDone()){
            throw std::string("Don't have any elements.");
        }
        return *_current;
    }

    void next() override {
        if(isDone()){
            throw std::string("Don't have any elements.");
        }
        _current++;
    }

    bool isDone() const override {
        return _current==_end;
    }
private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
};
