//
//  depictobj.cpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#include "depictobj.hpp"


DepictObject::DepictObject(){
    value = nullptr;
}

void DepictObject::addProp(string name, DepictObject obj){
    prop temp = {};
    temp.name = name;
    temp.obj = new DepictObject(obj);
    props.push_back(temp);
}

DepictObject* DepictObject::getProp(string name){
    for(prop i : props){
        if(i.name == name){
            return i.obj;
        }
    }
    return nullptr;
}

string* DepictObject::getValue(){
    return value;
}


//string object
StringObject::StringObject(string value_init){
    DepictObject();
    value = new string(value_init);
}


//int object
IntObject::IntObject(string value1_init,Tokenizer::tokenName op_init,string value2_init){
    value1 = stoi(value1_init);
    value2 = stoi(value2_init);
    op = op_init;
    eval();
}

IntObject::IntObject(string value_init){
    value1 = stoi(value_init);
    value2 = 0;
    op = Tokenizer::plus;
    eval();
}

void IntObject::eval(){
    int num = 0 ;
    switch (op) {
        case Tokenizer::plus:
            num = value1+value2;
            break;
        case Tokenizer::minus:
            num = value1-value2;
            break;
        case Tokenizer::asterisk:
            num = value1*value2;
            break;
        case Tokenizer::slash:
            num = value1/value2;
            break;
        default:
            break;
    }
    std::ostringstream stream;
    stream << num;
    value = new string(stream.str());
}

