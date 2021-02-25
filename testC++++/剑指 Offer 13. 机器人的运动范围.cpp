//
//  剑指 Offer 13.cpp
//  testC++++
//
//  Created by mm on 2021/2/25.
//

#include "剑指 Offer 13. 机器人的运动范围.hpp"
#include "common.h"


//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
//
//
//
//示例 1：
//
//输入：m = 2, n = 3, k = 1
//输出：3
//示例 2：
//
//输入：m = 3, n = 1, k = 0
//输出：1
//提示：
//
//1 <= n,m <= 100
//0 <= k <= 20
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



int indexBitSum(int i,int j){
    int sum = 0;
    while (i > 0 || j > 0) {
        if (i>0) {
            sum += i%10;
            i /=10;
        }
        if (j > 0) {
            sum += j%10;
            j /=10;
        }
    }
    
    return sum;
}

int movingCount(int m, int n, int k) {
    
    vector<vector<int>>dp(m,vector<int>(n,0));
    int maxv = 0;
    for (int i = 0 ; i<m; i++) {
        for (int j = 0 ; j<n; j++) {
            int res = (indexBitSum(i, j) <= k);
            if (i > 0 && j > 0) {
                res &= dp[i-1][j] || dp[i][j-1];
            }else if (i > 0){
                res &= dp[i-1][j];
            }else if (j > 0){
                res &= dp[i][j-1];
            }
            dp[i][j] = res;
            maxv+=dp[i][j];
        }
    }
    return maxv;
}

void _offer_13_repeat_test()
{
//    int res1 = movingCount(16,8,4);
//    int res2 = movingCount(3,2,17);
//    int res3 = movingCount(2,3,1);
//    int res4 = movingCount(3,1,0);
    int res5 = movingCount(38,15,9);
    
}
