//
//  剑指 Offer 57.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 57. 和为s的两个数字.hpp"
#include "common.h"

//哈希
vector<int> _offer_57_repeat_testtwoSum(vector<int>& nums, int target) {

    vector<int> res;
    int n = (int)nums.size();
    map<int, int>mymap;
    for (int i = 0; i<n; i++) {
        int val = nums[i];
        int modify = target - val;
        if (mymap.find(modify) == mymap.end()) {
            mymap[val] = i;
        }else{
            return {modify,val};
        }
        
    }
    return res;
    }

//双指针
vector<int> _offer_57_repeat_testtwoSum2(vector<int>& nums, int target) {
 
    int n = nums.size();
    
    int left = 0;
    int right = n-1;
    while (left<right) {
        int sum = nums[left] + nums[right];
        if (sum > target) {
            right--;
        }else if(sum < target){
            left++;
        }else{
            return {nums[left],nums[right]};
        }
    }
    
    return {};
}

void _offer_57_repeat_test()
{
    vector<int>list1={2,7,11,15};
    
    vector<int>res = _offer_57_repeat_testtwoSum2(list1,9);
    
}
