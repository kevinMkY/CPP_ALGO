//
//  剑指 Offer 19.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 19. 正则表达式匹配.hpp"
#include "common.h"

bool _offer_19_testisMatch(string s, string p) {

    int l1 = (int)s.length();
    int l2 = (int)p.length();
    
    vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
    dp[0][0]=1;
    for (int j = 1; j<=l2; j++) {
        //模式串
        char s2 = p[j-1];
        if (s2 == '*') {    // * 前面一定有字母,所以*往前2的位置一定存在
            dp[0][j] = dp[0][j-2];
        }else{
            dp[0][j] = 0;
        }
    }
    
    for (int i = 1; i<=l1; i++) {
        //s串
        char s1 = s[i-1];
        for (int j = 1; j<=l2; j++) {
            //模式串
            char s2 = p[j-1];
            if (s2 == s1 || s2 == '.') {         // A : A  A : .
                dp[i][j] = dp[i-1][j-1];
            }else if (s2 == '*'){   // A : *
                // * 前面一定有字母,所以*往前2的位置一定存在
                if (dp[i][j-2]) {
                    dp[i][j]=dp[i][j-2];
                }else{
                    char s3 = p[j-2];
                    if (s3 == s1 || s3 =='.') {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
    }
    
    return dp[l1][l2];
}

void _offer_19_test()
{
    bool res = _offer_19_testisMatch("aaabcaab", "a*b.a*b");
    
}
