#pragma once

#include <string>

class Article {
   public:
    virtual ~Article(){};

    virtual std::string getText() const = 0;

    virtual int getLevel() const {
        return 0;
    }

    virtual void add(Article* dpFormat){
        throw std::string ("not have add() function");
    };
};