#pragma once

#include <gtest/gtest.h>
#include "../../src/visitor/html_visitor.h"
#include "../../src/visitor/article_visitor.h"
#include "../../src/paragraph.h"
#include "../../src/article.h"
#include "../../src/list_item.h"
#include "../../src/text.h"

class HtmlVisitorTest: public ::testing::Test {
    protected:
        HtmlVisitorTest(){}
        ~HtmlVisitorTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            p1 = new Paragraph(1, "title");
            p1->add(new ListItem("list1"));
            p1->add(new ListItem("list2"));
            p1->add(new Text("text"));
            p2 = new Paragraph(2, "title2");
            p2->add(new ListItem("list3"));
            p2->add(new ListItem("list4"));
            p2->add(new Text("sub text"));
            p1->add(p2);
            visitor = new HtmlVisitor();
            p1->accept(visitor);

        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete p1;
            delete visitor;
        }

    // Class members declared here can be used by all tests in the test suite
    ArticleVisitor* visitor;
    Article* p1;
    Article* p2;

};

TEST_F(HtmlVisitorTest, Creation){
    ASSERT_TRUE(typeid(*visitor)==typeid(HtmlVisitor));
}

TEST_F(HtmlVisitorTest, VisitorTextIsCorrect){
    Article* t1 = new Text("text");
    ArticleVisitor* hv = new HtmlVisitor();
    t1->accept(hv);
    ASSERT_EQ(hv->getResult(), "<span>text</span>");

    delete t1;
    delete hv;
}

TEST_F(HtmlVisitorTest, VisitorListItemIsCorrect){
    Article* l1 = new ListItem("list");
    ArticleVisitor* hv = new HtmlVisitor();
    l1->accept(hv);
    ASSERT_EQ(hv->getResult(), "<li>list</li>");

    delete l1;
    delete hv;
}

TEST_F(HtmlVisitorTest, VisitorParagraphIsCorrect){
    ASSERT_EQ(visitor->getResult(), "<div><h1>title</h1><li>list1</li><li>list2</li><span>text</span><div><h2>title2</h2><li>list3</li><li>list4</li><span>sub text</span></div></div>");
}