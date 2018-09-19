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

class Token{
public:
    virtual string str(){
        return "???";
    }
};

class DelimiterToken : public Token{
    
public:
    char token;
    
    DelimiterToken(char token_init){
        token = token_init;
    }
    
    string str()  {
        string val = "Delimiter: ";
        val += token;
        if (token == '\n') {
            val = "Delimiter: (newline)";
        }
        return val;
    }
};

class KeywordToken : public Token{
    
public:
    string token;
    KeywordToken(string token_init){
        token = token_init;
    }
    string str()  {
        return "Keyword: "+token;
    }
   
};

class ContainerToken : public Token{
    
public:
    string token;
    char openingToken;
    char closingToken;
    ContainerToken(string token_init, char openingToken_init, char closingToken_init){
        token = token_init;
        openingToken = openingToken_init;
        closingToken = closingToken_init;
    }
    string str()  {
        string val = "Container: ";
        val += openingToken;
        val += token;
        val += closingToken;
        return val;
    }
    
};

class Tokenizer{
    
public:
    
    string source;
    vector<Token*> tokens;
    
    Tokenizer(string source_init);
    void tokenize();
    
};



#endif /* tokenizer_hpp */

#include <stdio.h>
