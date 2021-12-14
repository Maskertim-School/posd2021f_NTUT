#pragma once

#include <list>
#include "shape.h"
#include "iterator/iterator.h"
#include "iterator/compound_iterator.h"
#include "visitor/shape_visitor.h"

class CompoundShape: public Shape{
public:
    ~CompoundShape(){
        for(std::list<Shape*>::iterator it= _shapes.begin(); it!=_shapes.end();it++){
            delete *it;
        }
    }

    CompoundShape(){}

    double area() const override{
        double sum = 0.0;
        for(std::list<Shape*>::const_iterator it = _shapes.begin(); it!=_shapes.end(); it++){
            sum += (*it)->area();
        }
        return sum;
    }

    double perimeter() const override{
        double sum = 0.0;
        for(std::list<Shape*>::const_iterator it = _shapes.begin(); it!=_shapes.end(); it++){
            sum += (*it)->perimeter();
        }
        return sum;
    }

    std::string info() const override{
        return "CompoundShape";
    }

    Iterator* createIterator() override{
        return new CompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end());
    }

    void addShape(Shape* shape) override{
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override{
        // it can't delete itself
        if(shape==this){
            throw std::string("Can't kill itself.");
        }

        Iterator* it = createIterator();

        bool isFind = false;

        std::list<Shape*> store;
        for(it->first(); !it->isDone(); it->next()){
            if(!isFind && (it->currentItem() == shape)){
                isFind = true;
                continue;
            }else if(!isFind && typeid(*(it->currentItem()))==typeid(CompoundShape)){
                it->currentItem()->deleteShape(shape);
            }
            store.push_back(it->currentItem());
        }

        _shapes = store;

        delete it;
    }

    void accept(ShapeVisitor* visitor) override{
        visitor->visitCompoundShape(this);
    }

private:
    std::list<Shape*> _shapes;
};