#pragma once

class Shape;

class Iterator{
public:
    virtual ~Iterator(){}

    Iterator(){}

    virtual void first() = 0;
    
    virtual Shape* currentItem() = 0;
    
    virtual void next() = 0;

    virtual bool isDone() = 0; 

};