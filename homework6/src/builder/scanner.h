#pragma once
#include <vector>
#include <string>
#include <ctype.h>
#include <regex>

class Scanner {
public:
    Scanner(std::string input): _input(input) {}

    std::string next() {
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
            }else if(isdigit(_input[pos])) break;
        }

        if(isDone() && result.empty()) throw std::string ("the scan is ended.");

        return result;
    }

    double nextDouble() {
        std::string temporary = "";
        double result = 0.0;
        bool isFind = false;
        int pointCounter = 0;

        if(isDone()) throw std::string ("the scan is ended.");

        skipWhiteSpace();

        while(isalpha(_input[pos]) || ispunct(_input[pos])) pos++;

        if(isdigit(_input[pos])){
            int start = pos;

            while(isdigit(_input[pos]) || _input[pos]=='.') {
                if(_input[pos] == '.') pointCounter++;

                if(pointCounter > 1) break;
                 
                pos++;
            }

            temporary = _input.substr(start, pos-start);

            if(std::regex_match(temporary, std::regex("[+-]?([0-9]*[.])?[0-9]+"))){
                result = stod(temporary);
                isFind = true;
            }
        }

        if(isDone() && !isFind) throw std::string ("the scan is ended.");

        return result;
    }

    bool isDone() {
        while(pos < _input.length() && isspace(_input[pos])) pos++;

        return pos >= _input.length();
    }


private:
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
    std::string _input;
    std::string::size_type pos = 0;

    void skipWhiteSpace() {
        while(isspace(_input[pos])) pos++;
    }
};