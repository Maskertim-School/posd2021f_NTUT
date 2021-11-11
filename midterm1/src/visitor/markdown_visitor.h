#pragma once

#include "article_visitor.h"
#include "../list_item.h"
#include "../text.h"
#include "../paragraph.h"
#include <string>

class MarkdownVisitor : public ArticleVisitor {
   public:
    void visitListItem(ListItem* li) override{
        _result = "- "+li->getText()+"\n";
    };

    void visitText(Text* t) override{
        _result =  t->getText()+"\n";
    };

    void visitParagraph(Paragraph* p) override{
        std::string _alltext = "";
        // plus the number of '#' following what level 
        for(int i=0; i<p->getLevel();i++){
            _alltext += "#";
        }

        // paragraph text format
        _alltext += " "+p->getText()+"\n";

        Iterator* it = p->createIterator();

        // check paragraph has elements or not
        if(it->isDone()){
            // if only paragraph
            _result = _alltext;
        }else{
            /* iterates other components old version */
            // for(int i=0; i < _elements.size(); i++){
            //     _alltext += _elements[i]->getText()+"\n";
            // }
            /* iterates other components by 'auto' */
            for(it->first(); !it->isDone(); it->next()){
                it->currentItem()->accept(this);
                _alltext += getResult();
            }
        }

        _result = _alltext;

        delete it;
    };

    std::string getResult() const override {
        return _result;
    }

private:
    std::string _result;
};