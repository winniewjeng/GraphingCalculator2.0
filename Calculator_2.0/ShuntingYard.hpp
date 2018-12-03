

#ifndef ShuntingYard_hpp
#define ShuntingYard_hpp

#include "SimpleList.hpp"
#include "Token.hpp"
#include "Operand.hpp"
#include "Operator.hpp"
#include "Queue.hpp"
#include <iostream>
#include "Stack.hpp"
#include "Variable.hpp"
#include <string>
#include <sstream>
#include "Constants.hpp"

//parse the user-input string into tokens and store them in queue
Queue<Token*> toToken(string expression);
//convert the infix queue to a post-fix queue using Shunting-Yard algorithm
Queue<Token*> toPostFix(Queue<Token*> infix);

//evaluate the postfix queue
double Eval(Queue<Token*> postfix, double var_num);

//void test_eval();
void test_shunting();

#endif /* ShuntingYard_hpp */
