//
//  剑指 Offer 11.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "剑指 Offer 11. 旋转数组的最小数字.hpp"
#include "common.h"

int minArray(vector<int>& numbers) {

    int n = (int)numbers.size();
    if (n == 0) {
        return 0;
    }
    int maxv = numbers[0];
    for (int i = 1; i<n; i++) {
        if (numbers[i] < maxv) {
            return numbers[i];
        }
    }
    
    return maxv;
    }

int _offer_11_repeat_testminArray2(vector<int>& numbers) {
    
    int n = numbers.size();
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return numbers[0];
    }
    
    int l = 0;
    int r = n-1;
    int mid = l;
    while (numbers[l]>=numbers[r]) {
        if (r-l==1) {
            mid = r;
            break;
        }
        mid = (l+r)>>1;
        if (numbers[mid]<=numbers[r]) {
            r=mid;
        }else if (numbers[mid]>=numbers[l]) {
            l=mid;
        }
    }
    
    return numbers[mid];
}

void _offer_11_repeat_test()
{
    vector<int> list1 = {1,2,3};
    
    int res = _offer_11_repeat_testminArray2(list1);
    
}
