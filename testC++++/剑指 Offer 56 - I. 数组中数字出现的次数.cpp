//
//  剑指 Offer 56 - I.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 56 - I. 数组中数字出现的次数.hpp"
#include "common.h"

vector<int> singleNumbers(vector<int>& nums) {
    
    int a = 0,b=0,res = 0,h=1;
    for (int num : nums) {
        res ^= num;
    }
    while ((res & h)==0) {
        h<<=1;
    }
    for (int num : nums) {
        if (num & h) {
            a^=num;
        }else{
            b^=num;
        }
    }
    
    return {a,b};
    }

void _offer_56_repeat_test()
{
    vector<int> list1 = {1,2,5,2};
    vector<int>res = singleNumbers(list1);
    
}
