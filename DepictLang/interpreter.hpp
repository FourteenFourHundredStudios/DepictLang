//
//  interpreter.hpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#ifndef interpreter_hpp
#define interpreter_hpp

#include "tokenizer.hpp"
#include "bindings.hpp"
#include "Parser.hpp"
#include "util.hpp"

class Statement {
public:
    vector<Token*> tokens;
    Statement(){}
    Token* get(int i){
        return tokens.at(i);
    }
    string str(){
        string val = "";
        for(Token* token : tokens){
            val += token->str() + "->";
        }
        return val;
    }
    
};



class Interpreter {
    
public:
    string code;
    vector<Statement> statements;
    Interpreter(string code_init);
    void generateStatements();
    
};


#include <stdio.h>

#endif /* interpreter_hpp */
