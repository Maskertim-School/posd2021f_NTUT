#include "../../src/builder/article_parser.h"
#include "../../src/text.h"
#include "../../src/list_item.h"
#include "../../src/paragraph.h"

TEST(ParserTest, Creation){
    ArticleParser* parser = new ArticleParser("./test/data/text.txt");
    ASSERT_TRUE(typeid(*parser)==typeid(ArticleParser));

    delete parser;
}

TEST(ParserTest, ParseText){
    ArticleParser* parser = new ArticleParser("./test/data/text.txt");
    parser->parse();
    ASSERT_TRUE(typeid(*parser->getArticle())==typeid(Text));
    ASSERT_EQ(parser->getArticle()->getText(), "This is a text");

    delete parser;
}

TEST(ParserTest, ParseListItem){
    ArticleParser* parser = new ArticleParser("./test/data/list_item.txt");
    parser->parse();
    ASSERT_TRUE(typeid(*parser->getArticle())==typeid(ListItem));
    ASSERT_EQ(parser->getArticle()->getText(), "This is a list item");

    delete parser;
}

TEST(ParserTest, ParseEmptyParagraph){
    ArticleParser* parser = new ArticleParser("./test/data/empty_paragraph.txt");
    parser->parse();
    ASSERT_TRUE(typeid(*parser->getArticle())==typeid(Paragraph));
    ASSERT_EQ(parser->getArticle()->getText(), "This is an empty paragraph");

    delete parser;
}

TEST(ParserTest, ParseSimpleParagraph){
    ArticleParser* parser = new ArticleParser("./test/data/simple_paragraph.txt");
    parser->parse();
    Iterator* it = parser->getArticle()->createIterator();
    
    ASSERT_EQ(parser->getArticle()->getText(), "This is a simple paragraph");
    ASSERT_EQ(it->currentItem()->getText(), "This is a list item");
    it->next();
    ASSERT_EQ(it->currentItem()->getText(), "This is a text");

    delete parser;
    delete it;
}

TEST(ParserTest, ParseComplexParagraph){
    ArticleParser* parser = new ArticleParser("./test/data/complex_paragraph.txt");
    parser->parse();
    Iterator* it = parser->getArticle()->createIterator();
    
    ASSERT_EQ(parser->getArticle()->getText(), "This is a complex paragraph");
    ASSERT_EQ(parser->getArticle()->getLevel(), 1);
    ASSERT_EQ(it->currentItem()->getText(), "This is a list item");
    it->next();
    ASSERT_EQ(it->currentItem()->getText(), "This is an inner paragraph");
    ASSERT_EQ(it->currentItem()->getLevel(), 2);
    
    Iterator* innerIt = it->currentItem()->createIterator();
    ASSERT_EQ(innerIt->currentItem()->getText(), "This is an inner text");
    innerIt->next();
    ASSERT_EQ(innerIt->currentItem()->getText(), "This is an inner list item");
    it->next();
    ASSERT_EQ(it->currentItem()->getText(), "This is a text");

    delete parser;
    delete it;
    delete innerIt;
}