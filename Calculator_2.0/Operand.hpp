
#ifndef Operand_hpp
#define Operand_hpp
#include <iostream>
#include "Token.hpp"

using namespace std;

class Token;

class Operand : public Token {
    
public:
    Operand(double num): _num(num) {}
    void print(ostream& outs = cout) const {
        outs << _num;
    }
    int get_type() {return 1;}
    double get_num() {return _num;}
private:
    double _num;
};

#endif /* Operand_hpp */
