#include <gtest/gtest.h>

#include "../../src/builder/article_builder.h"
#include "../../src/text.h"
#include "../../src/list_item.h"
#include "../../src/paragraph.h"

class ArticleBuilderTest: public ::testing::Test{
    protected:
        ArticleBuilderTest() {}
        ~ArticleBuilderTest() {}

        void SetUp() override {
            builder = ArticleBuilder::getInstance();
        }

        void TearDown() override {
            // delete builder;
            builder->reset();
        }
    
    ArticleBuilder* builder;
};

TEST_F(ArticleBuilderTest, Creation){
    ASSERT_TRUE(typeid(*builder)==typeid(ArticleBuilder));
}

TEST_F(ArticleBuilderTest, GetInstanceShouldTheSame){
    ArticleBuilder* builder2 = ArticleBuilder::getInstance();
    ASSERT_TRUE(typeid(builder)==typeid(builder2));
}

TEST_F(ArticleBuilderTest, BuildText){
    builder->buildText("text");
    ASSERT_TRUE(typeid(*builder->getArticle())== typeid(Text));
    ASSERT_EQ(builder->getArticle()->getText(), "text");
}

TEST_F(ArticleBuilderTest, BuildListItem){
    builder->buildListItem("listitem");
    ASSERT_TRUE(typeid(*builder->getArticle())== typeid(ListItem));
    ASSERT_EQ(builder->getArticle()->getText(), "listitem");
}

TEST_F(ArticleBuilderTest, BuildParagraphBegin){
    builder->buildParagraphBegin(1, "title1");
    ASSERT_TRUE(typeid(*builder->getArticle())== typeid(Paragraph));
    ASSERT_EQ(builder->getArticle()->getText(), "title1");
}

TEST_F(ArticleBuilderTest, BuildParagraphEnd){
    builder->buildParagraphBegin(1, "title1");
    builder->buildText("text");
    builder->buildListItem("list1");
    builder->buildParagraphEnd();
    
    Iterator* it = builder->getArticle()->createIterator();
    ASSERT_EQ(it->currentItem()->getText(), "text");
    it->next();
    ASSERT_EQ(it->currentItem()->getText(), "list1");

    delete it;
}

TEST_F(ArticleBuilderTest, BuildComplexParagraphEnd){
    builder->buildParagraphBegin(1, "title1");
    builder->buildListItem("list1");
    builder->buildParagraphBegin(2, "title2");
    builder->buildText("text 1");
    builder->buildText("text 2");
    builder->buildParagraphEnd();
    builder->buildParagraphEnd();
    
    Iterator* it = builder->getArticle()->createIterator();
    ASSERT_EQ(it->currentItem()->getText(), "list1");
    it->next();
    ASSERT_EQ(it->currentItem()->getText(), "title2");
    Iterator* innerIt = it->currentItem()->createIterator();
    ASSERT_EQ(innerIt->currentItem()->getText(), "text 1");
    innerIt->next();
    ASSERT_EQ(innerIt->currentItem()->getText(), "text 2");

    delete innerIt;
    delete it;
}

