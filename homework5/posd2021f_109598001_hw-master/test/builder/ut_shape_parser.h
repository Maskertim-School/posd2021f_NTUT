#include "../../src/builder/shape_parser.h"
#include "../../src/compound_shape.h"
#include "../../src/iterator/iterator.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"
#include <math.h>

TEST(ShapeParser, Creation){
    ShapeParser* sp = new ShapeParser("./test/data/simple_compound.txt");

    try{
        // Expected
        ASSERT_TRUE(typeid(*sp)==typeid(ShapeParser));
    }catch(std::string ex){
        std::cout<<ex;
    }

    delete sp;
}

TEST(ShapeParser, BuildCircle){
    ShapeParser* sp = new ShapeParser("./test/data/circle.txt");
    sp->parse();

    // Expected
    ASSERT_NEAR(sp->getShape()->area(), 1.0*1.0*M_PI, 0.001);

    delete sp;
}

TEST(ShapeParser, BuildRectangle){
    ShapeParser* sp = new ShapeParser("./test/data/rectangle.txt");
    sp->parse();

    // Expected
    ASSERT_NEAR(sp->getShape()->area(), 3.14*4.00, 0.001);

    delete sp;
}

TEST(ShapeParser, BuildTriangle){
    ShapeParser* sp = new ShapeParser("./test/data/triangle.txt");
    sp->parse();

    // Expected
    TwoDimensionalVector t1(3.0, 0.0);
    TwoDimensionalVector t2(0.0, 4.0);
    Triangle triangle(t1, t2);
    ASSERT_NEAR(sp->getShape()->area(), triangle.area(), 0.001);

    delete sp;
}

TEST(ShapeParser, BuildEmptyCompound){
    ShapeParser* sp = new ShapeParser("./test/data/empty_compound.txt");
    sp->parse();

    // Expected
    ASSERT_TRUE(typeid(*sp->getShape()) == typeid(CompoundShape));

    delete sp;
}

TEST(ShapeParser, BuildSimpleCompound){
    ShapeParser* sp = new ShapeParser("./test/data/simple_compound.txt");
    sp->parse();

    // Expected
    Iterator* it = sp->getShape()->createIterator();
    it->first();
    ASSERT_TRUE(typeid(*it->currentItem()) == typeid(Circle));
    it->next();
    ASSERT_TRUE(typeid(*it->currentItem()) == typeid(Rectangle));
    it->next();
    ASSERT_TRUE(typeid(*it->currentItem()) == typeid(Triangle));

    delete sp;
    delete it;
}

TEST(ShapeParser, BuildComplexCompound){
    ShapeParser* sp = new ShapeParser("./test/data/complex_compound.txt");
    sp->parse();

    // Expected
    Iterator* it = sp->getShape()->createIterator();
    it->first();
    ASSERT_TRUE(typeid(*it->currentItem()) == typeid(Circle));
    it->next();
    ASSERT_TRUE(typeid(*it->currentItem()) == typeid(Triangle));
    it->next();
    ASSERT_TRUE(typeid(*it->currentItem()) == typeid(CompoundShape));
    Iterator* inner = it->currentItem()->createIterator();
    inner->first();
    ASSERT_TRUE(typeid(*inner->currentItem()) == typeid(Circle));
    inner->next();
    ASSERT_TRUE(typeid(*inner->currentItem()) == typeid(Rectangle));
    inner->next();
    ASSERT_TRUE(typeid(*inner->currentItem()) == typeid(Triangle));

    delete sp;
    delete it;
    delete inner;
}