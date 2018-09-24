//
//  Parser.hpp
//  DepictLang
//
//  Created by Marc Fervil on 19/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp
#include "util.hpp"
#include "tokenizer.hpp"
#include "depictobj.hpp"

extern vector<DepictObject*>* parseParamSet(Token* set);
extern DepictObject* tokenToObject(Token* token);

#include <stdio.h>

#endif /* Parser_hpp */
