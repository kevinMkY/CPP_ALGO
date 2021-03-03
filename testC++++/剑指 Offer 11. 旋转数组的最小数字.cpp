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
    if ( n  == 0) {
        return 0;
    }
    
    int l = 0,r = numbers.size()-1;
    //{3,3,1,3};
    while (l<r) {
        int mid = (l+r)>>1;
        //
        if (numbers[mid] < numbers[r]) {
            r = mid;
        //
        }else if(numbers[mid] > numbers[r]){
            l = mid+1;
        //
        }else{  //==
            r--;
        }
    }
    
    return numbers[l];
}

void _offer_11_repeat_test()
{
    vector<int> list1 = {3,3,1,3};
    
    int res = _offer_11_repeat_testminArray2(list1);
    
}
