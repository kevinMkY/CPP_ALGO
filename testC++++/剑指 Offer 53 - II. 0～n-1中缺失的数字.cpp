//
//  剑指 Offer 53 - II.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 53 - II. 0～n-1中缺失的数字.hpp"
#include "common.h"

//方法一,异或
int _offer_53_02_repeat_testmissingNumber(vector<int>& nums) {

    int n = (int)nums.size();
    
    int res = n;
    for (int i =0; i<n; i++) {
        res ^= (nums[i]^i);
    }
    
    return res;
    }

//方法二,二分
int _offer_53_02_repeat_testmissingNumber2(vector<int>& nums) {

    int n = (int)nums.size();
    
    int l = 0;
    int r= n-1;
    while (l <= r) {
        int m = (l+r)>>1;
        if (nums[m] == m) {
            l = m+1;
        }else{
            r = m-1;
        }
    }
    
    return l;
    }

void _offer_53_02_repeat_test()
{
    vector<int> list1 = {0,1,3};
    int res = _offer_53_02_repeat_testmissingNumber2(list1);
    
}
