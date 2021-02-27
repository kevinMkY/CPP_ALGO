//
//  剑指 Offer 63.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 63. 股票的最大利润.hpp"
#include "common.h"

int _offer_63_repeat_testmaxProfit(vector<int>& prices) {

    int n = (int)prices.size();
    
    //假设dp[i]是第i天卖出的时候的最大利润
    vector<int>dp(n+1);
    dp[0]=0;
    int minprice = INT_MAX;
    for (int i = 1; i<=n; i++) {
        //minprice是前i天的最低价格
        minprice = min(minprice, prices[i-1]);
        //dp[i] = max ( 前一天的最大利润 , 今天价格-历史最低价格);
        dp[i]=max(dp[i-1], prices[i-1] - minprice);
    }
    
    return dp[n];
    }


void _offer_63_repeat_test()
{
    vector<int> list1 = {7,1,5,3,6,4};
    
    int res = _offer_63_repeat_testmaxProfit(list1);
    
    
}
