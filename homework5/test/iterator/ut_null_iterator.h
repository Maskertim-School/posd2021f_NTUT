#pragma once

#include <gtest/gtest.h>
#include "../../src/circle.h"
#include "../../src/iterator/null_iterator.h"
#include "../../src/shape.h"
#include "../../src/iterator/iterator.h"

class NullIteratorTest: public ::testing::Test {
    protected:
        NullIteratorTest(){}
        ~NullIteratorTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            c = new Circle(5.0);
            null_it = c->createIterator();
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete c;
            delete null_it;
        }

    // Class members declared here can be used by all tests in the test suite
    Shape* c;
    Iterator* null_it;
};

TEST_F(NullIteratorTest, NullIteratorCreation){
    // Expected
    ASSERT_TRUE(typeid(*(c->createIterator()))==typeid(NullIterator));
}

TEST_F(NullIteratorTest, IsDoneAlwaysTrue){
    // Expected
    ASSERT_TRUE(null_it->isDone());
}

TEST_F(NullIteratorTest, NextThrowException){
    // Expected
    try{
        null_it->next();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Null Iterator don't have next().");
    }
}

TEST_F(NullIteratorTest, CurrentItemThrowException){
    // Expected
    try{
        null_it->currentItem();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Null Iterator don't have currentItem().");
    }
}

TEST_F(NullIteratorTest, FirstThrowException){
    // Expected
    try{
        null_it->first();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Null Iterator don't have first().");
    }
}