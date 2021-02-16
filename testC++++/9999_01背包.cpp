//
//  9999_01背包.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/14.
//

#include "9999_01背包.hpp"
#include "common.h"

/*
 有n件重量分别为weight,价值分别为value的物品,要求不超过重量bages的情况下,选一个最大价值
 */

int bag01(vector<int>& values,vector<int>& weights,int bages){
    if (values.size() == 0 || weights.size() == 0 || bages <= 0) {
        return 0;
    }
    vector<int> v1(bages+1,0);
    vector<vector<int>> dp(values.size()+1,v1);
    int maxv = 0;
    
    //dp[i][j] 总重量为j,前i件物品
    
    for (int i = 1; i<=values.size(); i++) {
        for (int j = 1; j<=bages; j++) {
            if (j < weights[i-1]) {
                dp[i][j] = dp[i-1][j];
            }else{
                int xuanle  = dp[i-1][j-weights[i-1]] + values[i-1];
                int meixuan = dp[i-1][j];
                dp[i][j] = max(xuanle,meixuan);
            }
            maxv = max(maxv, dp[i][j]);
        }
    }
    
    return dp[values.size()][bages]<0?-1:dp[values.size()][bages];
}

/*
 有n件重量分别为weight,价值分别为value的物品,要求重量刚刚=bages的情况下,选一个最大价值
 */

int bag02(vector<int>& values,vector<int>& weights,int bages){
    if (values.size() == 0 || weights.size() == 0 || bages <= 0) {
        return 0;
    }
    vector<int> v1(bages+1,-INT_MAX);
    v1[0]=0;
    vector<vector<int>> dp(values.size()+1,v1);
    int maxv = 0;
    
    //dp[i][j] 总重量为j,前i件物品
    
    for (int i = 1; i<=values.size(); i++) {
        for (int j = 1; j<=bages; j++) {
            if (j < weights[i-1]) {
                dp[i][j] = dp[i-1][j];
            }else{
                int xuanle  = dp[i-1][j-weights[i-1]] + values[i-1];
                int meixuan = dp[i-1][j];
                dp[i][j] = max(xuanle,meixuan);
            }
            maxv = max(maxv, dp[i][j]);
        }
    }
    
    return maxv;
}

void _9999_test()
{
    vector<int> list1 = {6,3,5,4,6};
    vector<int> list2 = {2,2,6,5,4};
    int flag1 = 10;
    
    
    int res1 = bag02(list1,list2,flag1);
    
}
