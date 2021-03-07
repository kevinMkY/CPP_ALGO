//
//  题库10最长公共子串.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/6.
//

#include "题库10最长公共子串.hpp"
#include "common.h"


string _tk_10_test_LCS(string s1, string s2) {
    if (s1.length() == 0 || s2.length() == 0) {
        return 0;
    }
    int maxv = 0;
    int start = -1;
    vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
    for (int i = 1; i<=s1.length(); i++) {
        for (int j = 1; j<=s2.length(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] =dp[i-1][j-1]+1;
                if (maxv<dp[i][j]) {
                    maxv = dp[i][j];
                    start = i - maxv;
                }
            }
        }
    }
    return s1.substr(start,maxv);
}

string _tk_10_test_LCS2(string s1, string s2) {
 
    int l1 = s1.length();
    int l2 = s2.length();
    int maxv = 0;
    int lastIdx = 0;
    vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
    for (int i = 1; i<=l1; i++) {
        for (int j = 1; j<=l2; j++) {
            char c1 = s1[i-1];
            char c2 = s2[j-1];
            if (c1 == c2) {
                dp[i][j]=dp[i-1][j-1]+1;
                if (maxv < dp[i][j]) {
                    maxv = dp[i][j];
                    lastIdx = (i-1);
                }
            }else{
                dp[i][j]=0;
            }
        }
    }
    if (maxv == 0) {
        return "";
    }
    return s1.substr(lastIdx-maxv+1,maxv);
}

void _tk_10_test()
{
    string s1 = "1AB2345CD";
    string s2 = "12345EF";
    string res = _tk_10_test_LCS2(s1,s2);
    
}
