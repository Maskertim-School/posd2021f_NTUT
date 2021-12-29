#pragma once

#include "article_visitor.h"
#include "../list_item.h"
#include "../text.h"
#include "../paragraph.h"
#include "../iterator/iterator.h"
#include <string>
#include <iostream>

class HtmlVisitor : public ArticleVisitor {
   public:
    void visitListItem(ListItem* li) override{
        _result = "<li>"+li->getText()+"</li>";
    };

    void visitText(Text* t) override{
        _result = "<span>"+t->getText()+"</span>";
    };

    void visitParagraph(Paragraph* p) override{
        std::string paragrapt_str = "<h"+ std::to_string(p->getLevel()) + ">" + p->getText() + "</h"+ std::to_string(p->getLevel())+">";
        std::string middle = "";
        Iterator* it = p->createIterator();
        if(!it->isDone()){
            for(it->first();!it->isDone();it->next()){
                it->currentItem()->accept(this);
                middle += getResult();
            }
        }
        
        _result = "<div>" + paragrapt_str + middle +"</div>";

        delete it;
    };

    std::string getResult() const override {
        return _result;
    }
private:
    std::string _result;
};