#include <gtest/gtest.h>
#include "../src/twoDimensionVector.h"

class TwoDimensionVectorTest: public ::testing::Test{
    protected:
        TwoDimensionVectorTest(){}
        ~TwoDimensionVectorTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            vec1 = new TwoDimensionVector(3.0, 4.0);
            vec2 = new TwoDimensionVector(5.0, 12.0);
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete vec1;
            delete vec2;
        }

    // Class members declared here can be used by all tests in the test suite
    TwoDimensionVector* vec1;
    TwoDimensionVector* vec2;
};

TEST_F(TwoDimensionVectorTest, Creation){
    // Expected
    ASSERT_TRUE(typeid(*vec1)==typeid(TwoDimensionVector));
    ASSERT_TRUE(typeid(*vec2)==typeid(TwoDimensionVector));
}

TEST_F(TwoDimensionVectorTest, XIsCorrect){
    // Expected
    ASSERT_EQ(vec1->x(), 3.0);
}

TEST_F(TwoDimensionVectorTest, YIsCorrect){
    // Expected
    ASSERT_EQ(vec1->y(), 4.0);
}

TEST_F(TwoDimensionVectorTest, LengthIsCorrect){
    // Expected
    ASSERT_NEAR(vec1->length(), 5.0, 0.001);
}

TEST_F(TwoDimensionVectorTest, DotIsCorrect){
    // Expected
    ASSERT_NEAR(vec1->dot(*vec2), 3.0*5.0+4.0*12.0, 0.001);
}

TEST_F(TwoDimensionVectorTest, CrossIsCorrect){
    // Expected
    ASSERT_NEAR(vec1->cross(*vec2), 3.0*12.0-5.0*4.0, 0.001);
}

TEST_F(TwoDimensionVectorTest, SubtractIsCorrect){
    // Logic
    TwoDimensionVector result = vec1->subtract(*vec2);

    // Expected
    ASSERT_NEAR(result.x(), -2.0, 0.001);
    ASSERT_NEAR(result.y(), -8.0, 0.001);
}

TEST_F(TwoDimensionVectorTest, InfoIsCorrect){
    // Expected
    ASSERT_EQ(vec1->info(), "TwoDimensionVector (3.00, 4.00)");
}

TEST_F(TwoDimensionVectorTest, CreationThrowsZeroVector){
    // Expected
    try{
        TwoDimensionVector v(0.0, 0.0);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Vector's value can't all be zero.");
    } 
}