//
//  剑指 Offer 43.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 43. 1～n 整数中 1 出现的次数.hpp"
#include "common.h"

int countDigitOne(int n) {
    long digit = 1;
    int high = n/10;
    int cur = n%10;
    int low = 0;
    int res = 0;
    
    while (high!=0 || cur!=0) {
        if (cur == 0) {
            res+= digit * high;
        }else if (cur == 1) {
            res += digit * high + low+1;
        }else{
            res+= (high + 1 ) * digit;
        }
        low+=cur * digit;
        cur = high%10;
        high/=10;
        digit*=10;
    }
    
    return res;
    }

void _offer_43_repeat_test()
{
    
    int res= countDigitOne(2);
    
}
