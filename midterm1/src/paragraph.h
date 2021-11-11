#pragma once

#include "article.h"
#include <string>
#include "iterator/iterator.h"
#include "iterator/compound_iterator.h"
#include "paragraph.h"
#include "visitor/article_visitor.h"
#include <list>

class Paragraph : public Article {
   public:
    Paragraph(int level, std::string text): _level(level), _text(text) {
        if(level > 6 || level < 1){
            throw std::string("This level is not allowed.");
        }
    }

    ~Paragraph() {
        for (std::list<Article*>::iterator it=_articles.begin(); it!=_articles.end(); ++it){
            delete *it;
        }

    }

    std::string getText() const override {
        return _text;
    }

    int getLevel() const override {
        return _level;
    }

    Iterator* createIterator() override {
        return new CompoundIterator<std::list<Article*>::iterator>(_articles.begin(), _articles.end());
    }

    void add(Article* content) override {
        if(typeid(*content)==typeid(Paragraph)){
            if(content->getLevel() <= _level){
                throw std::string("Level is greater or equal. That can't be added.");
            }
        }
        _articles.push_back(content);
    }

    void accept(ArticleVisitor* visitor) override {
        visitor->visitParagraph(this);
    }
private:
    std::string _text;
    int _level;
    std::list<Article*> _articles;
};