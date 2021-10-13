#include "../src/list_item.h"

TEST(CaseListItem, GetText){
    ListItem listitem("listitem 1");
    ASSERT_EQ(listitem.getText(), "- listitem 1");
};

TEST(CaseListItem, GetLevel){
    ListItem listitem("listitem 1");
    ASSERT_EQ(listitem.getLevel(), 0);
}

TEST(CaseListItem, ExceptionAdd){
    ListItem listitem("listitem 1");
    try{
        listitem.add(new ListItem("listitem 2"));
    }catch(std::string ex){
        ASSERT_EQ(ex, "not have add() function");
    }
};