#pragma once

#include <vector>
#include <string>
#include <ctype.h>
#include <regex>

class ArticleScanner {
public:
    ArticleScanner(std::string input): _input(input) {}

    std::string nextToken() { 
        std::string result = "";

        if(isDone()) throw std::string ("the scan is ended.");

        skipWhiteSpace();

        while(!isDone() && result.empty()){

            if(isalpha(_input[pos])){
                int start = pos;

                while(isalpha(_input[pos])) pos++;

                for(auto token : tokenList){
                    if(_input.substr(start, pos-start).find(token) != std::string::npos){
                        result = token;
                        break;
                    }
                }
            }else if(ispunct(_input[pos])){
                for(auto token : tokenList){
                    if(_input.compare(pos, 1, token) == 0){
                        result = token;
                        break;
                    }
                }
                pos++;
            }else if(isdigit(_input[pos])) {
                pos++;
            };
        }

        if(isDone() && result.empty()) throw std::string ("the scan is ended.");

        return result;
    }

    int nextInt() { 
        std::string temporary = "";
        int result = 0;
        bool isFind = false;
        int pointCounter = 0;

        if(isDone()) throw std::string ("the scan is ended.");

        skipWhiteSpace();

        while(isalpha(_input[pos]) || ispunct(_input[pos])) pos++;

        if(isdigit(_input[pos])){
            int start = pos;

            // while(isdigit(_input[pos]) || _input[pos]=='.') {
            //     if(_input[pos] == '.') pointCounter++;

            //     if(pointCounter > 1) break;
                 
            //     pos++;
            // }

            while(isdigit(_input[pos])) pos++;


            temporary = _input.substr(start, pos-start);

            // if(std::regex_match(temporary, std::regex("[+-]?([0-9]*[.])?[0-9]+"))){
            //     result = stod(temporary);
            //     isFind = true;
            // }

            if(std::regex_match(temporary, std::regex("[+-]?([0-9]*)"))){
                result = stoi(temporary);
                isFind = true;
            }
        }

        if(isDone() && !isFind) throw std::string ("the scan is ended.");

        return result;
    }

    std::string nextStr() {
        std::string result = "";

        if(isDone()) throw std::string ("the scan is ended.");

        skipWhiteSpace();

        while(_input[pos]!='\"') pos++;

        pos++;
        int start = pos;
        while(_input[pos]!='\"') pos++;

        result = _input.substr(start, pos-start);
        
        return result;
    }

    bool isDone(){ 
        while(pos < _input.length() && isspace(_input[pos])) pos++;

        return pos >= _input.length();
    }

private:
    const std::vector<std::string> tokenList = {"ListItem", "Text", "Paragraph", "(", ")", "{", "}"};
    std::string _input;
    std::string::size_type pos = 0;

    void skipWhiteSpace() {
        while(isspace(_input[pos])) pos++;
    }
};
