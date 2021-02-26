//
//  剑指 Offer 31.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 31. 栈的压入、弹出序列.hpp"
#include "common.h"

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

    stack<int>mystack;
    int popIndex = 0;
    for (int pushval : pushed) {
        mystack.push(pushval);
        while (mystack.size() && mystack.top() == popped[popIndex]) {
            mystack.pop();
            popIndex++;
        }
    }
    
    return mystack.empty();
    }

void _offer_31_repeate_test()
{
    vector<int> list1 = {1,2,3,4,5};
    vector<int> list2 = {4,5,3,2,1};
    
    bool res= validateStackSequences(list1,list2);
    
}
