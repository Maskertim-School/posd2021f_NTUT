#pragma once

#include "../../src/visitor/shape_info_visitor.h"
#include "../../src/shape.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/compound_shape.h"
#include <string>

TEST(CaseShapeInfoVisitor, Creation){
    ShapeInfoVisitor* sv = new ShapeInfoVisitor();
    //Expected
    ASSERT_TRUE(typeid(*sv)==typeid(ShapeInfoVisitor));

    delete sv;
}

TEST(CaseShapeInfoVisitor, VisitCircle){
    Shape* circle = new Circle(5.0);
    ShapeInfoVisitor* sv = new ShapeInfoVisitor();
    sv->visitCircle(dynamic_cast<Circle*>(circle));
    // Expected
    ASSERT_EQ(sv->getResult(), "Circle (5.00)\n");

    delete circle;
    delete sv;
}

TEST(CaseShapeInfoVisitor, VisitorRectangle){
    Shape* rectangle = new Rectangle(2.0, 3.0);
    ShapeInfoVisitor* sv = new ShapeInfoVisitor();
    sv->visitRectangle(dynamic_cast<Rectangle*>(rectangle));
    // Expected
    ASSERT_EQ(sv->getResult(), "Rectangle (2.00 3.00)\n");

    delete rectangle;
    delete sv;
}

TEST(CaseShapeInfoVisitor, VisitorTriangle){
    TwoDimensionalVector t1(1.0, 2.0);
    TwoDimensionalVector t2(2.0, 3.0);
    Shape* triangle = new Triangle(t1, t2);
    ShapeInfoVisitor* sv = new ShapeInfoVisitor();
    sv->visitTriangle(dynamic_cast<Triangle*>(triangle));
    // Expected
    ASSERT_EQ(sv->getResult(), "Triangle ([1.00,2.00] [2.00,3.00])\n");

    delete triangle;
    delete sv;
}

TEST(CaseShapeInfoVisitor, VisitorCompoundShapeWithoutElement){
    Shape* cs1 = new CompoundShape();
    ShapeInfoVisitor visitor;
    visitor.visitCompoundShape(dynamic_cast<CompoundShape*>(cs1));
    // Expected
    ASSERT_EQ(visitor.getResult(), "CompoundShape {\n}\n");

    delete cs1;
}

TEST(CaseShapeInfoVisitor, VisitorCompoundShape){
    Shape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14 ,4));
    
    Shape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(12.34567));
    cs2->addShape(cs1);
    
    ShapeInfoVisitor visitor;
    visitor.visitCompoundShape(dynamic_cast<CompoundShape*>(cs2));

    // Expected
    std::string answer = "CompoundShape {\n"
                    "  Circle (12.35)\n"
                    "  CompoundShape {\n"
                    "    Circle (1.10)\n"
                    "    Rectangle (3.14 4.00)\n"
                    "  }\n"
                    "}\n";
    ASSERT_EQ(visitor.getResult(), answer);

    // cs1 will delete by cs2 deconstructor
    delete cs2;
}