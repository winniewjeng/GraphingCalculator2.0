
#ifndef Variable_hpp
#define Variable_hpp
#include <iostream>
#include "Token.hpp"

class Token;

class Variable : public Token {
    
public:
    Variable(): _var('X') {}
    Variable(char var): _var(var) {}
    void print(ostream& outs = cout) const {
        outs << _var;
    }
    int get_type() {return 2;}
    char get_var() {return _var;}
private:
    char _var;
};

#endif /* Variable_hpp */
