#pragma once

class Circle;
class Rectangle;
class Triangle;
class CompoundShape;
class Shape;

class ShapeVisitor{
public:
    virtual ~ShapeVisitor(){}

    ShapeVisitor(){}

    virtual void visitCircle(Circle* circle) = 0;

    virtual void visitRectangle(Rectangle* rectangle) = 0;

    virtual void visitTriangle(Triangle* triangle) = 0;

    virtual void visitCompoundShape(CompoundShape* compoundShape) = 0;

    virtual Shape* getResult() const = 0;
};