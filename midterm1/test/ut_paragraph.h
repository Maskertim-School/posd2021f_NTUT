#pragma once

#include <gtest/gtest.h>
#include "../src/paragraph.h"
#include "../src/article.h"

class ParagraphTest: public ::testing::Test {
    protected:
        ParagraphTest(){}
        ~ParagraphTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            p = new Paragraph(1, "paragraph");
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete p;
        }

    // Class members declared here can be used by all tests in the test suite
    Article* p;
};

TEST_F(ParagraphTest, Creation){
    ASSERT_TRUE(typeid(*p)==typeid(Paragraph));
}

TEST_F(ParagraphTest, GetText){
    ASSERT_EQ(p->getText(), "paragraph");
}

TEST_F(ParagraphTest, GetLevel){
    ASSERT_EQ(p->getLevel(), 1);
}

TEST_F(ParagraphTest, LevelGreaterThan6){
    try{
        Article* px = new Paragraph(7, "fault");
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "This level is not allowed.");
    }
}

TEST_F(ParagraphTest, AddThrowsIfGreaterOrEqualLevel){
    Article* p2 = new Paragraph(2, "two");
    try{
        p2->add(p);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Level is greater or equal. That can't be added.");
    }
    delete p2;
}