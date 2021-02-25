//
//  剑指 Offer 10- II.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "剑指 Offer 10- II. 青蛙跳台阶问题.hpp"
#include "common.h"

int numWays(int n) {

    vector<int> dp(n+1);
    
    dp[0]=1;
    if (n>0) {
        dp[1]=1;
    }
    
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%1000000007;
    }
    
    return dp[n];
    }

void __offer_10_repeat2_test()
{
    int res = numWays(7);
    
}
