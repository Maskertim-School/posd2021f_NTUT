#include "../src/rectangle.h"

TEST(CaseRectangle, Area){
    Rectangle rectangle(10.0, 5.0);
    ASSERT_NEAR(rectangle.area(), 10.0*5.0, 0.001);
    
};

TEST(CaseRectangle, Perimeter){
    Rectangle rectangle(10.0, 5.0);
    ASSERT_NEAR(rectangle.perimeter(), (10.0+5.0)*2.0, 0.001);
}

TEST(CaseRectangle, Info){
    Rectangle rectangle(10.256, 5.544);
    ASSERT_EQ(rectangle.info(), "Rectangle (10.26 5.54)");
}

TEST(CaseRectangle, FailException){
    try{
        Rectangle retangle(-5.0, 5.0);
    }catch(std::string msg){
        ASSERT_EQ("This is not rectangle.", msg);
    }
}