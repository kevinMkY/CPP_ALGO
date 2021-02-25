//
//  剑指 Offer 09.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "剑指 Offer 09. 用两个栈实现队列.hpp"
#include "common.h"

class CQueue {
public:
    stack<int> instack;
    stack<int> outstack;
    CQueue() {
        instack = {};
        outstack = {};
    }
    
    void appendTail(int value) {
        instack.push(value);
    }
    
    int deleteHead() {
        checkStack();
        if (outstack.empty()) {
            return -1;
        }else{
            int res = outstack.top();
            outstack.pop();
            return res;
        }
    }
    
    void checkStack(){
        if (outstack.empty()) {
            while (!instack.empty()) {
                int res = instack.top();
                instack.pop();
                outstack.push(res);
            }
        }
    }
};

void _offer_09_test(){
    CQueue* obj = new CQueue();
    obj->appendTail(5);
    obj->appendTail(2);
    int param_2 = obj->deleteHead();
    
}
