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
    
        
        Token keyword = *statement.get(0);
        Binding* binding = getBinding(keyword.value);
        

        vector<DepictObject*>* paramsParsed = parseParamSet(statement.get(1));

        binding -> func(paramsParsed);
       
    }
    
}


void Interpreter::generateStatements(){
    Tokenizer tokenizer = Tokenizer(code);
    Statement currentStatement = Statement();
    for (Token* token : tokenizer.tokens){

        
        if(token->getName() == Tokenizer::newline){
            statements.push_back(currentStatement);
            currentStatement.tokens.clear();
        }
        
        currentStatement.tokens.push_back(token);
    }
}
