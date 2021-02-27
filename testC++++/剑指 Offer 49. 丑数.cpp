//
//  剑指 Offer 49.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 49. 丑数.hpp"
#include "common.h"

//超时
int nthUglyNumber(int n) {
    vector<int>res;
    res.push_back(1);
    for (int i =2; i<INT_MAX; i++) {
        
        int tmp = i;
        while (tmp%2==0) {
            tmp/=2;
        }
        while (tmp%5==0) {
            tmp/=5;
        }
        while (tmp%3==0) {
            tmp/=3;
        }
        
        if (tmp == 1) {
            res.push_back(i);
        }
        
        if (res.size() >= n) {
            return res[n-1];
        }
    }
    
    return 0;
    }


int nthUglyNumber2(int n) {
 
    if (n < 2) {
        return n;
    }
    vector<int>res;
    vector<int>dp(n+1);
    dp[0]=1;
    int a=0,b=0,c=0;
    for (int i =1; i<n; i++) {
        int n2 = dp[a] * 2;
        int n3 = dp[b] * 3;
        int n5 = dp[c] * 5;
        dp[i] = min(min(n2, n3), n5);
        if (dp[i] == n2) {
            a++;
        }
        if (dp[i] == n3) {
            b++;
        }
        if (dp[i] == n5) {
            c++;
        }
    }
    
    return dp[n-1];
}

void _offer_49_repeat_test()
{
    
    int res = nthUglyNumber2(10);

}
