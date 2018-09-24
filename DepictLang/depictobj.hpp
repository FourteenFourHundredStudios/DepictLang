//
//  depictobj.hpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#ifndef depictobj_hpp
#define depictobj_hpp
//#include "util.hpp"

#include "prop.hpp"
#include <stdio.h>




class DepictObject {
    
public:
    
    vector<prop> props;
    string type;
    string* value;
    //int null = -1;
    DepictObject();
    
    void addProp(string name, DepictObject obj);
    string* getValue();
    DepictObject* getProp(string name);
    
};



class StringObject : public DepictObject {
public:
    StringObject(string value_init);
};

#endif /* depictobj_hpp */
