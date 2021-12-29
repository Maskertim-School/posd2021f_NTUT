#pragma once

#include <gtest/gtest.h>
#include "../../src/visitor/markdown_visitor.h"
#include "../../src/visitor/article_visitor.h"
#include "../../src/paragraph.h"
#include "../../src/article.h"
#include "../../src/list_item.h"
#include "../../src/text.h"

class MarkdownVisitorTest: public ::testing::Test {
    protected:
        MarkdownVisitorTest(){}
        ~MarkdownVisitorTest(){}
        
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
            visitor = new MarkdownVisitor();
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

TEST_F(MarkdownVisitorTest, Creation){
    ASSERT_TRUE(typeid(*visitor)==typeid(MarkdownVisitor));
}

TEST_F(MarkdownVisitorTest, VisitorTextIsCorrect){
    Article* t1 = new Text("text");
    ArticleVisitor* mv = new MarkdownVisitor();
    t1->accept(mv);
    ASSERT_EQ(mv->getResult(), "text\n");

    delete t1;
    delete mv;
}

TEST_F(MarkdownVisitorTest, VisitorListItemIsCorrect){
    Article* l1 = new ListItem("list");
    ArticleVisitor* mv = new MarkdownVisitor();
    l1->accept(mv);
    ASSERT_EQ(mv->getResult(), "- list\n");

    delete l1;
    delete mv;
}

TEST_F(MarkdownVisitorTest, VisitorComplexParagraphIsCorrect){
    std::string expected = "# title\n"
                            "- list1\n"
                            "- list2\n"
                            "text\n"
                            "## title2\n"
                            "- list3\n"
                            "- list4\n"
                            "sub text\n";
    ASSERT_EQ(visitor->getResult(), expected);
    
}

TEST_F(MarkdownVisitorTest, VisitorSimpleParagraphIsCorrect){
    Article* p1 = new Paragraph(1, "p1");
    p1->add(new ListItem("list1"));
    p1->add(new Text("text1"));

    std::string test = "# p1\n"
                        "- list1\n"
                        "text1\n";

    ArticleVisitor* mv = new MarkdownVisitor();
    p1->accept(mv);
    ASSERT_EQ(mv->getResult(), test);

    delete p1;
    delete mv;
}

TEST_F(MarkdownVisitorTest, VisitorEmptyParagraphIsCorrect){
    Article* p1 = new Paragraph(1, "p1");

    std::string test = "# p1\n";

    ArticleVisitor* mv = new MarkdownVisitor();
    p1->accept(mv);
    ASSERT_EQ(mv->getResult(), test);

    delete p1;
    delete mv;
}