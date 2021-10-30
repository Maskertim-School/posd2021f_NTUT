#include "../src/circle.h"
#include <cmath>
#include "../src/iterator/iterator.h"

/* Follow the Homework 1 */
TEST(CaseCirecle, Creation){
    Circle circle(10.0);
    ASSERT_EQ(typeid(circle), typeid(Circle));
}

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

TEST(CaseCircle, ZeroException){
    try{
        Circle circle(0.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The negative or zero radius isn't allowed.", msg);
    }
}

TEST(CaseCircle, NegativeException){
    try{
        Circle circle(-5.0);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The negative or zero radius isn't allowed.", msg);
    }
}

/* Other operation (e.g., add, delete) */

TEST(CaseCircle, AddShapeException){
    Shape* circle = new Circle(5.0);
    Shape* circle2 = new Circle(3.0);
    try{
        circle->addShape(circle2);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("Uncomposite shape don't have method of addShape.", msg);
    }
}

TEST(CaseCircle, DeleteShapeException){
    Shape* circle = new Circle(5.0);
    Shape* circle2 = new Circle(3.0);
    try{
        circle->deleteShape(circle2);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("Uncomposite shape don't have method of deleteShape.", msg);
    }
}

TEST(CaseCircle, IsDoneOfIteratorShouldBeTrue){
    Shape* circle = new Circle(5.0);
    Iterator* nit = circle->createIterator();
    
    ASSERT_TRUE(nit->isDone());
}

TEST(CaseCircle, CurrentItemOfIteratorShouldBeThrowException){
    Shape* circle = new Circle(5.0);
    Iterator* nit = circle->createIterator();
    
    try{
        nit->currentItem();
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The currentItem method of Null Iterator is not allowed.", msg);
    }
}