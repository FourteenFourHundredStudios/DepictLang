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

ASTBinary::ASTBinary(ASTNode* left_init, string op_init, ASTNode* right_init) : ASTNode(binary){
    left = left_init;
    right = right_init;
    op = op_init;
}

string ASTBinary::str () {
    return "{Type: Binary, Left: "+left->str()+", Op: "+op+", Right: "+right->str()+"}";
}



ASTNode* AST::parseMath(int index,int minPr){
    
    
    return new ASTNode(null);
    //return new ASTBinary(left,tokens[index]->value,right);
}

ASTNode* AST::createBranch(int index){

    //cout << tokens[index]->str() << endl;
    
    //if(tokens[index]->parsed)return new ASTNode(null);
    switch (tokens[index]->getType()) {
        case Tokenizer::identifier:
            return new ASTAttribute(tokens[index]->value);
            break;
        case Tokenizer::operator_:
            return parseMath(index, getOpprecedence(tokens[index]->value));
            break;
        default:
            return new ASTNode(null);
    }
}

int AST::getOpprecedence(string op){
    if(op=="+" || op=="-"){
        return 0;
    }else if (op=="*" || op=="/"){
        return 1;
    }
    return -1;
}

ASTNode* AST::getTree(){
    
    int size = static_cast<int>(tokens.size());
    
    ASTNode* tree = new ASTNode(null);
    ASTNode* newValue = new ASTNode(null);
    for(int i=size; i --> 0;){
        
        ASTNode* branch = createBranch(i);

        if(newValue->type == null){
            tree = branch;
        }else if (ASTAttribute* derived = dynamic_cast<ASTAttribute*>(newValue)) {
            derived->value = branch;
        }

        newValue = branch;
        

        
    
    }
    return tree;
}
