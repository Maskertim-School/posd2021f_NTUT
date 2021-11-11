#pragma once

#include <gtest/gtest.h>
#include "../../src/iterator/iterator.h"
#include "../../src/iterator/compound_iterator.h"
#include "../../src/paragraph.h"
#include "../../src/article.h"
#include "../../src/text.h"
#include "../../src/list_item.h"
#include <list>
#include <string>

class CompoundIteratorTest: public ::testing::Test {
    protected:
        CompoundIteratorTest(){}
        ~CompoundIteratorTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            t = new Text("text");
            l = new ListItem("list");
            p = new Paragraph(1, "paragraph");
            p->add(t);
            p->add(l);
            c_ptr = p->createIterator();
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete p;
            delete c_ptr;
        }

    // Class members declared here can be used by all tests in the test suite
    Article* p;
    Article* t;
    Article* l;
    Iterator* c_ptr;
};

TEST_F(CompoundIteratorTest, CompoundIteratorOfCreation){
    ASSERT_TRUE(typeid(*c_ptr)==typeid(CompoundIterator<std::list<Article*>::iterator>));
}

TEST_F(CompoundIteratorTest, NextThrowsNoElement){
    try{
        c_ptr->next();
        c_ptr->next();
        c_ptr->next();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Don't have any elements.");
    }
}

TEST_F(CompoundIteratorTest, CurrentItemThrowsNoElement){
    try{
        Article* px = new Paragraph(2, "fault");
        Iterator* c_ptrx = px->createIterator();
        c_ptrx->currentItem();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Don't have any elements.");
    }
}

TEST_F(CompoundIteratorTest, FirstThrowsNoElement){
    try{
        Article* px = new Paragraph(2, "fault");
        Iterator* c_ptrx = px->createIterator();
        c_ptrx->first();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Don't have any elements.");
    }
}

TEST_F(CompoundIteratorTest, FirstIsCorrect){
    c_ptr->first();
    ASSERT_EQ(c_ptr->currentItem()->getText(), "text");
}

TEST_F(CompoundIteratorTest, CurrentItemIsCorrect){
    ASSERT_EQ(c_ptr->currentItem()->getText(), "text");
}

TEST_F(CompoundIteratorTest, NextIsCorrect){
    c_ptr->next();
    ASSERT_EQ(c_ptr->currentItem()->getText(), "list");
}

TEST_F(CompoundIteratorTest, IsDoneIsCorrect){
    c_ptr->next();
    ASSERT_EQ(c_ptr->isDone(), false);
    c_ptr->next();
    ASSERT_EQ(c_ptr->isDone(), true);
}