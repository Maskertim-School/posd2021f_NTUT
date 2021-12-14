#pragma once

#include <string>

#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"
#include "../iterator/iterator.h"

class ShapeInfoVisitor : public ShapeVisitor {
public:
    void visitCircle(Circle* circle) {
        result = circle->info() + "\n";
    }
    void visitRectangle(Rectangle* rectangle) {
        result = rectangle->info() + "\n";
    }
    void visitTriangle(Triangle* triangle) {
        result = triangle->info() + "\n";
    }
    void visitCompoundShape(CompoundShape* compoundShape) {
        Iterator* it = compoundShape->createIterator();
        // no element in compound shape
        if(it->isDone()) {
            result = "CompoundShape {\n}\n";
        }else{
            std::string alltext = compoundShape->info()+" {\n";
            std::string indent = "";

            if(!it->isDone()){
                depth += 1;
                for(int i=0; i<depth; i++){
                    indent += "  ";
                }
            }

            // iterator all elements in compound shape
            for(it->first();!it->isDone();it->next()){
                it->currentItem()->accept(this);
                alltext += indent + getResult();
            }

            depth -= 1;
            indent = "";
            for(int i=0; i<depth; i++){
                indent += "  ";
            }
            
            result = alltext + indent + "}\n";
        }
    }
    std::string getResult() {
        return result;
    }

private:
    int depth = 0;
    std::string result = "";
};
