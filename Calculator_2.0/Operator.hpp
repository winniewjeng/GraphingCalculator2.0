
#ifndef Operator_hpp
#define Operator_hpp
#include <iostream>
#include "Token.hpp"

using namespace std;

class Token;

class Operator : public Token {
    
public:
    Operator(string symb): _symb(symb) {}
    void print(ostream& outs = cout) const {
        outs << _symb;
    }
    int get_type() {return 0;}
    
    double do_math(double LHS, double RHS) {
        if (_symb == "+") {
            return (LHS + RHS);
        } else if (_symb == "-") {
            return (LHS - RHS);
        } else if (_symb == "*") {
            return (LHS * RHS);
        } else if (_symb == "/") {
            return (LHS / RHS);
        } else {
            cout << "unrecognizable operator\n";
        }
        return -1;
    }
    
    string get_symb() {return _symb;}
    
    //check order of precedence with the next token in stack
    double precedence() {
        if (_symb == "+" || _symb == "-") {
            return 0;
        } else if (_symb == "*" || _symb == "/") {
            return 1;
        } else if (_symb == "^") {
            return 2;
        } else if (_symb == "sin" || _symb == "cos" || _symb == "tan") {
            return 3;
        }
        return 5;
    }
    
    bool is_trig() {
        if (_symb == "sin") {
            return true;
        } else if (_symb == "cos") {
            return true;
        } else if (_symb == "tan") {
            return true;
        }
        return false;
    }
    
    
private:
    string _symb;
};

#endif /* Operator_hpp */