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


bool validateStackSequences2(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    int m = popped.size();
    if (n == 0 && m == 0) {
        return true;
    }else if (n == 0 || m == 0){
        return false;
    }
    
    stack<int> mystack;
    int popidx = 0;
    for (int i = 0; i<n; i++) {
        mystack.push(pushed[i]);
        while (mystack.size() && popidx < m && (mystack.top() == popped[popidx])) {
            mystack.pop();
            popidx++;
        }
    }
    
    return mystack.size() == 0;
}

void _offer_31_repeat_test()
{
    vector<int> list1 = {1,2,3,4,5};
    vector<int> list2 = {4,5,3,2,1};
    
    bool res= validateStackSequences2(list1,list2);
    
}
