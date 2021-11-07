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
        std::string content = "";
        for(std::list<Shape*>::const_iterator it = _shapes.begin(); it!=_shapes.end(); it++){
            content += (*it)->info()+"\n";
        }
        return "CompoundShape{\n"+content+"}";
    }

    Iterator* createIterator() override{
        return new CompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end());
    }

    void addShape(Shape* shape) override{
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override{
        Iterator* it = createIterator();
        for(it->first(); !it->isDone(); it->next()){
            if(it->currentItem() == shape){
                _shapes.remove(shape);
                break;
            }
        }

        // if not find the matching shape, just throw exception
        if(it->isDone()){
            delete it;
            throw std::string("The shape don't contain in compoundshape.");
        }

        delete it;
    }

    void accept(ShapeVisitor* visitor) override{
        visitor->visitCompoundShape(this);
    }

private:
    std::list<Shape*> _shapes;
};