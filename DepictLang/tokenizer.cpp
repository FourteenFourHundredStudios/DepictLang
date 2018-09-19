//
//  tokenizer.cpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//


#include "tokenizer.hpp"


char tokens [] = { '\n', ',', ' '};
char singleMatchtokens [] = { '"','\'' };
char matchTokens[] = { '{', '}', '(', ')' , '[', ']', '<', '>'};
char openToken = '~';
char closingToken = '~';
int openTokenCount = -1;
bool singleOpenToken = false;

int inTokens(char token){
    for(char c : tokens) {
        if (c == token){
            return true;
        }

    }
    return false;
}

int inSingleMatchtokens(char token){
    for(char c : singleMatchtokens) {
        if (c == token){
            return true;
        }
        
    }
    return false;
}


int isOpeningToken(char token){
    for(int i=0; i< sizeof(matchTokens); i+=2) {
        char c = matchTokens[i];
        if (c == token){
            return i;
        }
    }
    return -1;
}

bool isClosingToken(char token){
    for(int i=1; i< sizeof(matchTokens); i+=2) {
        char c = matchTokens[i];
        if (c == token){
            return true;
        }
    }
    return false;
}



Tokenizer::Tokenizer(string source_init){
    source = source_init;
    tokenize();
}

//TODO Split this massive function up into 3 smaller functions

void Tokenizer::tokenize() {
    string part = "";
    
    
    for(char c : source) {
        
        int openTokenPos = isOpeningToken(c);
        
        if (inSingleMatchtokens(c) && closingToken == '~'){

            if(!singleOpenToken){
                singleOpenToken = true;
                openToken = c;
            }else if (c==openToken){
                ContainerToken* container = new ContainerToken(part, openToken, openToken);
                tokens.push_back(container);
                openToken = '~';
                singleOpenToken = false;
                part = "";
            }
            
        }else if(openTokenPos != -1){
            
            if(openToken == '~'){
                
                if (part!=""){
                    KeywordToken* keyword = new KeywordToken(part);
                    tokens.push_back(keyword);
                    part = "";
                }
                
                openToken = c;
                closingToken = matchTokens[openTokenPos + 1];
                openTokenCount = 1;
            }else if ( c==openToken ){
                openTokenCount++;
                part += c;
            }else{
                part += c;
            }
            
        }else if(isClosingToken(c)){
            if (c == closingToken){
                openTokenCount--;
                //part += c;
                if(openTokenCount == 0){
                    
                    ContainerToken* container = new ContainerToken(part, openToken, closingToken);
                    tokens.push_back(container);
                    
                    openToken = '~';
                    closingToken = '~';
                    openTokenCount = -1;
                    
                   
                    part = "";
                    continue;
                }
            }
            part += c;
            
        
        } else if(inTokens(c) && openToken=='~'){
            if(part != ""){
                KeywordToken* keyword = new KeywordToken(part);
                tokens.push_back(keyword);
            }
            DelimiterToken* delimiter = new DelimiterToken(c);
            tokens.push_back(delimiter);
            part = "";
        }else{
            
            part += c;
        }
    }
}




