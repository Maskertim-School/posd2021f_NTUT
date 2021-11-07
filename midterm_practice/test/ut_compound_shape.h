#pragma once

#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/compound_shape.h"
#include "../src/iterator/iterator.h"

class CompoundShapeTest: public ::testing::Test {
    protected:
        CompoundShapeTest(){}
        ~CompoundShapeTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            c = new Circle(10.0);
            r = new Rectangle(10.0, 2.0);
            cs = new CompoundShape();
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete cs;
        }

    // Class members declared here can be used by all tests in the test suite
    Shape* cs;
    Shape* c;
    Shape* r;
};

TEST_F(CompoundShapeTest, Creation){
    // Expected
    ASSERT_TRUE(typeid(*cs)==typeid(CompoundShape));
}

TEST_F(CompoundShapeTest, AddShapeIsWorking){
    // Logic
    cs->addShape(c);
    Iterator* it = cs->createIterator();
    
    // Expected
    ASSERT_TRUE(typeid(*(it->currentItem()))==typeid(*c));
}

TEST_F(CompoundShapeTest, DeleteShapeIsWorking){
    // Logic
    cs->addShape(c);
    cs->deleteShape(c);
    Iterator* it = cs->createIterator();
    
    // Expected
    ASSERT_TRUE(it->isDone());
}

TEST_F(CompoundShapeTest, DeleteShapeThrowsNotFound){
    // Expected
    try{
        cs->addShape(c);
        cs->deleteShape(r);
    }catch(std::string ex){
        ASSERT_EQ(ex, "The shape don't contain in compoundshape.");
    }
}

TEST_F(CompoundShapeTest, AreaIsWorking){
    // Logic
    cs->addShape(c);
    cs->addShape(r);
    
    // Expected
    ASSERT_EQ(cs->area(), c->area()+r->area());
}

TEST_F(CompoundShapeTest, AreaIsWorkingWithCompoundShape){
    // Logic
    cs->addShape(c);
    cs->addShape(r);
    Shape* cs2 = new CompoundShape();
    cs2->addShape(c);
    cs2->addShape(cs);
    
    // Expected
    ASSERT_EQ(cs2->area(), c->area()+r->area()+c->area());
}

TEST_F(CompoundShapeTest, PerimeterIsWorking){
    // Logic
    cs->addShape(c);
    cs->addShape(r);
    
    // Expected
    ASSERT_EQ(cs->perimeter(), c->perimeter()+r->perimeter());
}

TEST_F(CompoundShapeTest, PerimeterIsWorkingWithCompoundShape){
    // Logic
    cs->addShape(c);
    cs->addShape(r);
    Shape* cs2 = new CompoundShape();
    cs2->addShape(c);
    cs2->addShape(cs);
    
    // Expected
    ASSERT_EQ(cs2->perimeter(), c->perimeter()+r->perimeter()+c->perimeter());
}

TEST_F(CompoundShapeTest, InfoIsWorking){
    // Logic
    cs->addShape(c);
    cs->addShape(r);
    
    std::string expected = "CompoundShape{\n"
                        "Circle (10.00)\n"
                        "Rectangle (10.00, 2.00)\n"
                        "}";

    // Expected
    ASSERT_EQ(cs->info(), expected);
}

TEST_F(CompoundShapeTest, InfoIsWorkingWithCompoundShape){
    // Logic
    cs->addShape(c);
    cs->addShape(r);
    Shape* cs2 = new CompoundShape();
    cs2->addShape(c);
    cs2->addShape(cs);
    
    std::string expected = "CompoundShape{\n"
                        "Circle (10.00)\n"
                        "CompoundShape{\n"
                        "Circle (10.00)\n"
                        "Rectangle (10.00, 2.00)\n"
                        "}\n}";

    // Expected
    ASSERT_EQ(cs2->info(), expected);
}
