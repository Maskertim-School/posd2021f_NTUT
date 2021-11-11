#pragma once

#include <gtest/gtest.h>
#include "../src/text.h"
#include "../src/article.h"

class TextTest: public ::testing::Test {
    protected:
        TextTest(){}
        ~TextTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            text = new Text("text");
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete text;
        }

    // Class members declared here can be used by all tests in the test suite
    Article* text;
};

TEST_F(TextTest, Creation){
    ASSERT_TRUE(typeid(*text)==typeid(Text));
}

TEST_F(TextTest, GetText){
    ASSERT_EQ(text->getText(), "text");
}

TEST_F(TextTest, GetLevel){
    ASSERT_EQ(text->getLevel(), 0);
}

TEST_F(TextTest, AddThrowsException){
    Article* t2 = new Text("text2");
    try{
        text->add(t2);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "don't have add method.");
    }
    delete t2;
}