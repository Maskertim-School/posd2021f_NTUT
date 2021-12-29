#pragma once

#include <stack>
#include "../article.h"
#include "../text.h"
#include "../list_item.h"
#include "../paragraph.h"
#include <list>

class ArticleBuilder {
public:
    static ArticleBuilder* getInstance() { 
        if(_instance == nullptr){
            _instance = new ArticleBuilder();
        }
        return _instance;
    }

    ~ArticleBuilder() { }

    void buildListItem(std::string text) { 
        _result.push(new ListItem(text));
    }

    void buildText(std::string text) { 
        _result.push(new Text(text));
    }

    void buildParagraphBegin(int level, std::string text) { 
        _result.push(new Paragraph(level, text));
    }

    void buildParagraphEnd() { 
        std::list<Article*> temp;

        // store into list
        while(typeid(*_result.top())!=typeid(Paragraph) ||
        (!_result.top()->createIterator()->isDone() && 
        typeid(*_result.top())==typeid(Paragraph))){
            temp.push_back(_result.top());
            _result.pop();
        }

        Article* paragraph = _result.top();

        // add the elements into parargraph
        for(auto it = temp.rbegin(); it!= temp.rend(); it++){
            paragraph->add(*it);
        }
    }

    Article* getArticle() { 
        return _result.top();
    }

    void reset() { 
        while(_result.size() != 0){
            // this call the removed element destructor
            _result.pop();
        }
    }
private:
    std::stack<Article*> _result;
    static inline ArticleBuilder* _instance = nullptr;
};
