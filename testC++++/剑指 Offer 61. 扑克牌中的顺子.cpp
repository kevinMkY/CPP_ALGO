//
//  剑指 Offer 61.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 61. 扑克牌中的顺子.hpp"
#include "common.h"

bool isStraight(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    
    int n = (int)nums.size();
    int maxv = 0;
    int minv = 14;
    for (int i = 0; i<n; i++) {
        if (nums[i] == 0) {
            continue;
        }
        if (i > 0 && nums[i-1] == nums[i]) {
            return false;
        }
        maxv = max(maxv, nums[i]);
        minv = min(minv, nums[i]);
    }
    
    return maxv - minv < 5;
    }

void _offer_61_repeat_test()
{
    vector<int> list1 = {1,2,3,4,5};
    vector<int> list2 = {1,2,0,4,6};
    
    bool res = isStraight(list2);
    
    
}
