#include "../src/shape.h"
#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/iterator/iterator.h"

TEST(CaseCompoundShape, CompoundShapeWithTwoSimpleShapeCreation){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    // Excepted: first element is circle, second element is rectangle (typeid() to check the same is or not)
    Iterator* it = cs->createIterator();
    it->first();
    ASSERT_EQ(typeid(*it->currentItem()).name(), typeid(*circle).name());
    it->next();
    ASSERT_EQ(typeid(*it->currentItem()).name(), typeid(*rectangle).name());

    // deallocate occupied memory
    delete it;
    delete cs;
}

TEST(CaseCompoundShape, CompoundShapeWithTwoSimpleShapeForArea){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    // Excepted: first element is circle, second element is rectangle
    Iterator* it = cs->createIterator();
    it->first();
    ASSERT_NEAR(circle->area(), it->currentItem()->area(), 0.001);
    it->next();
    ASSERT_NEAR(it->currentItem()->area(), rectangle->area(), 0.001);

    // deallocate occupied memory
    delete it;
    delete cs;
}

TEST(CaseCompoundShape, CompoundShapeWithTwoSimpleShapeForPerimeter){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    // Excepted: first element is circle, second element is rectangle
    Iterator* it = cs->createIterator();
    it->first();
    ASSERT_NEAR(it->currentItem()->perimeter(), circle->perimeter(), 0.001);
    it->next();
    ASSERT_NEAR(it->currentItem()->perimeter(), rectangle->perimeter(), 0.001);

    // deallocate occupied memory
    delete it;
    delete cs;
}

TEST(CaseCompoundShape, CompoundShapeWithTwoSimpleShapeForInfo){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);

    // Excepted: first element is circle, second element is rectangle
    Iterator* it = cs->createIterator();
    it->first();
    ASSERT_EQ(it->currentItem()->info(), circle->info());
    it->next();
    ASSERT_EQ(it->currentItem()->info(), rectangle->info());

    // deallocate occupied memory
    delete it;
    delete cs;
}

TEST(CaseCompoundShape, CompoundShapeWithCompoundShapeForArea){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* cs2 = new CompoundShape();
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle2 = new Circle(3.0);
    cs->addShape(circle);
    cs2->addShape(rectangle);
    cs2->addShape(circle2);
    cs->addShape(cs2);

    // Excepted: first element is circle, second element is compoundshape
    Iterator* it = cs->createIterator();
    it->first();
    ASSERT_NEAR(it->currentItem()->area(), circle->area(), 0.001);
    it->next();
    double expected = rectangle->area()+circle2->area();
    ASSERT_NEAR(it->currentItem()->area(), expected, 0.001);

    delete it;
    delete cs;
    
}

TEST(CaseCompoundShape, CompoundShapeWithCompoundShapeForPerimeter){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* cs2 = new CompoundShape();
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle2 = new Circle(3.0);
    cs->addShape(circle);
    cs2->addShape(rectangle);
    cs2->addShape(circle2);
    cs->addShape(cs2);

    // Excepted: first element is circle, second element is compoundshape
    Iterator* it = cs->createIterator();
    it->first();
    ASSERT_NEAR(it->currentItem()->perimeter(), circle->perimeter(), 0.001);
    it->next();
    double expected = rectangle->perimeter()+circle2->perimeter();
    ASSERT_NEAR(it->currentItem()->perimeter(), expected, 0.001);

    delete it;
    delete cs;
}

TEST(CaseCompoundShape, CompoundShapeWithCompoundShapeForInfo){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* cs2 = new CompoundShape();
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle2 = new Circle(3.0);
    cs->addShape(circle);
    cs2->addShape(rectangle);
    cs2->addShape(circle2);
    cs->addShape(cs2);

    // Expected: compoundshape info
    std::string expected = "CompoundShape\n{\nCircle (5.00)\nCompoundShape\n{\nRectangle (5.00 3.00)\nCircle (3.00)\n}\n}";
    ASSERT_EQ(cs->info(),expected);

    delete cs;
}

TEST(CaseCompoundShape, DeleteShapeWithSimpleShape){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(circle);
    cs->addShape(rectangle);
    cs->deleteShape(circle);

    // Excepted: first element is rectangle due to deleted circle
    Iterator* it = cs->createIterator();
    it->first();
    ASSERT_EQ(typeid(*it->currentItem()).name(), typeid(*rectangle).name());
    it->next();
    ASSERT_TRUE(it->isDone());

    
    delete it;
    delete cs;
}

TEST(CaseCompoundShape, DeleteShapeWithSimpleShapeCheck){
    Shape* cs = new CompoundShape();
    Circle circle(5.0);
    Shape* rectangle = new Rectangle(5.0, 3.0);
    cs->addShape(&circle);
    cs->addShape(rectangle);
    cs->deleteShape(&circle);

    // Excepted: first element is rectangle due to deleted circle
    Iterator* it = cs->createIterator();
    it->first();
    ASSERT_EQ(typeid(*it->currentItem()).name(), typeid(*rectangle).name());
    it->next();
    ASSERT_TRUE(it->isDone());

    std::cout<< cs->info();

    
    delete it;
    delete cs;
}

TEST(CaseCompoundShape, DeleteCompoundShapeWithCompoundShape){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* cs2 = new CompoundShape();
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle2 = new Circle(3.0);
    cs2->addShape(rectangle);
    cs2->addShape(circle);
    cs->addShape(cs2);
    cs->addShape(circle);
    cs->deleteShape(cs2);

    // Excepted: first element is circle due to deleted compoundshape
    Iterator* it = cs->createIterator();
    it->first();
    ASSERT_NEAR(it->currentItem()->area(), circle->area(), 0.001);
    it->next();
    ASSERT_TRUE(it->isDone());

    delete it;
    delete cs;
}

TEST(CaseCompoundShape, DeleteSimpleShapeWithCompoundShape){
    Shape* cs = new CompoundShape();
    Shape* circle = new Circle(5.0);
    Shape* cs2 = new CompoundShape();
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle2 = new Circle(3.0);
    cs2->addShape(rectangle);
    cs2->addShape(circle);
    cs->addShape(cs2);
    cs->addShape(circle);
    cs2->deleteShape(circle);

    // Excepted: delete circle in compoundshape2
    Iterator* it = cs->createIterator();
    it->first();
    // the remaining shape in compoundshape2 is rectangle 
    ASSERT_NEAR(it->currentItem()->area(), rectangle->area(), 0.001);
    it->next();
    // second element is circle
    ASSERT_NEAR(it->currentItem()->area(), circle->area(), 0.001);
    it->next();
    ASSERT_TRUE(it->isDone());

    delete it;
    delete cs;
}

TEST(CaseCompoundShape, DeleteShapeThrowsUnexistedShape){
    Shape* circle = new Circle(5.0);
    Shape* cs = new CompoundShape();
    
    // Excepted: the compound shape don't have delete the shape that it don't own
    try{
        cs->deleteShape(circle);
        FAIL();
    }catch(std::string msg){
        ASSERT_EQ("This type of shape don't find in compoundshape.", msg);
    }

    delete cs;
}