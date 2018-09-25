//
//  main.cpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//





//#include "util.hpp"
 #include "interpreter.hpp"
 #include "tokenizer.hpp"



int main(int argc, const char * argv[]) {

    //cout << "starting" << endl;
    
    string file = readFile("/Users/Marc/Documents/Programming/DepictLang/DepictLang/test.dpct");
  
    
    Tokenizer toke = Tokenizer(file);
    for(Token* t : toke.tokens  ){
        cout << t->str() << endl;
    }
    
 //   Interpreter depict = Interpreter(file);

    return 0;
}
