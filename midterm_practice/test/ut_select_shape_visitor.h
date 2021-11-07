#pragma once

#include <gtest/gtest.h>
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"
#include "../src/shape.h"
#include "../src/twoDimensionVector.h"
#include "../src/visitor/select_shape_visitor.h"
#include "../src/visitor/shape_visitor.h"

class SelectShapeVisitorTest: public ::testing::Test{
    protected:
        SelectShapeVisitorTest(){}
        ~SelectShapeVisitorTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            c = new Circle(3.0);
            TwoDimensionVector vec1(0.0, 5.0);
            TwoDimensionVector vec2(5.0, 0.0);
            t = new Triangle(vec1, vec2);
            r = new Rectangle(10.0, 2.0);
            cs = new CompoundShape();
            cs->addShape(c);
            cs->addShape(t);
            cs->addShape(r);

            sv = new SelectShapeVisitor();
            sv_constraint = new SelectShapeVisitor([](Shape* s) {
                return s->area() > 10.0 && s->area() < 50.0; 
            });
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete cs;
            delete sv;
        }

    // Class members declared here can be used by all tests in the test suite
    Shape* c;
    Shape* t;
    Shape* r;
    Shape* cs;
    ShapeVisitor* sv;
    ShapeVisitor* sv_constraint;
};

TEST_F(SelectShapeVisitorTest, Creation){
    // Expected
    ASSERT_TRUE(typeid(*sv)==typeid(SelectShapeVisitor));
}

TEST_F(SelectShapeVisitorTest, VisitCircle){
    c->accept(sv);
    // Expected
    ASSERT_EQ(sv->getResult(), c);
}

TEST_F(SelectShapeVisitorTest, VisitCircleWithCompatibleConstraint){
    // Compatible
    c->accept(sv_constraint);

    // Expected
    ASSERT_EQ(sv_constraint->getResult(), c);
}

TEST_F(SelectShapeVisitorTest, VisitCircleWithNonCompatibleConstraint){
    // Non-compatible
    Shape* c2 = new Circle(10.0);
    c2->accept(sv_constraint);

    // Expected
    ASSERT_EQ(sv_constraint->getResult(), nullptr);
    delete c2;
}

TEST_F(SelectShapeVisitorTest, VisitRectangle){
    r->accept(sv);
    // Expected
    ASSERT_EQ(sv->getResult(), r);
}

TEST_F(SelectShapeVisitorTest, VisitRectangleWithCompatibleConstraint){
    // Compatible
    r->accept(sv_constraint);

    // Expected
    ASSERT_EQ(sv_constraint->getResult(), r);
}

TEST_F(SelectShapeVisitorTest, VisitRectangleWithNonCompatibleConstraint){
    // Non-compatible
    Shape* r2 = new Rectangle(10.0, 10.0);
    r2->accept(sv_constraint);

    // Expected
    ASSERT_EQ(sv_constraint->getResult(), nullptr);
    delete r2;
}

TEST_F(SelectShapeVisitorTest, VisitTriangle){
    t->accept(sv);
    // Expected
    ASSERT_EQ(sv->getResult(), t);
}

TEST_F(SelectShapeVisitorTest, VisitTriangleWithCompatibleConstraint){
    // Compatible
    t->accept(sv_constraint);

    // Expected
    ASSERT_EQ(sv_constraint->getResult(), t);
}

TEST_F(SelectShapeVisitorTest, VisitTriangleWithNonCompatibleConstraint){
    // Non-compatible
    TwoDimensionVector v1(5.0, 12.0);
    TwoDimensionVector v2(6.0, 14.0);
    Shape* t2 = new Triangle(v1, v2);
    t2->accept(sv_constraint);

    // Expected
    ASSERT_EQ(sv_constraint->getResult(), nullptr);
    delete t2;
}

TEST_F(SelectShapeVisitorTest, VisitCompoundShape){
    cs->accept(sv);
    // Expected
    ASSERT_EQ(sv->getResult(), c);
}

TEST_F(SelectShapeVisitorTest, VisitCompoundShapeWithCompatibleConstraint){
    // Compatible
    cs->accept(sv_constraint);

    // Expected
    ASSERT_EQ(sv_constraint->getResult(), c);
}

TEST_F(SelectShapeVisitorTest, VisitCompoundShapeWithNonCompatibleConstraint){
    // Non-compatible
    TwoDimensionVector v1(5.0, 12.0);
    TwoDimensionVector v2(6.0, 14.0);
    Shape* t2 = new Triangle(v1, v2);
    Shape* c2 = new Circle(10.0);
    Shape* cs2 = new CompoundShape();
    
    cs2->addShape(t2);
    cs2->addShape(c2);
    cs2->accept(sv_constraint);

    // Expected
    ASSERT_EQ(sv_constraint->getResult(), nullptr);
    delete cs2;
}
