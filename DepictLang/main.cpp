//
//  main.cpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//


#include "util.hpp"
#include "interpreter.hpp"

//greet (hello, world, {(and, all)}) (hello, marc)

/*
string* f (){
    return new string("f");
}

cout << *f() << endl;
*/
 
int main(int argc, const char * argv[]) {

    string file = readFile("/Users/Marc/Documents/Programming/DepictLang/DepictLang/test.dpct");
  
    /*
    Tokenizer toke = Tokenizer(file);
    for(Token* t : toke.tokens  ){
        cout << t->str() << endl;
    }*/
    
    Interpreter depict = Interpreter(file);
    
    
    return 0;
}
