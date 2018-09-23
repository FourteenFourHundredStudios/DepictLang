//
//  Parser.cpp
//  DepictLang
//
//  Created by Marc Fervil on 19/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#include "Parser.hpp"



vector<DepictObject*>* parseParamSet(Token* set ){

    vector<DepictObject*>* objs = new vector<DepictObject*>();
    Tokenizer* parse = new Tokenizer(set->value);
    if(set->getName() == Tokenizer::parentheses){
        for(Token* token:parse->tokens){
            if(token->getType()==Tokenizer::literal){
                objs->push_back(new StringObject(token->value));
            }else if(token->getType()==Tokenizer::keyword){
                //parse variables here
            }
        }
    }

    return objs;
}


