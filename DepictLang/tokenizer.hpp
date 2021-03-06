//
//  tokenizer.hpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#ifndef tokenizer_hpp
#define tokenizer_hpp

#include <stdio.h>

#include "util.hpp"



class Tokenizer{
    
public:
    
    string source;
    vector<Token*> tokens;
    string tokenValue; 
    bool recordChar = true; 
    bool inLiteral = false;
    
    enum tokenType {
        container,
        literal,
        delimiter,
        keyword,
        number,
        identifier,
        operator_
    };
    
    enum tokenName {
        parentheses,
        square_brackets,
        curly_brackets,
        angle_brackets,
        newline,
        comma,
        space,
        word,
        single_quotes,
        double_quotes,
        equal,
        plus,
        minus,
        period,
        asterisk,
        slash
    };
    
    struct tokenMatch {
        tokenType type;
        tokenName name;
        char opening;
        char closing;
        int numValue;
    };
    vector <string> keywords;
    vector <string> operators;
    vector <tokenMatch> tokenMatchList;
    int stateCount = 0;
    tokenMatch state;
    Tokenizer(string source_init);
    
    tokenMatch identifyToken(char c);
    void tokenize();
    void setup();
    void handleMath(tokenMatch match);
    void handleDelimiter(tokenMatch match);
    void handleLiteral(tokenMatch match);
    void handleContainer(tokenMatch match, char matchChar);
    void handleKeyword();
};


class Token{
public:
    Tokenizer::tokenMatch tokenProps;
    Token(string value_init,Tokenizer::tokenMatch tokenProps_init);
    Token();
    string value;
    string str();
    bool parsed = false;
    Tokenizer::tokenType getType();
    Tokenizer::tokenName getName();
};


#endif /* tokenizer_hpp */

//#include <stdio.h>
