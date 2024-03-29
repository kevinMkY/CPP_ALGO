//
//  剑指 Offer 21.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 21. 调整数组顺序使奇数位于偶数前面.hpp"
#include "common.h"

bool isJishu(int val){
    
    return (val %2) != 0;
}

vector<int> exchange(vector<int>& nums) {

    int n = (int)nums.size();
    int right = n-1;
    for (int left = 0; left < right; left++) {
        int leftval = nums[left];
        if (leftval %2 ==1) {
            continue;
        }else{
            while (nums[right]%2 == 0 && right>left) {
                right--;
            }
            if (right>left) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
    }
    return nums;
}


vector<int> exchange2(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    int r = n-1;
    while (l<r) {
        if ((nums[l] & 1) == 1) {
            l++;
            continue;
        }
        if ((nums[r] & 1) == 0) {
            r--;
            continue;
        }
        swap(nums[l], nums[r]);
    }
    return nums;
    }

void _offer_21_repeat_test()
{
    vector<int> list1 = {1,2,3,4};
    
    vector<int> res = exchange2(list1);
    
}
