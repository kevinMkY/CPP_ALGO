//
//  剑指 Offer 64.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 64. 求1+2+…+n.hpp"
#include "common.h"

int sumNums(int n) {
    //&& 如果n 》 0 ,执行&&右边的
    //如果 n == 0,直接执行下面的return n
    n && (n+=sumNums(n-1));
    return n;
    }

void _offer_64_repeat_test()
{
    int res= sumNums(1);
    
    
    
}
