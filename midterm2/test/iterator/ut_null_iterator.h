#pragma once

#include <gtest/gtest.h>
#include "../../src/iterator/iterator.h"
#include "../../src/text.h"
#include "../../src/iterator/null_iterator.h"
#include "../../src/iterator/compound_iterator.h"
#include <list>
#include <string>

class NullIteratorTest: public ::testing::Test {
    protected:
        NullIteratorTest(){}
        ~NullIteratorTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            t = new Text("text");
            n_ptr = t->createIterator();
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete t;
            delete n_ptr;
           
        }

    // Class members declared here can be used by all tests in the test suite
    Article* t;
    Iterator* n_ptr;
};

TEST_F(NullIteratorTest, NullIteratorOfCreation){
    ASSERT_TRUE(typeid(*n_ptr)==typeid(NullIterator));
}

TEST_F(NullIteratorTest, NullIteratorOfFirstThrowsException){
    try{
        n_ptr->first();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Don't have first method.");
    }
}

TEST_F(NullIteratorTest, NullIteratorOfNextThrowsException){
    try{
        n_ptr->next();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Don't have next method.");
    }
}

TEST_F(NullIteratorTest, NullIteratorOfCurrentItemThrowsException){
    try{
        n_ptr->currentItem();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Don't have currentItem method.");
    }
}

TEST_F(NullIteratorTest, NullIteratorOfIsDoneIsTrue){
    ASSERT_TRUE(n_ptr->isDone());
}