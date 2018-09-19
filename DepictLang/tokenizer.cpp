//
//  tokenizer.cpp
//  DepictLang
//
//  Created by Marc Fervil on 17/9/18.
//  Copyright © 2018 Marc Fervil. All rights reserved.
//


#include "tokenizer.hpp"

Token::Token(string value_init,Tokenizer::tokenMatch tokenProps_init){
    value = value_init;
    tokenProps = tokenProps_init;
}

string Token::str(){
    if(getType()==Tokenizer::literal){
        string result = "Literal: ";
        result += tokenProps.opening;
        result += value;
        result += tokenProps.opening;
        return result;
    }else if (getType()==Tokenizer::container){
        string result = "Container: ";
        result += tokenProps.opening;
        result += value;
        result += tokenProps.closing;
        return result;
    }else if (getType()==Tokenizer::delimiter){
        string result = "Delimiter: ";
        if(result!="\n"){
            result += value;
        }else{
            result+= "\\n";
        }
        return result;
    }else if (getType()==Tokenizer::keyword){
        return "Keyword: "+value;
    }
    return "";
}

Tokenizer::tokenType Token::getType(){
    return tokenProps.type;
}

Tokenizer::tokenName Token::getName(){
    return tokenProps.name;
}

Tokenizer::Tokenizer(string source_init){
    source = source_init;
    setup();
    tokenize();
}



void Tokenizer::setup(){
    tokenMatchList = {
        { container, curly_brackets ,'{', '}' },
        { literal, single_quotes ,'"' },
        { delimiter, space , ' ' },
        { delimiter, newline , '\n' },
    };
    state = { keyword };
}

Tokenizer::tokenMatch Tokenizer::identifyToken(char c){
    for(tokenMatch potentialMatch : tokenMatchList){
        if (c == potentialMatch.opening || c == potentialMatch.closing){
            return potentialMatch;
        }
    }
    return { keyword };
}

void Tokenizer::handleDelimiter(Tokenizer::tokenMatch match){
    if(match.type==delimiter && state.type == keyword){
        if(tokenValue != ""){
            tokens.push_back(new Token(tokenValue, state));
            tokenValue = "";
        }

        tokens.push_back(new Token(string() + match.opening, { delimiter }));
        recordChar = false;
    }
}

void Tokenizer::handleLiteral(Tokenizer::tokenMatch match){
    if(match.type==literal){
        inLiteral = !inLiteral;
        if(state.type == keyword){
            state = match;
            recordChar = false;
        }else if (state.type == literal){
            tokens.push_back(new Token(tokenValue,state));
            state = { keyword };
            tokenValue = "";
            recordChar = false;
        }
    }
}

void Tokenizer::handleContainer(Tokenizer::tokenMatch match, char matchChar){
    if(match.type==container && !inLiteral){
        if(state.type == keyword && stateCount == 0){
            if(tokenValue != ""){
                tokens.push_back(new Token(tokenValue, state));
                tokenValue = "";
            }
            state = match;
            stateCount++;
            recordChar = false;
        }else if(state.type==container){
            if(match.opening==matchChar){
                stateCount++;
            }else if(match.closing==matchChar){
                stateCount--;
            }
            if(stateCount == 0){
                tokens.push_back(new Token(tokenValue,state));
                recordChar = false;
            }
        }
    }
}


void Tokenizer::tokenize() {
    for(char c : source){
        recordChar = true;
        tokenMatch charMatch = identifyToken(c);
        handleDelimiter(charMatch);
        handleLiteral(charMatch);
        handleContainer(charMatch,c);
        if (!recordChar) continue;
        tokenValue += c;
    }
}




