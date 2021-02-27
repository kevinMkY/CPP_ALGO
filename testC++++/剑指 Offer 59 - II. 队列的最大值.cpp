//
//  剑指 Offer 59 - II.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 59 - II. 队列的最大值.hpp"
#include "common.h"

class MaxQueue {
public:
    
    queue<int>orginq;
    deque<int>maxqueue;
    
    MaxQueue() {

    }
    
    int max_value() {
        if (maxqueue.size()) {
            return maxqueue.front();;
        }
        return -1;
    }
    
    void push_back(int value) {
        orginq.push(value);
        while (maxqueue.size() && maxqueue.back() < value) {
            maxqueue.pop_back();
        }
        maxqueue.push_back(value);
    }
    
    int pop_front() {
        if (!orginq.size()) {
            return -1;
        }
        int val = orginq.front();
        orginq.pop();
        if (maxqueue.size() && val == maxqueue.front()) {
            maxqueue.pop_front();
        }
        return val;
    }
};


void _offer_59_02_repeat_test()
{
    MaxQueue* obj = new MaxQueue();
    obj->push_back(1);
    obj->push_back(2);
    int param_1 = obj->max_value();
    int param_2 = obj->pop_front();
    int param_3 = obj->max_value();
    
}
