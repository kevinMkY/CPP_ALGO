//
//  剑指 Offer 41.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 41. 数据流中的中位数.hpp"
#include "common.h"

class MedianFinder {
public:
    priority_queue<int,vector<int>,less<int>>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    int m,n,total;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (total % 2 == 0) {   //往min
            //对比num和max的top
            if (maxheap.size() && num < maxheap.top()) {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }else{
                minheap.push(num);
            }
        }else{                  //往max
            //对比num和min
            if (minheap.size() && num > minheap.top()) {
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
            }else{
                maxheap.push(num);
            }
        }
        total++;
    }
    
    double findMedian() {
        if (total % 2 == 0) {   //oushu
            return (maxheap.top() + minheap.top()) * 0.5;
        }else{                  //奇数
            return minheap.top();
        }
    }
};

void _offer_41_repeat_test()
{
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    double param_2 = obj->findMedian();
    obj->addNum(3);
    double param_3 = obj->findMedian();
    
}
