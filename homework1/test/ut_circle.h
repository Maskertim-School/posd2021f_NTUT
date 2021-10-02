#include "../src/circle.h"
#include <cmath>

TEST(CaseCircle, Area){
    Circle circle(10.0);
    ASSERT_NEAR(circle.area(), 10.0*10.0*M_PI, 0.001);
};

TEST(CaseCircle, Perimeter){
    Circle circle(10.0);
    ASSERT_NEAR(circle.perimeter(), 10.0*2*M_PI, 0.001);
}

TEST(CaseCircle, Info){
    Circle circle(10.0);
    ASSERT_EQ(circle.info(), "Circle (10.00)");
}

TEST(CaseCircle, FailException){
    try{
        Circle circle(0.0);
    }catch(std::string msg){
        ASSERT_EQ("This is not a circle.", msg);
    }
}