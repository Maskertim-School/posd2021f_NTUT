#pragma once

#include <string>
#include "article.h"

class ListItem : public Article {
   public:
    ListItem(std::string text): _text(text) {}

    std::string getText() const {
        return "- "+_text;
    }

   private:
    std::string _text;
};