
#ifndef Stack_hpp
#define Stack_hpp

#include "SimpleList.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Stack {
public:
    Stack() {
        size = 0;
    }
    
    int get_size() {
        return size;
    }
    
    void push(const T& item) {
        size++;
        stack.insert_head(item);
    }
    
    T pop() {
        assert (stack.Begin()!=nullptr);
        size--;
        return stack.Delete(stack.Begin());
    }
    
    T top() {
        assert (stack.Begin()!=nullptr);
        return stack.Begin()->_item;
    }
    
    bool empty() {
        return size == 0;
    }
    
    //WOW I DIDN'T THINK THIS WOULD WORK
    template <class U>
    friend ostream& operator<<(ostream& outs, const Stack<U>& s) {
        node<U>* walker = s.stack.Begin();
        while (walker != s.stack.End()) {
            outs << " [" << walker->_item << "]";
            walker = walker->_next;
        }
        return outs;
    }
    
private:
    int size;
    SimpleList<T> stack;
    
};


#endif /* Stack_hpp */
