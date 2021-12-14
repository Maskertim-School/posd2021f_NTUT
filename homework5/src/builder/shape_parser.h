#pragma once
#include "../shape.h"
#include <string>
#include <iostream>
#include "../circle.h"
#include <fstream>
#include <sstream>
#include "./scanner.h"

class ShapeParser{
public:
    // `filePath` is a relative path of makefile
    ShapeParser(std::string filePath) {
        auto ss = std::ostringstream{};
        std::ifstream input_file(filePath);

        if(!input_file.is_open()){
            throw std::string("cannot open file");
        }

        ss << input_file.rdbuf();

        scanner = new Scanner(ss.str());
        builder = new ShapeBuilder();
    }

    ~ShapeParser() {
        delete scanner;
        delete builder;
    }

    void parse() {
        std::string token;
        while(!scanner->isDone()){
            try{
                token = scanner->next();
            }catch(std::string ex){
                std::cout << "the scan is ended";
                break;
            }

            if(token=="Circle"){
                double radius = 0.0;
                while(scanner->next() != "(");
                radius = scanner->nextDouble();
                while(scanner->next() != ")");

                builder->buildCircle(radius);
            }else if(token=="Rectangle"){
                double length = 0.0;
                double width = 0.0;
                while(scanner->next() != "(");
                length = scanner->nextDouble();
                scanner->next();
                width = scanner->nextDouble();
                while(scanner->next() != ")");

                builder->buildRectangle(length, width);
            }else if(token=="Triangle"){
                double x1 = 0.0;
                double y1 = 0.0;
                double x2 = 0.0;
                double y2 = 0.0;

                while(scanner->next() != "(");
                while(scanner->next() != "[");
                x1 = scanner->nextDouble();
                while(scanner->next() != ",");
                y1 = scanner->nextDouble();
                while(scanner->next() != "]");
                while(scanner->next() != "[");
                x2 = scanner->nextDouble();
                while(scanner->next() != ",");
                y2 = scanner->nextDouble();
                while(scanner->next() != "]");
                while(scanner->next() != ")");

                builder->buildTriangle(x1, y1, x2, y2);
            }else if(token=="CompoundShape"){
                while(scanner->next() != "{");
                builder->buildCompoundBegin();
            }else if(token=="}"){
                builder->buildCompoundEnd();
            }
        }
    }

    Shape* getShape() {
        return builder->getShape();
    }
private:
    Scanner* scanner;
    ShapeBuilder* builder;
};