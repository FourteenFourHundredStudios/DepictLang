//
//  virtualmem.hpp
//  DepictLang
//
//  Created by Marc Fervil on 24/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#ifndef virtualmem_hpp
#define virtualmem_hpp



#include <stdio.h>
#include "depictobj.hpp"

struct depictVar {
    string name;
    DepictObject* object;
};

extern vector<depictVar*> depictVars;

void defineVar(string name, DepictObject* object);
DepictObject* getVar(string name);

#endif /* virtualmem_hpp */
