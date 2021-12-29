#include "../../src/builder/article_scanner.h"

TEST(ScannerTest, Creation){
    ArticleScanner* scanner = new ArticleScanner("Text (\"This is a text\")");
    ASSERT_TRUE(typeid(*scanner)==typeid(ArticleScanner));
    delete scanner;
}

TEST(ScannerTest, ScanText){
    ArticleScanner* scanner = new ArticleScanner("Text (\"This is a text\")");
    ASSERT_EQ(scanner->nextToken(), "Text");
    ASSERT_EQ(scanner->nextToken(), "(");
    ASSERT_EQ(scanner->nextStr(), "This is a text");
    ASSERT_EQ(scanner->nextToken(),")");
    delete scanner;
}

TEST(ScannerTest, ScanListItem){
    ArticleScanner* scanner = new ArticleScanner("ListItem (\"This is a list item\")");
    ASSERT_EQ(scanner->nextToken(), "ListItem");
    ASSERT_EQ(scanner->nextToken(), "(");
    ASSERT_EQ(scanner->nextStr(), "This is a list item");
    ASSERT_EQ(scanner->nextToken(),")");
    delete scanner;
}

TEST(ScannerTest, ScanIsDone){
    ArticleScanner* scanner = new ArticleScanner("");
    ASSERT_TRUE(scanner->isDone());
    delete scanner;
}

TEST(ScannerTest, ScanNextTokenThrowWhenIsDone){
    ArticleScanner* scanner = new ArticleScanner("");
    try{
        scanner->nextToken();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "the scan is ended.");
    }
    delete scanner;
}

TEST(ScannerTest, ScanNextStrThrowWhenIsDone){
    ArticleScanner* scanner = new ArticleScanner("");
    try{
        scanner->nextStr();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "the scan is ended.");
    }
    delete scanner;
}

TEST(ScannerTest, ScanNextIntThrowWhenIsDone){
    ArticleScanner* scanner = new ArticleScanner("");
    try{
        scanner->nextInt();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "the scan is ended.");
    }
    delete scanner;
}

TEST(ScannerTest, ScanEmptyParagraph){
    ArticleScanner* scanner = new ArticleScanner("Paragraph (1 \"This is an empty paragraph\") {}");
    ASSERT_EQ(scanner->nextToken(), "Paragraph");
    ASSERT_EQ(scanner->nextToken(), "(");
    ASSERT_EQ(scanner->nextInt(), 1);
    ASSERT_EQ(scanner->nextStr(), "This is an empty paragraph");
    ASSERT_EQ(scanner->nextToken(), ")");
    ASSERT_EQ(scanner->nextToken(), "{");
    ASSERT_EQ(scanner->nextToken(), "}");

    delete scanner;
}

TEST(ScannerTest, ScanSimpleParagraph){
    std::string test = "Paragraph (1 \"This is an empty paragraph\") {\n"
                        "\tListItem (\"This is a list item\")\n"
                        "\tText (\"This is a text\")\n"
                        "}";
    
    ArticleScanner* scanner = new ArticleScanner(test);
    ASSERT_EQ(scanner->nextToken(), "Paragraph");
    ASSERT_EQ(scanner->nextToken(), "(");
    ASSERT_EQ(scanner->nextInt(), 1);
    ASSERT_EQ(scanner->nextStr(), "This is an empty paragraph");
    ASSERT_EQ(scanner->nextToken(), ")");
    ASSERT_EQ(scanner->nextToken(), "{");
    ASSERT_EQ(scanner->nextToken(), "ListItem");
    ASSERT_EQ(scanner->nextToken(), "(");
    ASSERT_EQ(scanner->nextStr(), "This is a list item");
    ASSERT_EQ(scanner->nextToken(), ")");
    ASSERT_EQ(scanner->nextToken(), "Text");
    ASSERT_EQ(scanner->nextToken(), "(");
    ASSERT_EQ(scanner->nextStr(), "This is a text");
    ASSERT_EQ(scanner->nextToken(), ")");
    ASSERT_EQ(scanner->nextToken(), "}");

    delete scanner;
}

TEST(ScannerTest, ScanIllegalWordShouldIgnore){
    ArticleScanner* scanner = new ArticleScanner("I ListItem eee {\"string\"555\"next\"}too6a");

    ASSERT_EQ(scanner->nextToken(), "ListItem");
    ASSERT_EQ(scanner->nextStr(), "string");
    ASSERT_EQ(scanner->nextToken(), "}");
    ASSERT_EQ(scanner->nextInt(), 6);

    delete scanner;
}