//
//  剑指 Offer 65.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 65. 不用加减乘除做加法.hpp"
#include "common.h"

int add(int a, int b) {

    if (b==0) {
        return a;
    }
    //计算进位
    int high = (a&b)<<1;
    //a+b的结果,如果不算进位 ,等同于异或
    a ^=b;
    //将进位存储于b,在下次add里给a+
    b=high;
    
    return add(a, b);
    }

void _offer_65_repeat_test()
{
    int res = add(-1, 2);
    
}
