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
    temp.obj = &obj;
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

StringObject::StringObject(string value_init){
    DepictObject();
    value = &value_init;
}

