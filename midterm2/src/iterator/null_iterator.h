#pragma once

#include "../article.h"
#include "iterator.h"

class NullIterator : public Iterator {
   public:
    void first() override {    
        throw std::string("Don't have first method.");
    }

    Article* currentItem() const override {
        throw std::string("Don't have currentItem method.");
    }

    void next() override {
        throw std::string("Don't have next method.");
    }

    bool isDone() const override {
        return true;
    }
};
