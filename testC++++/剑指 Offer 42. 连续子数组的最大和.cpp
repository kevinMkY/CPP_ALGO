//
//  剑指 Offer 42.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 42. 连续子数组的最大和.hpp"
#include "common.h"

int maxSubArray(vector<int>& nums) {

    int n = (int)nums.size();
    if (n == 0) {
        return 0;
    }
    //以元素nums[i]结尾的最大和
    int pre = nums[0];
    int maxv = pre;
    int cur = 0;
    for (int i = 1; i<n; i++) {
        cur = max(nums[i],pre+nums[i]);
        maxv = max(maxv, cur);
        pre = cur;
    }
    
    return maxv;
    }

void _offer_42_repeat_test()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res= maxSubArray(nums);
    
}
