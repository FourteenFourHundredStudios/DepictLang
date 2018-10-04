//
//  util.hpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#ifndef util_hpp
#define util_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;



string readFile(string name);
bool isNumber(const std::string& s);
template <class T>
inline bool contains(vector<T> search, T value){
    for(T t:search)if(t==value)return true;
    return false;
}


class Token;
class DepictObject;
struct prop;



#endif /* util_hpp */

