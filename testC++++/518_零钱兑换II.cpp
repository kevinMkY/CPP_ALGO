//
//  518_零钱兑换II.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/7.
//

#include "518_零钱兑换II.hpp"
#include "common.h"

//给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。
//
//
//
//示例 1:
//
//输入: amount = 5, coins = [1, 2, 5]
//输出: 4
//解释: 有四种方式可以凑成总金额:
//5=5
//5=2+2+1
//5=2+1+1+1
//5=1+1+1+1+1
//示例 2:
//
//输入: amount = 3, coins = [2]
//输出: 0
//解释: 只用面额2的硬币不能凑成总金额3。
//示例 3:
//
//输入: amount = 10, coins = [10]
//输出: 1
//
//
//注意:
//
//你可以假设：
//
//0 <= amount (总金额) <= 5000
//1 <= coin (硬币面额) <= 5000
//硬币种类不超过 500 种
//结果符合 32 位符号整数
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/coin-change-2
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


/*
 5=5
 5=2+2+1
 5=2+1+1+1
 5=1+1+1+1+1
 */

int change(int amount, vector<int>& coins) {
    
    sort(coins.begin(), coins.end());
    vector<int> dp(amount+1,0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int curamount = 1; curamount <= amount; curamount++) {
            if (curamount >= coin) {
                dp[curamount] = dp[curamount - coin] + dp[curamount];
                printf("curamount = %d,coin = %d, dp[%d] = %d \n",curamount,coin,curamount,dp[curamount]);
            }
        }
    }
    
    return dp[amount];
}

void _518_test()
{
    vector<int> list1 = {1,2,5};
    int res1 = change(5,list1);
    
}
