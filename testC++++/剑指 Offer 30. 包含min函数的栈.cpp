//
//  剑指 Offer 30.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 30. 包含min函数的栈.hpp"
#include "common.h"

class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int>datastack;
    stack<int>mindatastack;
    
    MinStack() {

    }
    
    void push(int x) {
        datastack.push(x);
        if (mindatastack.size() > 0) {
            int y = mindatastack.top();
            if (y < x) {
                mindatastack.push(y);
            }else{
                mindatastack.push(x);
            }
        }else{
            mindatastack.push(x);
        }
    }
    
    void pop() {
        datastack.pop();
        mindatastack.pop();
    }
    
    int top() {
        return datastack.top();
    }
    
    int min() {
        return mindatastack.top();
    }
};

void _offer_30_repeate_test()
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->min();//   --> 返回 -3.
    minStack->pop();
    minStack->top();  //    --> 返回 0.
    minStack->min();  // --> 返回 -2.

    
}
