#pragma once
#include "shape.h"
#include "string"
#include "iterator/compound_iterator.h"
#include <list>

class Iterator;

class CompoundShape : public Shape {
public:

    ~CompoundShape() { 
        for (std::list<Shape*>::iterator it=_shapes.begin(); it!=_shapes.end(); ++it){
            delete *it;
        }
    }

    double area() const override {
        double sum = 0.0; 
        for (auto it : _shapes){
            sum = it->area() + sum;
        }
        return sum;
    }

    double perimeter() const override {
        double sum = 0.0; 
        for(std::list<Shape*>::const_iterator it = _shapes.begin();it!=_shapes.end();it++){
            sum += (*it)->perimeter();
        }
        return sum;
    }

    std::string info() const override { 
        std::string start = "CompoundShape\n{\n";
        std::string end = "}";
        std::string middle = "";

        for (auto it: _shapes){
            middle = middle+it->info()+"\n";
        }

        return start+middle+end;
    }

    Iterator* createIterator() override { 
        return new CompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end());
    }

    void addShape(Shape* shape) override {
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override { 
        Iterator* it = createIterator();
        for(it->first();!it->isDone();it->next()){
            if(it->currentItem()==shape){
                _shapes.remove(shape);
                break;
            }
        }

        if(it->isDone()){
            throw std::string("This type of shape don't find in compoundshape.");
        }
    }

private:
    std::list<Shape*> _shapes;
};