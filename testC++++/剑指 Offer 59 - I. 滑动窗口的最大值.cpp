//
//  剑指 Offer 59 - I.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 59 - I. 滑动窗口的最大值.hpp"
#include "common.h"

vector<int> _offer_59_repeat_testmaxSlidingWindow(vector<int>& nums, int k) {

    vector<int> res;
    
    int n = (int)nums.size();
    //val : index
    priority_queue<pair<int, int>>queue;
    for (int left = 0; left <k; left++) {
        queue.push({nums[left],left});
    }
    
    res.push_back(queue.top().first);
    
    for (int left = k; left < n ; left++) {
        queue.push({nums[left],left});
        while (queue.top().second <= left-k) {
            queue.pop();
        }
        res.push_back(queue.top().first);
    }
    
    return res;
    }

void _offer_59_repeat_test()
{
    vector<int> list1 = {1,3,-1,-3,5,3,6,7};
    vector<int>res= _offer_59_repeat_testmaxSlidingWindow(list1,3);
    
}
