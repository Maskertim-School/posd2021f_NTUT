#pragma once

#include <gtest/gtest.h>
#include "../../src/circle.h"
#include "../../src/compound_shape.h"
#include "../../src/rectangle.h"
#include "../../src/iterator/compound_iterator.h"
#include "../../src/shape.h"
#include "../../src/iterator/iterator.h"

class CompoundIteratorTest: public ::testing::Test {
    protected:
        CompoundIteratorTest(){}
        ~CompoundIteratorTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            c = new Circle(5.0);
            r = new Rectangle(10.0, 2.0);
            cs = new CompoundShape();
            cs->addShape(c);
            cs->addShape(r);
            it = cs->createIterator();
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete cs;
            delete it;
        }

    // Class members declared here can be used by all tests in the test suite
    Shape* cs;
    Shape* c;
    Shape* r;
    Iterator* it;
};

TEST_F(CompoundIteratorTest, Creation){
    // Expected
    ASSERT_TRUE(typeid(*it)==typeid(CompoundIterator<std::list<Shape*>::iterator>));
}

TEST_F(CompoundIteratorTest, FirstIsCorrect){
    // Logic
    it->first();
    
    // Expected
    ASSERT_EQ(it->currentItem()->area(), c->area());
}

TEST_F(CompoundIteratorTest, CurrentItemIsCorrect){
    // Expected
    ASSERT_EQ(it->currentItem()->area(), c->area());
}

TEST_F(CompoundIteratorTest, CurrentItemThrowsNoElement){
    Shape* cs1 = new CompoundShape();
    // Expected
    try{
        cs1->createIterator()->currentItem();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "There is no elements in compound shapes.");
    }

    delete cs1;
}

TEST_F(CompoundIteratorTest, NextIsCorrect){
    it->next();
    // Expected
    ASSERT_EQ(it->currentItem()->area(), r->area());
}

TEST_F(CompoundIteratorTest, NextThrowsNoElement){
    Shape* cs1 = new CompoundShape();
    Iterator* it1 = cs1->createIterator();
    // Expected
    try{
        it1->next();
        it1->next();
        it1->next();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "There is no elements in compound shapes.");
    }
    delete cs1;
    delete it1;
}