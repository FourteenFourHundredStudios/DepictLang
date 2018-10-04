//
//  Parser.cpp
//  DepictLang
//
//  Created by Marc Fervil on 19/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#include "Parser.hpp"





AST::AST(vector<Token> tokens_init){
    tokens = tokens_init;
    parse();
}

void AST::parse(){
    if(accept(Tokenizer::keyword)){
        
    }
}

bool AST::accept(Tokenizer::tokenType tokenType){
    if(tokens[currentTokenPos].getType()==tokenType){
        currentTokenPos++;
        return true;
    }
    return false;
}

vector<ASTNode> AST::getTree(){
    return vector<ASTNode>();
}
