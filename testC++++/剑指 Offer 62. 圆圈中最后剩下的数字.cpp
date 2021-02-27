//
//  剑指 Offer 62.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 62. 圆圈中最后剩下的数字.hpp"
#include "common.h"


//约瑟夫环
int lastRemaining(int n, int m) {

    //n个数字最后剩下的那个序号
    vector<int>dp(n+1);
    dp[1]=0;
    for (int i = 2; i<=n; i++) {
        //dp[i]假如是最后一轮的0
        //那么它在上一轮,是dp[i-1]+m的位置
        dp[i] = (dp[i-1]+m)%i;
    }
    
    return dp[n];
    }

void _offer_62_repeat_test()
{
    
    int res = lastRemaining(5,3);
    
    
}
