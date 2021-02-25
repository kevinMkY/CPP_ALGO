//
//  剑指 Offer 10- I.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "剑指 Offer 10- I. 斐波那契数列.hpp"
#include "common.h"

int _offer_10_repeat_testfib(int n) {

    vector<int> dp(n+1);
    dp[0]=0;
    if (n>0) {
        dp[1]=1;
    }
    
    for (int i = 2; i<=n; i++) {
        dp[i] = (dp[i-1]+dp[i-2])%1000000007;
    }
    
    return dp[n];
    }

void _offer_10_repeat_test()
{
    int res = _offer_10_repeat_testfib(45);
    
    
}
