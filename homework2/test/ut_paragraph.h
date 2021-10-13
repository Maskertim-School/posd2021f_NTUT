#include "../src/paragraph.h"
#include "../src/list_item.h"
#include "../src/text.h"
#include <iostream>


TEST(CaseParagraph, GetTextAndLevel){
    Paragraph paragraph(1, "paragraph 1");
    ASSERT_EQ(paragraph.getText(), "# paragraph 1\n");
    ASSERT_EQ(paragraph.getLevel(), 1);
};

TEST(CaseParagraph, AddArticle){
    Paragraph* paragraph = new Paragraph(1, "paragraph 1");
    ListItem* listitem1 = new ListItem("listitem 1");
    ListItem* listitem2 = new ListItem("listitem 2");
    Text* text1 = new Text("text 1");

    // business logic
    paragraph->add(listitem1);
    paragraph->add(listitem2);
    paragraph->add(text1);

    // expected
    std::string expected = "# paragraph 1\n"
                            "- listitem 1\n"
                            "- listitem 2\n"
                            "text 1";
    ASSERT_EQ(paragraph->getText(), expected);
    
};

TEST(CaseParagraph, AddArticleWithParagraph){
    Paragraph* paragraph1 = new Paragraph(1, "paragraph 1");
    ListItem* listitem1 = new ListItem("listitem 1");
    ListItem* listitem2 = new ListItem("listitem 2");
    Text* text1 = new Text("text 1");
    Paragraph* paragraph2 = new Paragraph(2, "paragraph 2");
    ListItem* listitem3 = new ListItem("listitem 3");
    ListItem* listitem4 = new ListItem("listitem 4");

    // business logic
    paragraph1->add(listitem1);
    paragraph1->add(listitem2);
    paragraph1->add(text1);

    paragraph1->add(paragraph2);
    paragraph2->add(listitem3);
    paragraph2->add(listitem4);

    // expected
    std::string expected = "# paragraph 1\n"
                            "- listitem 1\n"
                            "- listitem 2\n"
                            "text 1\n"
                            "## paragraph 2\n"
                            "- listitem 3\n"
                            "- listitem 4";
    ASSERT_EQ(paragraph1->getText(), expected);
    
};

TEST(CaseParagraph, ExceptionLevelOfParagraph){
    try{
        Paragraph* paragraph1 = new Paragraph(1, "paragraph 1");
        ListItem* listitem1 = new ListItem("listitem 1");
        Paragraph* paragraph1_1 = new Paragraph(1, "paragraph 2");
        ListItem* listitem3 = new ListItem("listitem 3");

        paragraph1->add(listitem1);
        paragraph1_1->add(listitem3);
        // need to throw exceptions
        paragraph1_1->add(paragraph1);
    }catch(std::string ex){
        ASSERT_EQ("low level can't be added in high level", ex);
    }
};

TEST(CaseParagraph, ExceptionMorethan6){
    try{
        Paragraph paragraph(7, "paragraph 1");
    }catch(std::string ex){
        ASSERT_EQ(ex, "not in the range from 1 to 6");
    }
};

TEST(CaseParagraph, ExceptionLessThan1){
    try{
        Paragraph paragraph(0, "paragraph 1");
    }catch(std::string ex){
        ASSERT_EQ(ex, "not in the range from 1 to 6");
    }
};