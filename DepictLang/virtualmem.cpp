//
//  virtualmem.cpp
//  DepictLang
//
//  Created by Marc Fervil on 24/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#include "virtualmem.hpp"

vector<depictVar*> depictVars;

void defineVar(string name, DepictObject* object){
    
    for(depictVar* v : depictVars){
        if (v->name == name){
            free(v->object);
            v->object = object;
            return;
        }
    }
    
    depictVar* var = new depictVar();
    var->name = name;
    var->object = object;

    depictVars.push_back(var);
}

DepictObject* getVar(string name){
    for(depictVar* v : depictVars){
        if (v->name == name){
            return v->object;
        }
    }
    return nullptr;
}


