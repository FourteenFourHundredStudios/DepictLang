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

    //    cout << "1). one down" << endl;
        
        Token keyword = *statement.get(0);
        Binding* binding = getBinding(keyword.value);

 //       cout << "2). one down" << endl;
        
        if(statement.get(1)->getName() == Tokenizer::equal){
            //assigning value
            defineVar(statement.get(0)->value, tokenToObject(statement.get(2)));
        }else{
            //calling functions that are defined in C++
            vector<DepictObject*>* paramsParsed = parseParamSet(statement.get(1));
            binding -> func(paramsParsed);
        }
     //   cout << "3). one down\n" << endl;
        
       
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
