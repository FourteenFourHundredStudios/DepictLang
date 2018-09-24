//
//  bindings.hpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#ifndef bindings_hpp
#define bindings_hpp
#include "util.hpp"
#include <stdio.h>

#include "depictobj.hpp"


class Binding {
    
public:
    string name;
    function<DepictObject* (vector<DepictObject*>*)> func;
    
    
    Binding(string name_init, function<DepictObject* (vector<DepictObject*>*)> func_init){
        name = name_init;
        func = func_init;
    }
    
   
};

void addBinding(string name, function<DepictObject* (vector<DepictObject*>*)> func);
Binding* getBinding(string name);
void generateBindings();

#endif /* bindings_hpp */
