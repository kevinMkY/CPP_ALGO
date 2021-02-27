//
//  剑指 Offer 53 - I.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 53 - I. 在排序数组中查找数字 I.hpp"
#include "common.h"

int _offer_53_repeat_testsearch(vector<int>& nums, int target) {

    int n = (int)nums.size();
    map<int, int>mymap;
    for (int i = 0; i<n; i++) {
        int c = nums[i];
        mymap[c]++;
    }
    if (mymap.find(target) == mymap.end()) {
        return 0;
    }
    return mymap[target];
    }

//本质上看， helper() 函数旨在查找数字 tartar 在数组 numsnums 中的 插入点 ，且若数组中存在值相同的元素，则插入到这些元素的右边。
int _offer_53_repeat_test(vector<int>& nums, int target) {
    
    int l = 0;
    int r = (int)nums.size()-1;
    while (l<=r) {
        int m = (l+r)>>1;
        if (target >= nums[m]) {
            l = m+1;
        }else{
            r = m-1;
        }
    }
    
    return l;
}

int _offer_53_repeat_testsearch2(vector<int>& nums, int target) {
 
    return  _offer_53_repeat_test(nums, target) -
            _offer_53_repeat_test(nums, target-1);
}

void _offer_53_repeat_test()
{
    vector<int> list1 = {5,7,7,8,8,10};
    vector<int> list2 = {5,7,7,8,8,10};
    
//    int res = _offer_53_repeat_testsearch2(list1, 8);
    int res = _offer_53_repeat_testsearch2(list2, 6);
    
}
