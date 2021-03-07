//
//  9998_最长公共子串.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/14.
//

#include "9998_最长公共子串.hpp"
#include "common.h"

//求子串
int lcstring2(string s1,string s2){
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
                //注意,这里只要末尾不相等就是0 ,所以是连续判断,是子串
                dp[i][j] = 0;

            }
            maxv = max(maxv,dp[i][j] );
        }
    }
    return maxv;
}

//求子序列
int lcstring1(string s1,string s2){
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
                //注意,这里相当于会把dp[0]传递到dp[x],中间跨度了n个,所以是不连续的子序列
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            }
            maxv = max(maxv,dp[i][j] );
        }
    }
    return maxv;
}

void _9998_test()
{
    string s1 = "1AB2345CD";
    string s2 = "12345EF";
    //子序列,12345
    int res1 = lcstring1(s1,s2);
    //子串,2345
    int res2 = lcstring2(s1,s2);
    
}
