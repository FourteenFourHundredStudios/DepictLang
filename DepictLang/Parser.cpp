//
//  Parser.cpp
//  DepictLang
//
//  Created by Marc Fervil on 19/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#include "Parser.hpp"


ASTNode::ASTNode(nodeType type_init){
    type=type_init;
}

 string ASTNode::str(){
    return "null";
}


ASTExpression::ASTExpression() : ASTNode(expression){
    body = new ASTNode(null);
}



ASTNumber::ASTNumber(string value_init) : ASTNode(number){
    value = value_init;
}

string ASTNumber::str () {
    return "{Type: Number, Value: "+value+"}";
}



AST::AST(vector<Token*> tokens_init){
    tokens = tokens_init;
}

ASTAttribute::ASTAttribute(string name_init) : ASTNode(attribute){
    name = name_init;
    value = new ASTNode(null);
}
    
string ASTAttribute::str(){
    return "{Type: Attribute, Name: "+name+", Value: "+value->str()+"}";
}


ASTNode* AST::createBranch(int index){
    switch (tokens[index]->getType()) {
        case Tokenizer::identifier:
            return new ASTAttribute(tokens[index]->value);
            break;
            
        default:
            return nullptr;
    }
}


ASTNode* AST::getTree(){
    
    ASTNode* tree = new ASTNode(null);
    ASTNode* newTree = new ASTNode(null);
    for(int i=0; i<tokens.size(); i++){
        ASTNode* branch = createBranch(i);
        
        newTree = branch;
        
        if(tree->type == null){
            tree = branch;
        }else if (ASTExpression* derived = dynamic_cast<ASTExpression*>(newTree)) {
            derived->body = tree;
        }else  if (ASTAttribute* derived = dynamic_cast<ASTAttribute*>(newTree)) {
            derived->value = tree;
        }
        
        
    
    }
    return newTree;
}
