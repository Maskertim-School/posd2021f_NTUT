#pragma once
#include "string"

class Iterator;

class Shape {
public:
    virtual ~Shape() {};

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    virtual Iterator* createIterator() = 0;

    virtual void addShape(Shape* shape) { 
        throw std::string("Uncomposite shape don't have method of addShape.");
    }

    virtual void deleteShape(Shape* shape) { 
        throw std::string("Uncomposite shape don't have method of deleteShape.");
    }

    void decimalplace(std::string& str, int index) const {
        for(int i=0; i<str.length();i++){
            if(str[i]=='.'){
                str.erase(i+index+1);
                break;
            }
        }
    }
};