#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include "article_scanner.h"
#include "article_parser.h"

class ArticleParser {
public:
    // `filePath` is a relative path of makefile
    ArticleParser(std::string filePath) { 
        auto ss = std::ostringstream{};
        std::ifstream input_file(filePath);

        if(!input_file.is_open()){
            throw std::string("cannot open file");
        }

        ss << input_file.rdbuf();

        scanner = new ArticleScanner(ss.str());
    }

    ~ArticleParser() { 
        delete scanner;
        builder->reset();
    }

    void parse() { 
        std::string token;
        while(!scanner->isDone()){
            try{
                token = scanner->nextToken();
            }catch(std::string ex){
                throw std::string ("the scan is ended");
                break;
            }

            if(token=="Text"){
                std::string text = "";
                while(scanner->nextToken() != "(");
                text = scanner->nextStr();
                while(scanner->nextToken() != ")");
                
                builder->buildText(text);
            }else if(token=="ListItem"){
                std::string text = "";
                while(scanner->nextToken() != "(");
                text = scanner->nextStr();
                while(scanner->nextToken() != ")");
                
                builder->buildListItem(text);
            }else if(token=="Paragraph"){
                std::string text = "";
                int level = 0;
                while(scanner->nextToken() != "(");
                level = scanner->nextInt();
                text = scanner->nextStr();
                while(scanner->nextToken() != ")");

                while(scanner->nextToken() != "{");
                builder->buildParagraphBegin(level, text);
            }else if(token=="}"){
                builder->buildParagraphEnd();
            }
        }
    }

    Article* getArticle() { 
        return builder->getArticle();
    }
private:
    ArticleScanner* scanner;
    ArticleBuilder* builder = ArticleBuilder::getInstance();
};