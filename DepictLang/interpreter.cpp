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
    for(Statement i : statements){
    
        KeywordToken *keyword = static_cast<KeywordToken*>(i.get(0));
        Binding binding = *getBinding(keyword->token);
        
        //cout << i.str() << endl;
        
        /*
        DepictObject params[1] = {StringObject("TESTTT")};
        binding.func(params);*/
    }
    
}


void Interpreter::generateStatements(){
    Tokenizer tokenizer = Tokenizer(code);
    Statement currentStatement = Statement() ;
    for (Token* token : tokenizer.tokens){
        //cout << token->str() << endl;
        if(DelimiterToken* v = dynamic_cast<DelimiterToken*>(token)) {
            if(v->token == '\n'){
                statements.push_back(currentStatement);
                currentStatement.tokens.clear();
                continue;
            }
            continue;
        }
        currentStatement.tokens.push_back(token);
    }
}
