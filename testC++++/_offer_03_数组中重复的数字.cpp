//
//  _offer_03_数组中重复的数字.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "_offer_03_数组中重复的数字.hpp"
#include "common.h"

//map
int findRepeatNumber(vector<int>& nums) {
    
    map<int, int> mymap;
    
    int n = (int)nums.size();
    for (int i = 0; i<n; i++) {
        int val = nums[i];
        if (mymap.find(val) == mymap.end()) {
            mymap[val] = i;
        }else{
            return val;
        }
    }
    
    return 0    ;
    }

//排序交换
int findRepeatNumber2(vector<int>& nums) {
    //2, 3, 1, 0, 2
    int n = (int)nums.size();
    int tmp;
    for (int i = 0; i<n; i++) {
        while (nums[i] != i) {
            if (nums[i] == nums[nums[i]]) {
                return nums[i];
            }
            tmp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = tmp;
        }
    }
    return 0;
}

void _offer_03_test()
{
    vector<int> list1 = {2, 3, 1, 0, 2, 5, 3};
    int res =findRepeatNumber2(list1);
    
}
