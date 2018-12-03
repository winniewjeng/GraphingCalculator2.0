
#include "ShuntingYard.hpp"

// convert user input string to token and then store queue
Queue<Token*> toToken(string expression) {
    
    Queue<Token*> infix;
    
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == 'X' || expression[i] == 'Y') {
            char tok = ' ';
            while (expression[i] != ' ' && i < expression.size()) {
                tok = expression[i];
                i++;
            }
            //cout << "2. infix var: " << expression[i] << endl;
            infix.push(new Variable(tok));
        }
        else if (isdigit(expression[i]) || expression[i] == '.') {
            string tok = "";
            while (expression[i] != ' ' && i < expression.size()) {
                tok += expression[i];
                i++;
            }
            //cout << "1. infix num: " << tok << endl;
            infix.push(new Operand(stod(tok)));
        } else {
            string tok = "";
            while (expression[i] != ' ' && i < expression.size()) {
                tok += expression[i];
                i++;
            }
            //cout << "0. infix optr: " << tok << endl;
            infix.push(new Operator(tok));
        }
        
    }
    return infix;
};

// turn the infix to postfix
Queue<Token*> toPostFix(Queue<Token*> infix) {
    // get a postfix queue
    Queue<Token*> postfix;
    // get an operator stack
    Stack<Operator*> optr;
    while (!infix.empty()) {
        //pop infix queue one item one at a time
        Token* item = infix.pop();
        Token* prev_item = new Operator("P");  // initialize it to something ridiculous
        // if the item is a number, push it to postfix
        if (item->get_type() == OPERAND) {
            postfix.push(item);
            // store the popped item as the previous item for the next round
            prev_item = item; ////
        }
        //item is a variable, check the previous item first before doing stuff
        else if (item->get_type() == VARIABLE) {
            postfix.push(item);
            if (prev_item->get_type() == OPERAND) {
                cout << "do i star\n";
                // if its previous item is number, create a ghost * and put it in postfix
                postfix.push(new Operator("*"));
            }
            // store the popped item as the previous item for the next round
            prev_item = item; ////
        }
        // if the item is an operator, check some conditions before doing stuff
        else if (item->get_type() == OPERATOR) {
            // cast item as an Operator* type first
            Operator* optr_item = static_cast<Operator*>(item);
            // push item into the optr stack if stack is empty
            if (optr.empty()) {
                if (prev_item->get_type() == OPERAND) {
                    if (optr_item->get_symb() == "(" || optr_item->is_trig()) {
                        optr.push(new Operator("*"));
                    }
                }
                optr.push(optr_item);
                // store the popped item as the previous item for the next round
                prev_item = optr_item; ////
            }
            // if optr stack is not empty...check the type of the optr_item before
            // determining where it goes
            else {
                // if the optr_item is an open parenthesis
                if (optr_item->get_symb() == "(") {
                    //push the open parenthesis into the optr stack
                    if (prev_item->get_type() == OPERAND) {
                        // if its previous item is number, create a ghost * and put it in optr stack
                        optr.push(new Operator("*"));
                    }
                    optr.push(optr_item);
                    // store the popped item as the previous item for the next round
                    prev_item = optr_item; ////
                }
                // if the optr_item is a closed parenthesis, mary poppings the optr stack to postfix
                else if (optr_item->get_symb() == ")") {
                    while(optr.top()->get_symb() != "(") {
                        //                        cout << optr.top()->get_symb() << endl;
                        postfix.push(optr.pop());
                    }
                    //                    cout << optr.top() << endl;
                    //disgard the open parenthesis from stack
                    optr.pop();
                    // store the popped item as the previous item for the next round
                    prev_item = optr_item; ////
                }
                // if the optr_item is trig, check the prev_item, check precedence
                else {
                    //if optr_item has greater precedence than the precedence of the top of stack, pop the stack's top and push it to postfix queue
                    if (optr_item->precedence() <= optr.top()->precedence() && optr.top()->get_symb() != "(") {
                        postfix.push(optr.pop());
                    }
                    
                    //if optr_item is trig and prev_item is OPERAND or ")", push a star into optr stack
                    if (optr_item->is_trig()) {
                        if (prev_item->get_type() == OPERAND || prev_item->get_symb() == ")") {
                            optr.push(new Operator("*"));
                        }
                    }
                    //push the current optr_item to the stack
                    optr.push(optr_item);
                    // store the popped item as the previous item for the next round
                    prev_item = optr_item; ////
                }
            }
        }
        // if infix is empty, pop all item in optr stack and put them in postfix
        if (infix.empty()) {
            while (!optr.empty()) {
                postfix.push(optr.pop());
            }
        }
    }
    return postfix;
}

//double Eval(Queue<Token*> postfix) {
//    //a stack that stores double* Operands
//    Stack<double> s;
//
//    while (!postfix.empty()) {
//        //get the top Token* in the queue
//        Token* p = postfix.top();
//        //cout << p << " ";
//        double LHS;
//        double RHS;
//        // if Token* is of type Operand(0), i.e. number digit, push into stack
//        // if Token* is of type Operator(1), pop stack twice and do the math
//        if (p->get_type() == 0) {
//            // cast the Token* p to Operand*
//            Operand* token_num = static_cast<Operand*>(p);
//            // get the value that Operand* holds
//            double num = token_num->get_num();
//            // push the value into stack
//            s.push(num);
//        } else {
//            // get two numbers from stack
//            RHS = s.pop();
//            LHS = s.pop();
//            // do math with the numbers
//            double result = static_cast<Operator*>(p)->do_math(LHS, RHS);
//            // push result back into the stack
//            s.push(result);
//        }
//        // house keeping - shrink the postfix queue
//        postfix.pop();
//    }
//
//    return s.top();
//};
//
//double Eval(Queue<Token*> postfix, Variable var) {
//
//    Stack<double> s;
//
//    while(!postfix.empty()) {
//        Token* p = postfix.top();
//        cout << "p is " << p << endl;
//        double LHS;
//        double RHS;
//        // if Token* is of type Operand(0), i.e. number digit, push into stack
//        if (p->get_type() == 0) {
//            // cast the Token* p to Operand*
//            Operand* token_num = static_cast<Operand*>(p);
//            // get the value that Operand* holds
//            double num = token_num->get_num();
//            // push the value into stack
//            s.push(num);
//        }
//        // if Token* is of type Operator(1), pop stack twice and do the math
//        else if (p->get_type() == 1) {
//            // get two numbers from stack
//            RHS = s.pop();
//            LHS = s.pop();
//            // do math with the numbers
//            double result = static_cast<Operator*>(p)->do_math(LHS, RHS);
//            // push result back into the stack
//            s.push(result);
//        }
//        // if Token* is of type Variable(2)
//        else if (p->get_type() == 2) {
//
//        }
//        // house keeping - shrink the postfix queue
//        postfix.pop();
//    }
//    return s.top();
//}
//
//void test_eval() {
//
//    Queue<Token*> input;
//
//    input.push(new Operand(3.0));
//    input.push(new Operand(2));
//    input.push(new Operand(5.5));
//    input.push(new Operator("+"));
//    input.push(new Operand(4));
//    input.push(new Operator("/"));
//    input.push(new Operator("*"));
//
//    cout << "Evaluate: " << endl;
//    cout << input << " = " << Eval(input) << endl;
//};
//
void test_shunting() {
    string expression;
    cout << "Enter an expression, i.e. 5.5 ( 4.0 ^ 2 + X ) sin ( 0.9 ) \n";
    cout << "My expression: ";
    getline(cin, expression);
    //    cout << "the string expression is " << expression << endl;
    Queue<Token*> infix = toToken(expression);
    cout << "Tokenized infix expression is   " << infix << endl;
    Queue<Token*> postfix = toPostFix(infix);
    cout << "Tokenized postfix expression is " << postfix << endl;
    //    cout << "the evaluated postfix expression is " << Eval(postfix) << endl;
};
