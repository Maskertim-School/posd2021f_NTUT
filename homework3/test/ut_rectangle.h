
#include "../src/rectangle.h"

/* Follow the Homework 1 */
TEST(CaseRectangle, Creation){
    Rectangle rectangle(10.0, 5.0);
    ASSERT_EQ(typeid(rectangle), typeid(Rectangle));
}

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

TEST(CaseRectangle, LengthZeroException){
    try{
        Rectangle retangle(0.0, 5.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The negative or zero length or width isn't allow.", msg);
    }
}

TEST(CaseRectangle, LengthNegativeException){
    try{
        Rectangle retangle(-5.0, 5.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The negative or zero length or width isn't allow.", msg);
    }
}

TEST(CaseRectangle, WidthZeroException){
    try{
        Rectangle retangle(5.0, 0.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The negative or zero length or width isn't allow.", msg);
    }
}

TEST(CaseRectangle, WidthNegativeException){
    try{
        Rectangle retangle(5.0, -5.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The negative or zero length or width isn't allow.", msg);
    }
}

/* other operations */

TEST(CaseRectangle, AddShapeException){
    Shape* rectangle = new Rectangle(5.0, 5.0);
    Shape* rectangle2 = new Rectangle(3.0, 3.0);
    try{
        rectangle->addShape(rectangle2);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("Uncomposite shape don't have method of addShape.", msg);
    }
}

TEST(CaseRectangle, DeleteShapeException){
    Shape* rectangle = new Rectangle(5.0, 5.0);
    Shape* rectangle2 = new Rectangle(3.0, 3.0);
    try{
        rectangle->deleteShape(rectangle2);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("Uncomposite shape don't have method of deleteShape.", msg);
    }
}

TEST(CaseRectangle, IsDoneOfIteratorShouldBeTrue){
    Shape* rectangle = new Rectangle(5.0, 10.0);
    Iterator* nit = rectangle->createIterator();
    
    ASSERT_TRUE(nit->isDone());
}

TEST(CaseRectangle, CurrentItemOfIteratorShouldBeThrowException){
    Shape* rectangle = new Rectangle(5.0, 10.0);
    Iterator* nit = rectangle->createIterator();
    
    try{
        nit->currentItem();
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The currentItem method of Null Iterator is not allowed.", msg);
    }
}