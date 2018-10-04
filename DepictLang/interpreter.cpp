//
//  interpreter.cpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//


#include "interpreter.hpp"


Interpreter::Interpreter(string code_init){
    code = code_init;
    generateStatements();
    generateBindings();

    for(Statement statement : statements){
        
    }
    
}


void Interpreter::generateStatements(){
    Tokenizer tokenizer = Tokenizer(code);
    Statement currentStatement = Statement();
    for (Token* token : tokenizer.tokens){

        
        if(token->getName() == Tokenizer::newline){
            if(currentStatement.tokens.size()>0){
                statements.push_back(currentStatement);
            }
            currentStatement.tokens.clear();
            continue;
        }
        
        currentStatement.tokens.push_back(token);
    }
}
