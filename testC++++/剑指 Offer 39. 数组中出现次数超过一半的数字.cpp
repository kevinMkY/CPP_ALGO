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

int _offer_39_repeat_testmajorityElement3(vector<int> list1){
    
    int n = list1.size();
    if ( n < 1) {
        return 0;
    }
    int voteNum = list1[0];
    int voteCount = 1;
    for (int i = 1; i<n; i++) {
        if (voteCount == 0) {
            voteCount++;
            voteNum=list1[i];
        }else if (list1[i] != voteNum) {
            voteCount--;
        }else{
            voteCount++;
        }
    }
    
    return voteNum;
}

void _offer_39_repeat_test()
{
    vector<int> list1 = {1,2,3,2,2,2,5,4,2};
    int res = _offer_39_repeat_testmajorityElement3(list1);
    
}
