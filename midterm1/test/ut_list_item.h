#pragma once

#include <gtest/gtest.h>
#include "../src/list_item.h"
#include "../src/article.h"

class ListItemTest: public ::testing::Test {
    protected:
        ListItemTest(){}
        ~ListItemTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            listItem = new ListItem("listItem");
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete listItem;
        }

    // Class members declared here can be used by all tests in the test suite
    Article* listItem;
};

TEST_F(ListItemTest, Creation){
    ASSERT_TRUE(typeid(*listItem)==typeid(ListItem));
}

TEST_F(ListItemTest, GetText){
    ASSERT_EQ(listItem->getText(), "listItem");
}

TEST_F(ListItemTest, GetLevel){
    ASSERT_EQ(listItem->getLevel(), 0);
}

TEST_F(ListItemTest, AddThrowsException){
    Article* l2 = new ListItem("list2");
    try{
        listItem->add(l2);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "don't have add method.");
    }
    delete l2;
}

TEST_F(ListItemTest, CreateIteratorShouldBeNullIterator){
    ASSERT_TRUE(typeid(*listItem->createIterator())== typeid(NullIterator));
}