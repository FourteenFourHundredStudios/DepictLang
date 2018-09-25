//
//  Parser.cpp
//  DepictLang
//
//  Created by Marc Fervil on 19/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#include "Parser.hpp"
#include "virtualmem.hpp"

DepictObject* tokenToObject(Token* token){
    if(token->getType()==Tokenizer::literal){
        //parse literals like strings etc
        return new StringObject(token->value);
    }else if(token->getType()==Tokenizer::keyword){
        //parse variables here
        return getVar(token->value);
    }
    return nullptr;
}


vector<DepictObject*>* parseParamSet(Token* set ){

    vector<DepictObject*>* objs = new vector<DepictObject*>();
    Tokenizer* parse = new Tokenizer(set->value);
    if(set->getName() == Tokenizer::parentheses){
        for(Token* token:parse->tokens){
            objs->push_back(tokenToObject(token));
        }
    }
    free(parse);
    return objs;
}


