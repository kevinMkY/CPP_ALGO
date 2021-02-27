//
//  剑指 Offer 39.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 39. 数组中出现次数超过一半的数字.hpp"
#include "common.h"

//排序 +中点
int _offer_39_repeat_testmajorityElement(vector<int>& nums) {

    int n = (int)nums.size();
    if (n == 0) {
        return n;
    }
    sort(nums.begin(), nums.end());
    
    return nums[n/2];
    }

//投票
int _offer_39_repeat_testmajorityElement2(vector<int>& nums) {
 
    int n = (int)nums.size();
    if (n == 0) {
        return n;
    }
    int votecount = 1;
    int votenum = nums[0];
    
    for (int i = 1; i<n; i++) {
        if (nums[i] != votenum) {
            votecount--;
        }else{
            votecount++;
        }
        if (votecount==0) {
            votenum=nums[i+1];
            votecount++;
            i++;
        }
    }
    
    return votenum;
}


void _offer_39_repeat_test()
{
    vector<int> list1 = {1,2,3,2,2,2,5,4,2};
    int res = _offer_39_repeat_testmajorityElement2(list1);
    
}
