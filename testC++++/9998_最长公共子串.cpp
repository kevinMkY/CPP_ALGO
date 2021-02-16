//
//  9998_最长公共子串.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/14.
//

#include "9998_最长公共子串.hpp"
#include "common.h"

int lcstring(string s1,string s2){
    if (s1.length() == 0 || s2.length() == 0) {
        return 0;
    }
    int maxv = 0;
    vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
    for (int i = 1; i<=s1.length(); i++) {
        for (int j = 1; j<=s2.length(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] =dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            maxv = max(maxv,dp[i][j] );
        }
    }
    return maxv;
}

void _9998_test()
{
    string s1 = "abcd";
    string s2 = "bbcd";
    int res = lcstring(s1,s2);
    
}
