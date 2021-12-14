#include "../../src/builder/scanner.h"
#include <string>

TEST(CaseScanner, Creation){
    std::string input = "Circle 3.0";
    Scanner* s = new Scanner(input);
    
    // Expected
    ASSERT_TRUE(typeid(*s)==typeid(Scanner));

    delete s;
}

TEST(CaseScanner, ScanIgnoreIllegalWord){
    std::string input = "I Circle eee ,tt{t3.14159.324asd";
    Scanner* s = new Scanner(input);
    
    // Expected
    ASSERT_EQ(s->next(), "Circle");
    ASSERT_EQ(s->next(), ",");
    ASSERT_EQ(s->next(), "{");
    ASSERT_NEAR(s->nextDouble(), 3.14159, 0.001);

    delete s;
}

TEST(CaseScanner, ScanCircleIsCorrect){
    std::string input = "Circle 3.0";
    Scanner* s = new Scanner(input);
    
    // Expected
    ASSERT_EQ(s->next(), "Circle");
    ASSERT_NEAR(s->nextDouble(), 3.0, 0.001);

    delete s;
}

TEST(CaseScanner, ScanRectangleIsCorrect){
    std::string input = "Rectangle (3.0, 4.0)";
    Scanner* s = new Scanner(input);
    
    // Expected
    ASSERT_EQ(s->next(), "Rectangle");
    ASSERT_EQ(s->next(), "(");
    ASSERT_NEAR(s->nextDouble(), 3.0, 0.001);
    ASSERT_EQ(s->next(), ",");
    ASSERT_NEAR(s->nextDouble(), 4.0, 0.001);
    ASSERT_EQ(s->next(), ")");

    delete s;
}

TEST(CaseScanner, ScanTriangleIsCorrect){
    std::string input = "Triangle ([3, 0] [0.000, 4.0])";
    Scanner* s = new Scanner(input);

    // Expected
    ASSERT_EQ(s->next(), "Triangle");
    ASSERT_EQ(s->next(), "(");
    ASSERT_EQ(s->next(), "[");
    ASSERT_NEAR(s->nextDouble(), 3.0, 0.001);
    ASSERT_EQ(s->next(), ",");
    ASSERT_NEAR(s->nextDouble(), 0.0, 0.001);
    ASSERT_EQ(s->next(), "]");

    delete s;
}

TEST(CaseScanner, ScanCompoundSimpleIsCorrect){
    std::string input = "CompoundShape {\n  Circle (1.0)\n  Rectangle (3.14 4.00)\n}";
    Scanner* s = new Scanner(input);

    // Expected
    ASSERT_EQ(s->next(), "CompoundShape");
    ASSERT_EQ(s->next(), "{");
    ASSERT_EQ(s->next(), "Circle");
    ASSERT_EQ(s->next(), "(");
    ASSERT_EQ(s->nextDouble(), 1.0);
    ASSERT_EQ(s->next(), ")");
    ASSERT_EQ(s->next(), "Rectangle");
    ASSERT_EQ(s->next(), "(");
    ASSERT_NEAR(s->nextDouble(), 3.14, 0.001);
    ASSERT_NEAR(s->nextDouble(), 4.00, 0.001);
    ASSERT_EQ(s->next(), ")");
    ASSERT_EQ(s->next(), "}");

    delete s;
}

TEST(CaseScanner, ScanCompoundComplexIsCorrect){
    std::string input = "CompoundShape {\n"
                        "  Circle (1.0)\n"
                        "  Rectangle (3.14 4.00)\n"
                        "  CompoundShape {\n"
                        "    Circle (1.0)\n"
                        "    Triangle ([3,0] [0,4])\n"
                        "  }\n"
                        "}";
    Scanner* s = new Scanner(input);

    // Expected
    ASSERT_EQ(s->next(), "CompoundShape");
    ASSERT_EQ(s->next(), "{");
    ASSERT_EQ(s->next(), "Circle");
    ASSERT_EQ(s->next(), "(");
    ASSERT_EQ(s->nextDouble(), 1.0);
    ASSERT_EQ(s->next(), ")");
    ASSERT_EQ(s->next(), "Rectangle");
    ASSERT_EQ(s->next(), "(");
    ASSERT_NEAR(s->nextDouble(), 3.14, 0.001);
    ASSERT_NEAR(s->nextDouble(), 4.00, 0.001);
    ASSERT_EQ(s->next(), ")");
    ASSERT_EQ(s->next(), "CompoundShape");
    ASSERT_EQ(s->next(), "{");
    ASSERT_EQ(s->next(), "Circle");
    ASSERT_EQ(s->next(), "(");
    ASSERT_EQ(s->nextDouble(), 1.0);
    ASSERT_EQ(s->next(), ")");
    ASSERT_EQ(s->next(), "Triangle");
    ASSERT_EQ(s->next(), "(");
    ASSERT_EQ(s->next(), "[");
    ASSERT_NEAR(s->nextDouble(), 3.00, 0.001);
    ASSERT_EQ(s->next(), ",");
    ASSERT_NEAR(s->nextDouble(), 0.00, 0.001);
    ASSERT_EQ(s->next(), "]");
    ASSERT_EQ(s->next(), "[");
    ASSERT_NEAR(s->nextDouble(), 0.00, 0.001);
    ASSERT_EQ(s->next(), ",");
    ASSERT_NEAR(s->nextDouble(), 4.00, 0.001);
    ASSERT_EQ(s->next(), "]");
    ASSERT_EQ(s->next(), ")");
    ASSERT_EQ(s->next(), "}");
    ASSERT_EQ(s->next(), "}");


    delete s;
}

TEST(CaseScanner, NextTokenWithComplexInput){
    std::string input = "Circle eee ,! (2.0";
    Scanner* s = new Scanner(input);
    
    // Expected
    ASSERT_EQ(s->next(), "Circle");
    ASSERT_EQ(s->next(), ",");
    ASSERT_EQ(s->next(), "(");

    delete s;
}

TEST(CaseScanner, NextTokenThrowInputIsEnded){
    std::string input = "  Im";
    Scanner* s = new Scanner(input);
    
    // Expected
    try{
        s->next();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "the scan is ended.");
    }

    delete s;
}

TEST(CaseScanner, IsDoneWorking){
    std::string input = "  Im";
    Scanner* s = new Scanner(input);
    
    // Expected
    try{
        s->next();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "the scan is ended.");
    }

    ASSERT_TRUE(s->isDone());

    delete s;
}

TEST(CaseScanner, NextDoubleWithSimple){
    std::string input = "Circle 3.0";
    Scanner* s = new Scanner(input);
    s->next();

    // Expected
    ASSERT_NEAR(s->nextDouble(), 3.0, 0.001);
}

TEST(CaseScanner, NextDoubleWithComplexInput){
    std::string input = "Circle eee ,! (2.0 tt4";
    Scanner* s = new Scanner(input);
    
    // Expected
    ASSERT_EQ(s->next(), "Circle");
    ASSERT_EQ(s->next(), ",");
    ASSERT_EQ(s->next(), "(");
    ASSERT_NEAR(s->nextDouble(), 2.0, 0.001);

    delete s;
}

TEST(CaseScanner, NextDoubleThrowInputIsEnded){
    std::string input = "  Circle 5.0";
    Scanner* s = new Scanner(input);
    s->next();
    s->nextDouble();

    // Expected
    try{
        s->nextDouble();
        FAIL();
    }catch(std::string ex){
        ASSERT_EQ(ex, "the scan is ended.");
    }

    delete s;
}