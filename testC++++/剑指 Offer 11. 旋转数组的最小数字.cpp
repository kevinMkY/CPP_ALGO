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

void _offer_11_repeat_test()
{
    vector<int> list1 = {5,7,1,3};
    
    int res = minArray(list1);
    
}
