#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"
#include "../src/compound_shape.h"
#include "../src/iterator/iterator.h"
#include "../src/iterator/compound_iterator.h"
#include "../src/iterator/null_iterator.h"

/* null Iterator */
TEST(CaseIterator, NullIteratorIsAIterator){
    Shape* circle = new Circle(5.0);

    Iterator* nullIt = circle->createIterator();
    // Expected: null iterator constructs correctly
    ASSERT_EQ(typeid(*nullIt).name(), typeid(NullIterator).name());

    delete nullIt;
    delete circle;
}

TEST(CaseIterator, NullIteratorIsDoneShouldBeTrue){
    Shape* circle = new Circle(5.0);

    Iterator* nullIt = circle->createIterator();
    // Expected: IsDone method of null iterator is always true
    ASSERT_TRUE(nullIt->isDone());

    delete nullIt;
    delete circle;
}

TEST(CaseIterator, NullIteratorThrowsNoNextMethod){
    Shape* circle = new Circle(5.0);

    Iterator* nullIt = circle->createIterator();
    // Expected: next method is not allowed
    try{
        nullIt->next();
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The next method of Null Iterator is not allowed.", msg);
    }

    delete nullIt;
    delete circle;
}

TEST(CaseIterator, NullIteratorThrowsNoCurrentItemMethod){
    Shape* circle = new Circle(5.0);

    Iterator* nullIt = circle->createIterator();
    // Expected: currentItem method is not allowed
    try{
        nullIt->currentItem();
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The currentItem method of Null Iterator is not allowed.", msg);
    }

    delete nullIt;
    delete circle;
}

TEST(CaseIterator, NullIteratorThrowsNoFirstMethod){
    Shape* circle = new Circle(5.0);

    Iterator* nullIt = circle->createIterator();
    // Expected: first method is not allowed
    try{
        nullIt->first();
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The first method of Null Iterator is not allowed.", msg);
    }

    delete nullIt;
    delete circle;
}

/* Iterator of Compound Shape */
TEST(CaseIterator, CompoundIteratorCreation){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    Iterator* csIt = cs->createIterator();

    // Expected: the compound iterator constructs correctly
    ASSERT_EQ(typeid(*csIt).name(), typeid(CompoundIterator<std::list<Shape*>::iterator>).name());

    delete csIt;
    delete cs;
}

TEST(CaseIterator, CompoundIteratorFisrtNoException){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    Iterator* csIt = cs->createIterator();

    // Expected: the first method don't throw exception
    csIt->first();
    SUCCEED();

    delete csIt;
    delete cs;
}

TEST(CaseIterator, CompoundIteratorCurrentItemIsCorrect){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    Iterator* csIt = cs->createIterator();

    // Expected: the first element is circle (using area() to check it is the same or not)
    csIt->first();
    ASSERT_EQ(csIt->currentItem()->area(), circle->area());

    delete csIt;
    delete cs;
}

TEST(CaseIterator, CompoundIteratorNextNoException){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    Iterator* csIt = cs->createIterator();

    // Expected: the second element is rectangle
    csIt->first();
    csIt->next();
    ASSERT_EQ(typeid(*csIt->currentItem()), typeid(*rectangle));

    delete csIt;
    delete cs;
}

TEST(CaseIterator, CompoundIteratorIsDoneMethod){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    Iterator* csIt = cs->createIterator();

    // Expected: the last element is null, check it is null or not
    csIt->first();
    csIt->next();
    csIt->next();
    ASSERT_TRUE(csIt->isDone());

    delete csIt;
    delete cs;
}

TEST(CaseIterator, IteratorOfCompoundShapeThrowNoNextElement){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    Iterator* csIt = cs->createIterator();

    // Expected: the last element is null that means isdone, next methdo can't go ahead
    csIt->first();
    csIt->next();
    csIt->next();
    try{
        csIt->next();
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("No next element can iterate.", msg);
    }

    delete csIt;
    delete cs;
}

TEST(CaseIterator, IteratorOfCompoundShapeThrowCurrentItemIsNull){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    Iterator* csIt = cs->createIterator();

    // Expected: the last element is null, currentItem can't access null object
    csIt->first();
    csIt->next();
    csIt->next();
    try{
        csIt->currentItem();
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("The element is done at the end point.", msg);
    }

    delete csIt;
    delete cs;
}