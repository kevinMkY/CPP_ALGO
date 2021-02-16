//
//  121_买卖股票的最佳时机.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/9.
//

#include "121_买卖股票的最佳时机.hpp"
#include "common.h"

//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//
//你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//
//返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
//
//
//
//示例 1：
//
//输入：[7,1,5,3,6,4]
//输出：5
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
//示例 2：
//
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
//
//
//提示：
//
//1 <= prices.length <= 105
//0 <= prices[i] <= 104
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int maxProfit(vector<int>& prices) {

    int minP = INT_MAX;
    int max_profit = INT_MIN;
    for (int i = 0;i<prices.size();i++) {
        int todayP = prices[i] ;
        if (todayP < minP) {    //买入
            minP = todayP;
            continue;
        }
        int cur_profit = todayP - minP;
        if (cur_profit > max_profit) {
            max_profit = cur_profit;
        }
    }
    
    return max_profit > INT_MIN ? max_profit : 0;
    }

//第i天卖出的最大利润
int dp(int day){
    
    return 0;
}

int maxProfit2(vector<int>& prices) {

    if (prices.size() == 0) {
        return 0;
    }
    //前i天的最大利润
    vector<int> dp(prices.size()+1,0);
    dp[0] = 0;
    int minprice = prices[0];
    
    for (int i = 1 ; i < prices.size();i++) {
        dp[i] = max(dp[i-1], prices[i]-minprice);
        minprice = min(minprice,prices[i]);
    }
    return dp[prices.size()-1];
    }

void _121_test()
{
    vector<int> list1 = {7,1,5,3,6,4};
    int res1 = maxProfit(list1);
    int res2 = maxProfit2(list1);
    
}
