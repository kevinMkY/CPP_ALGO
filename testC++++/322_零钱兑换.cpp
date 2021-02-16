//
//  322_零钱兑换.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/7.
//

#include "322_零钱兑换.hpp"
#include "common.h"

//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
//
//你可以认为每种硬币的数量是无限的。
//
//
//
//示例 1：
//
//输入：coins = [1, 2, 5], amount = 11
//输出：3
//解释：11 = 5 + 5 + 1
//示例 2：
//
//输入：coins = [2], amount = 3
//输出：-1
//示例 3：
//
//输入：coins = [1], amount = 0
//输出：0
//示例 4：
//
//输入：coins = [1], amount = 1
//输出：1
//示例 5：
//
//输入：coins = [1], amount = 2
//输出：2
//
//
//提示：
//
//1 <= coins.length <= 12
//1 <= coins[i] <= 231 - 1
//0 <= amount <= 104
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/coin-change
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//
//int coinChangeInCollect(vector<int>& coins, int amount,vector<int>& dp) {
//
//    for (int curAmount = 1; curAmount<=amount; curAmount++) {
//        if (dp[curAmount] == -1) { //代表当前值未计算过
//            for (int j = 0; j<coins.size(); j++) {
//                int lastcoin = coins[j];
//                if (curAmount > lastcoin) {
//                    int lastCoinCount = dp[curAmount - lastcoin];
//                    if (lastCoinCount == -1) {  //代表上一次这个coin也没集全
//
//                    }else if(dp[curAmount] == -1){
//                        dp[curAmount] = lastCoinCount + 1;
//                    }else{
//                        dp[curAmount] = min(lastCoinCount + 1,dp[curAmount]);
//                    }
//                }else if (curAmount == coins[j]) {
//                    dp[curAmount] = 1;
//                }else{  //curAmount < coins[j]
//
//                }
//            }
//        }
//    }
//    return dp[amount];
//    }
//int coinChange(vector<int>& coins, int amount) {
//    sort(coins.begin(),coins.end());
//    vector<int> dp(amount+1,-1);
//    dp[0] = 0;
//    return coinChangeInCollect(coins,amount,dp);
//    }
//
//int coinChange2(vector<int>& coins, int amount) {
//
//    vector<int> dp(amount+1,INT_MAX-1);
//    dp[0]=0;
//    for (int coin : coins) {
//        for (int curAmount = 1; curAmount <= amount; curAmount ++) {
//            if (curAmount >= coin) {
//                dp[curAmount] = min(dp[curAmount - coin]+1, dp[curAmount]);
//                printf("coin = %d, dp[%d] = %d\n",coin,curAmount,dp[curAmount]);
//            }
//        }
//    }
//    return dp[amount] < INT_MAX -1 ? dp[amount] : -1;
//    }
//
//int coinChange3(vector<int>& coins, int amount) {
//
//    vector<int> dp(amount+1,INT_MAX-1);
//    dp[0]=0;
//
//    return 1;
//    }


int coinChange4(vector<int>& coins, int amount) {

    vector<int> dp(amount+1,INT_MAX-1);
    dp[0]=0;

    for (int coin : coins) {
        for (int curamount = 1; curamount <= amount; curamount++) {
            if (curamount >= coin) {
                dp[curamount] = min(dp[curamount - coin]+1, dp[curamount]);
            }
        }
    }
    
    return dp[amount] < INT_MAX-1 ? dp[amount] : -1;
}


void _322_test()
{
    vector<int> list1 = {1,5,20,25};
    vector<int> list2 = {2};
    vector<int> list3 = {1};
    vector<int> list4 = {1};
    int res1 = coinChange4(list1,41);
    int res2 = coinChange4(list2,3);
    int res3 = coinChange4(list3,0);
    int res4 = coinChange4(list4,1);
//    int res3 = coinChange2(list2,flag2);
//    int res4 = coinChange2(list3,flag3);
//    int res5 = coinChange2(list4,flag4);
    
    
}
