#pragma once

#include "shape_visitor.h"
class Circle;
class Rectangle;
class Triangle;
class CompoundShape;
class Shape;
class Iterator;

typedef bool (*ShapeConstraint) (Shape*); // pointer to function
class SelectShapeVisitor: public ShapeVisitor{
public:
    ~SelectShapeVisitor(){}

    SelectShapeVisitor(): _result(nullptr), _constraint(nullptr){}

    SelectShapeVisitor(ShapeConstraint constraint): _result(nullptr), _constraint(constraint){}

    /* select first circle */
    void visitCircle(Circle* circle) override{
        // if constraint exists, then filter and return first circle.
        // else just return the circle.
        if(_constraint){
            if(_constraint(circle)){
                _result = circle;
            }else{
                _result = nullptr;
            }
        }else{
            _result = circle;
        }
    }

    void visitTriangle(Triangle* triangle) override{
        // if constraint exists, then filter and return first triangle.
        // else just return the triangle.
        if(_constraint){
            if(_constraint(triangle)){
                _result = triangle;
            }else{
                _result = nullptr;
            }
        }else{
            _result = triangle;
        }
    }

    void visitRectangle(Rectangle* rectangle) override{
        // if constraint exists, then filter and return first rectangle.
        // else just return the rectangle.
        if(_constraint){
            if(_constraint(rectangle)){
                _result = rectangle;
            }else{
                _result = nullptr;
            }
        }else{
            _result = rectangle;
        }
    }

    void visitCompoundShape(CompoundShape* compoundShape) override{
        // if constraint exists, then filter and return first sjape.
        // else just return the shape.
        Iterator* it = compoundShape->createIterator();
        if(_constraint){
            for(it->first();!it->isDone();it->next()){
                if(_constraint(it->currentItem())){
                    it->currentItem()->accept(this);
                    break;
                }
            }

            if(it->isDone()){
                _result = nullptr;
            }
        }else{
            _result = it->currentItem();
        }
        
        delete it;
    }

    Shape* getResult() const override{
        return _result;
    }

private:
    Shape* _result;
    ShapeConstraint _constraint;
};