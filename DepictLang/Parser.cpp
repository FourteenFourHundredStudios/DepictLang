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
    }else if(token->getType()==Tokenizer::number){
        //parse numbers here
        return new IntObject(token->value);
    }
    return nullptr;
}

DepictObject* tokensToObject(vector<Token*> tokens){
    
    return nullptr;
}

vector<DepictObject*>* parseParamSet(Token* set ){

    vector<DepictObject*>* objs = new vector<DepictObject*>();
    Tokenizer* parse = new Tokenizer(set->value);
    if(set->getName() == Tokenizer::parentheses){
        vector<Token*> tokens;
        for(Token* token:parse->tokens){
            if(token->getType()!=Tokenizer::delimiter){
                tokens.push_back(token);
            }else{
                if(tokens.size() == 1){
                    objs->push_back(tokenToObject(tokens.at(0)));
                }else{
                    objs->push_back(tokensToObject(tokens));
                }
                tokens.clear();
            }
        }
        if(tokens.size() == 1){
            objs->push_back(tokenToObject(tokens.at(0)));
        }else{
            objs->push_back(tokensToObject(tokens));
        }
    }
    free(parse);
    return objs;
}


