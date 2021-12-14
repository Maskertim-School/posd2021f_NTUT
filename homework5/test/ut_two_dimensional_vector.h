#include <gtest/gtest.h>
#include "../src/two_dimensional_vector.h"

class TwoDimensionalVectorTest: public ::testing::Test{
    protected:
        TwoDimensionalVectorTest(){}
        ~TwoDimensionalVectorTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            vec1 = new TwoDimensionalVector(3.0, 4.0);
            vec2 = new TwoDimensionalVector(5.0, 12.0);
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete vec1;
            delete vec2;
        }

    // Class members declared here can be used by all tests in the test suite
    TwoDimensionalVector* vec1;
    TwoDimensionalVector* vec2;
};

TEST_F(TwoDimensionalVectorTest, Creation){
    // Expected
    ASSERT_TRUE(typeid(*vec1)==typeid(TwoDimensionalVector));
    ASSERT_TRUE(typeid(*vec2)==typeid(TwoDimensionalVector));
}

TEST_F(TwoDimensionalVectorTest, XIsCorrect){
    // Expected
    ASSERT_EQ(vec1->x(), 3.0);
}

TEST_F(TwoDimensionalVectorTest, YIsCorrect){
    // Expected
    ASSERT_EQ(vec1->y(), 4.0);
}

TEST_F(TwoDimensionalVectorTest, LengthIsCorrect){
    // Expected
    ASSERT_NEAR(vec1->length(), 5.0, 0.001);
}

TEST_F(TwoDimensionalVectorTest, DotIsCorrect){
    // Expected
    ASSERT_NEAR(vec1->dot(*vec2), 3.0*5.0+4.0*12.0, 0.001);
}

TEST_F(TwoDimensionalVectorTest, CrossIsCorrect){
    // Expected
    ASSERT_NEAR(vec1->cross(*vec2), 3.0*12.0-5.0*4.0, 0.001);
}

TEST_F(TwoDimensionalVectorTest, SubtractIsCorrect){
    // Logic
    TwoDimensionalVector result = vec1->subtract(*vec2);

    // Expected
    ASSERT_NEAR(result.x(), -2.0, 0.001);
    ASSERT_NEAR(result.y(), -8.0, 0.001);
}

TEST_F(TwoDimensionalVectorTest, InfoIsCorrect){
    // Expected
    ASSERT_EQ(vec1->info(), "[3.00,4.00]");
}

TEST_F(TwoDimensionalVectorTest, InfoRoundingUpIsCorrect){
    // // Expected
    TwoDimensionalVector v1(2.995, 0.00);
    ASSERT_EQ(v1.info(), "[3.00,0.00]");
}

TEST_F(TwoDimensionalVectorTest, CreationThrowsZeroVector){
    // Expected
    try{
        TwoDimensionalVector v(0.0, 0.0);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Vector's value can't all be zero.");
    } 
}