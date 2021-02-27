//
//  剑指 Offer 60.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 60. n个骰子的点数.hpp"
#include "common.h"

vector<double> dicesProbability(int n) {
    
    //最小n,最大6n,差值6n-n 但是多减了一个,加回来
    vector<double> res(6 *n -n+1);
    
    //dp[n][s] 表示投掷 n 个骰子，n 个朝上的面的点数之和为 s 的事件出现的次数。
    vector<vector<int>>dp(n+1,vector<int>(6*n+1,0));
    
    for (int col =1 ; col<=6;col++) {
        //投一个骰子,每个值出现次数都是1
        dp[1][col] = 1;
    }
    
    for (int count = 2; count <=n; count++) {
        for (int s = count; s <= 6*n; s++) {
            for (int i = 1; i<=6; i++) {
                if (s-i > 0) {
                    dp[count][s] += dp[count-1][s-i];
                }else{
                    break;
                }
            }
        }
    }
    
    double denominator = pow(6.0, n);
    for (int s = n; s<=6*n; s++) {
        double td = dp[n][s]/denominator;
        res[s-n]=td;
    }
    
    return res;
    
    }

void _offer_60_repeat_test()
{
    vector<double>res1 = dicesProbability(1);
    vector<double>res2 = dicesProbability(2);
    vector<double>res3 = dicesProbability(6);
    
    
    
}
