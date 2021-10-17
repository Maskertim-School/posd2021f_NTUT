#include "../src/text.h"

TEST(CaseText, GetText){
    Text text("text 1");
    ASSERT_EQ(text.getText(), "text 1");
};

TEST(CaseText, GetLevel){
    Text text("text 1");
    ASSERT_EQ(text.getLevel(), 0);
};

TEST(CaseText, ExceptionAdd){
    Text text("text 1");
    try{
        text.add(new Text("text 2"));
        FAIL(); // if not throw exceptions, the test is error
    }catch(std::string ex){
        ASSERT_EQ(ex, "not have add() function");
    }
};