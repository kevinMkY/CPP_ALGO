//
//  剑指 Offer 47.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 47. 礼物的最大价值.hpp"
#include "common.h"

int countPath(vector<int>path){
    int sum = 0;
    for (int i = 0; i<path.size(); i++) {
        sum+=path[i];
    }
    return sum;
}

void _offer_47_repeat_testdfs(
                              vector<vector<int>>& grid,
                              int m,int n,
                              int x,int y,
//                              vector<int>&path,
                              int &path,
                              int &maxv) {
    if (x==m-1 && y==n-1) {
        path+=grid[y][x];
        maxv = max(maxv, path);
        path-=grid[y][x];
        return;
    }
    
    if (x<m && y < n) {
        path+=grid[y][x];
        //往右
        _offer_47_repeat_testdfs(grid, m, n, x+1, y, path, maxv);
        //往下
        _offer_47_repeat_testdfs(grid, m, n, x, y+1, path, maxv);
        path-=grid[y][x];
    }
}

int maxValue(vector<vector<int>>& grid) {
    int n = (int)grid.size();
    if ( n == 0) {
        return 0;
    }
    int m = (int)grid[0].size();
    if ( m == 0) {
        return 0;
    }
    int x = 0;
    int y = 0;
//    vector<int>path;
    int path = 0;
    int maxv = INT_MIN;
    
    _offer_47_repeat_testdfs(grid,m,n, x, y,path, maxv);
    
    return maxv;
    }

int maxValue2(vector<vector<int>>& grid) {
 
    int n = (int)grid.size();
    if ( n == 0) {
        return 0;
    }
    int m = (int)grid[0].size();
    if ( m == 0) {
        return 0;
    }
    
    vector<vector<int>>dp(n,vector<int>(m));
    dp[0][0] = grid[0][0];
    for (int y = 0; y<n; y++) {
        for (int x = 0; x<m; x++) {
            if (x == 0 && y == 0) {
                
                continue;
            }
            int sum1 = 0;
            int sum2 = 0;
            if (x > 0) {
                sum1 = dp[y][x-1] + grid[y][x];
            }
            if (y>0) {
                sum2 = dp[y-1][x] + grid[y][x];
            }
            dp[y][x] = max(sum1, sum2);
        }
    }
    
    return dp[n-1][m-1];
    
}

void _offer_47_repeat_test()
{
    vector<vector<int>> list1 =
    {
            {1,3,1},
            {1,5,1},
            {4,2,1}
    };
    vector<vector<int>> list2 =
    {
            {1,2,5},
            {3,2,1}
    };
    
//    int res1 = maxValue2(list1);
    int res2 = maxValue2(list2);
    
}
