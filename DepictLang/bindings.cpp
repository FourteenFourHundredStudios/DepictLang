//
//  bindings.cpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#include "bindings.hpp"

vector<Binding> bindings;

void addBinding(string name, function<DepictObject* (vector<DepictObject*>*)> func){
    bindings.push_back(Binding(name, func));
}

Binding* getBinding(string name){
    for(Binding &binding:bindings){
        if (name == binding.name){
            return &binding;
        }
    }
    return nullptr;
}


DepictObject* print(vector<DepictObject*>* params){
    cout << *params->at(0)->getValue() << endl;
    return nullptr;
}

DepictObject* doublePrint(vector<DepictObject*>* params){
    cout << *params->at(0)->getValue() << endl;
    cout << *params->at(1)->getValue() << endl;
    return nullptr;
}

void generateBindings(){
    addBinding("print", print);
    addBinding("doublePrint", doublePrint);
}





