#pragma once
#include "../shape.h"
#include "../circle.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "../two_dimensional_vector.h"
#include "../compound_shape.h"
#include <stack>
#include <list>

class ShapeBuilder {
public:
    void buildCircle(double radius) {
        _result.push(new Circle(radius));
    }

    void buildRectangle(double length, double width) {
        _result.push(new Rectangle(length, width));
    }

    void buildTriangle(double x1, double y1, double x2, double y2) {
        TwoDimensionalVector v1(x1, y1);
        TwoDimensionalVector v2(x2, y2);
        _result.push(new Triangle(v1, v2));
    }

    void buildCompoundBegin() {
        _result.push(new CompoundShape());
    }

    void buildCompoundEnd() {
        std::list<Shape*> temporary;
        while(typeid(*_result.top()) != typeid(CompoundShape) ||
                (!_result.top()->createIterator()->isDone() && 
                typeid(*_result.top()) == typeid(CompoundShape)) ){
            temporary.push_back(_result.top());
            _result.pop();
        }

        Shape* compound = _result.top();
        for(auto it = temporary.rbegin(); it != temporary.rend(); it++){
            compound->addShape(*it);
        }
    }

    Shape* getShape() {
        return _result.top();
    }

    ~ShapeBuilder(){
        while(!_result.empty()){
            // this calls the removed element destructor
            _result.pop();
        }
    }
private:
    std::stack<Shape*> _result;

};
