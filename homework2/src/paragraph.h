#pragma once

#include <string>
#include "article.h"
#include <vector>
#include <iostream>

class Paragraph : public Article {
   public:
    Paragraph(int level, std::string text): _level(level),_text(text) {
        if(level > 6 || level < 1){
            throw std::string ("not in the range from 1 to 6");
        }
    }

    ~Paragraph() {
        _elements.clear();
    }

    std::string getText() const override {
        std::string _alltext = "";
        // plus the number of '#' following what level 
        for(int i=0; i<_level;i++){
            _alltext += "#";
        }
        // paragraph text format
        _alltext += " "+_text+"\n";

        // check paragraph has elements or not
        if(_elements.empty()){
            // if only paragraph
            return _alltext;
        }else{
            // iterates other components
            for(int i=0; i < _elements.size(); i++){
                _alltext += _elements[i]->getText()+"\n";
            }
        }
        return _alltext.erase(_alltext.size()-1);
    }

    int getLevel() const override {
        return _level;
    }

    void add(Article* content) override {
        // std::cout << typeid(*content).name();
        if(typeid(*content)==typeid(Paragraph)){
            if(_level >= content->getLevel()){
                throw std::string ("low level can't be added in high level");
            }
        }
        _elements.push_back(content);
    }
   private:
    std::string _text;
    int _level;
    std::vector<Article*> _elements = {};
    
    
};