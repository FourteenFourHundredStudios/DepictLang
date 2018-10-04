//
//  util.cpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#include "util.hpp"

string readFile(string name){
    string file = "";
    string line;
    ifstream myfile(name);
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            file += line + '\n';
        }
        myfile.close();
    }
    return file; 
}

bool isNumber(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}





