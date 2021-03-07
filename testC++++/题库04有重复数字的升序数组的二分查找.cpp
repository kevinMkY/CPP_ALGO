//
//  题库04有重复数字的升序数组的二分查找.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/5.
//

#include "题库04有重复数字的升序数组的二分查找.hpp"
#include "common.h"

int quickSearchRepeat(vector<int>& nums, int target) {
     
    int l = 0;
    int r = nums.size()-1;
    if (r-l<1) {
        return 0;
    }
    
    int mid = 0;
    int ans = -1;
    while (l<=r) {
        mid = l+((r-l)>>1);
        if (nums[mid] >= target) {
            if (nums[mid] == target) {
                ans = mid;
            }
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
    }

void _tk_04_test()
{
    vector<int> list1 = {1,4,4,4,4,5};
    int res = quickSearchRepeat(list1,4);
     
}
