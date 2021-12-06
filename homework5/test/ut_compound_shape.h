#pragma once

#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/compound_shape.h"
#include "../src/iterator/iterator.h"
#include "../src/iterator/compound_iterator.h"
#include <list>

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

TEST_F(CompoundShapeTest, CreateIteratorNoException){
    Iterator* it = cs->createIterator();
    // Expected
    ASSERT_TRUE(typeid(*it)==typeid(CompoundIterator<std::list<Shape*>::iterator>));

    delete it;
}

TEST_F(CompoundShapeTest, AddShapeIsWorking){
    // Logic
    cs->addShape(c);
    Iterator* it = cs->createIterator();
    
    // Expected
    ASSERT_TRUE(typeid(*(it->currentItem()))==typeid(*c));
    delete it;
}

TEST_F(CompoundShapeTest, DeleteShapeIsWorking){
    // Logic
    cs->addShape(c);
    cs->addShape(r);
    Shape* r2 = new Rectangle(2.0, 5.0);
    cs->addShape(r2);
    cs->deleteShape(r);
    Iterator* it = cs->createIterator();
    it->next();

    // Expected
    ASSERT_TRUE(it->currentItem()==r2);

    delete it;
}

TEST_F(CompoundShapeTest, DeleteInnerShapeCorrectly){
    // Logic
    cs->addShape(c);
    cs->addShape(r);
    Shape* r2 = new Rectangle(2.0, 5.0);
    Shape* r3 = new Rectangle(3.0, 4.0);
    Shape* cs2 = new CompoundShape();
    cs2->addShape(r2);
    cs2->addShape(r3);
    cs->addShape(cs2);
    cs->deleteShape(r2);

    Iterator* it = cs->createIterator();
    it->next();
    it->next();
    Iterator* innerIt = it->currentItem()->createIterator();

    // // Expected
    ASSERT_TRUE(innerIt->currentItem()==r3);

    delete innerIt;
    delete it;
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
    Shape* c2 = new Circle(2.0);
    cs2->addShape(c2);
    cs->addShape(cs2);
    
    // Expected
    ASSERT_EQ(cs->perimeter(), c->perimeter()+r->perimeter()+c2->perimeter());
}

TEST_F(CompoundShapeTest, DeleteShapeItselfThrowException){
    cs->addShape(c);
    cs->addShape(r);
    try{
        cs->deleteShape(cs);
        FAIL();
    }catch(std::string ex){
        // Expected
        ASSERT_EQ(ex, "Can't kill itself.");
    }
}

TEST_F(CompoundShapeTest, InfoIsWorking){
    std::string expected = "CompoundShape";

    // Expected
    ASSERT_EQ(cs->info(), expected);
}

TEST_F(CompoundShapeTest, AcceptCompoundShape){
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14 ,4));
    
    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(12.34567));
    cs2->addShape(cs1);
    
    ShapeInfoVisitor visitor;
    cs2->accept(&visitor);

    // Expected
    std::string answer = "CompoundShape {\n"
                    "  Circle (12.35)\n"
                    "  CompoundShape {\n"
                    "    Circle (1.10)\n"
                    "    Rectangle (3.14 4.00)\n"
                    "  }\n"
                    "}\n";
    ASSERT_EQ(visitor.getResult(), answer);

    delete cs2;
}