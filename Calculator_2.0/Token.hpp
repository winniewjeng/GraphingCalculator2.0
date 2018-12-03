
#ifndef Token_hpp
#define Token_hpp

#include <iostream>

using namespace std;

class Token {
    
public:
    Token() {}
    //print fxn to print it
    virtual void print(ostream& outs = cout) const {}
    //ostream
    friend ostream& operator<<(ostream& outs, const Token* p) {
        p->print();
        return outs;
    }
    virtual string get_symb() {return "";}
    virtual int get_type() {return 2;}
    
private:
};

#endif /* Token_hpp */
