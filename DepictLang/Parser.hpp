//
//  Parser.hpp
//  DepictLang
//
//  Created by Marc Fervil on 19/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp
#include "util.hpp"
#include "tokenizer.hpp"
#include "depictobj.hpp"
#include "virtualmem.hpp"



enum nodeType {
    expression,
    assignment
};

class ASTNode {
public:
    string str();
};


class AST{
public:
    Token currentToken;
    int currentTokenPos;
    vector<Token> tokens;
    AST(vector<Token> tokens_init);
    bool accept(Tokenizer::tokenType tokenType);
    void parse();
    void next();
    vector<ASTNode> getTree();
};


#include <stdio.h>

#endif /* Parser_hpp */
