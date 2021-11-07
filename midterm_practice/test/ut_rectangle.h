#pragma once

#include <gtest/gtest.h>
#include "../src/rectangle.h"

class RectangleTest: public ::testing::Test {
    protected:
        RectangleTest(){}
        ~RectangleTest(){}
        
        void SetUp() override{
            // Code here will be called immediately after the constructor (right
            // before each test)
            rec = new Rectangle(10.0, 2.0);
        }

        void TearDown() override{
            // Code here will be called immediately after each test (right
            // before the destructor).
            delete rec;
        }

    // Class members declared here can be used by all tests in the test suite
    Shape* rec;
};

TEST_F(RectangleTest, Creation){
    // Expected
    ASSERT_TRUE(typeid(*rec)==typeid(Rectangle));
}

TEST_F(RectangleTest, AreaIsCorrect){
    // Expected
    ASSERT_EQ(rec->area(), 10.0*2.0);
}

TEST_F(RectangleTest, PerimeterIsCorrect){
    // Expected
    ASSERT_EQ(rec->perimeter(), (10.0+2.0)*2.0);
}

TEST_F(RectangleTest, IntoIsCorrect){
    // Expected
    ASSERT_EQ(rec->info(), "Rectangle (10.00, 2.00)");
}

TEST_F(RectangleTest, CreationThrowsZeroWidth){
    // Expected
    try{
        Rectangle r(0.0, 2.0);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Width or length can't be negative or zero.");
    }
}

TEST_F(RectangleTest, CreationThrowsNegativeWidth){
    // Expected
    try{
        Rectangle r(-5.0, 2.0);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Width or length can't be negative or zero.");
    }
}

TEST_F(RectangleTest, CreationThrowsZeroLength){
    // Expected
    try{
        Rectangle r(10.0, 0.0);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Width or length can't be negative or zero.");
    }
}

TEST_F(RectangleTest, CreationThrowsNegativeLength){
    // Expected
    try{
        Rectangle r(10.0, -2.0);
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Width or length can't be negative or zero.");
    }
}

TEST_F(RectangleTest, AddShapeThrowsException){
    // Expected
    try{
        rec->addShape(new Rectangle(5.0, 2.0));
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Basic Shape don't have addShape().");
    }
}

TEST_F(RectangleTest, DeleteShapeThrowsException){
    // Expected
    try{
        rec->deleteShape(new Rectangle(5.0, 2.0));
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "Basic Shape don't have deleteShape().");
    }
}