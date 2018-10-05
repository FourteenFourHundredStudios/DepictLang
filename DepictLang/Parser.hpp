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
    assignment,
    binary,
    literal,
    number,
    attribute,
    null,
};



class ASTNode {
public:
    ASTNode(nodeType type_init);
    virtual ~ASTNode() = default;
    nodeType type;
    virtual string str();
};

class ASTExpression : public ASTNode{
public:
    ASTNode* body;
    ASTExpression();
    string str() = 0;
};

class ASTAttribute : public ASTNode{
public:
    string name;
    ASTNode* value;
    ASTAttribute(string name_init) ;
    string str();
};


class ASTNumber : public ASTNode{
public:
    ASTNumber(string value);
    string value;
    string str();
};



class AST{
public:
    Token currentToken;
    int currentTokenPos;
    vector<Token*> tokens;
    AST(vector<Token*> tokens_init);
    
    ASTNode* createBranch(int index);
    ASTNode* getTree();
};


#include <stdio.h>

#endif /* Parser_hpp */
