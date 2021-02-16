//
//  1143_最长公共子序列.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/13.
//

#include "1143_最长公共子序列.hpp"
#include "common.h"

//给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
//
//一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
//例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
//
//若这两个字符串没有公共子序列，则返回 0。
//
//
//
//示例 1:
//
//输入：text1 = "abcde", text2 = "ace"
//输出：3
//解释：最长公共子序列是 "ace"，它的长度为 3。
//示例 2:
//
//输入：text1 = "abc", text2 = "abc"
//输出：3
//解释：最长公共子序列是 "abc"，它的长度为 3。
//示例 3:
//
//输入：text1 = "abc", text2 = "def"
//输出：0
//解释：两个字符串没有公共子序列，返回 0。
//
//
//提示:
//
//1 <= text1.length <= 1000
//1 <= text2.length <= 1000
//输入的字符串只含有小写英文字符。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/longest-common-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int longestCommonSubsequence(string text1, string text2) {
    if (text1.length() == 0 || text2.length() == 0) {
        return 0;
    }
    vector<int>colv(text2.length()+1,0);
    vector<vector<int>> dp(text1.length()+1,colv);
    for (int i = 1; i<=text1.length(); i++) {
        string s1 = text1.substr(i-1,1);
        for (int j = 1; j<=text2.length(); j++) {
            string s2 = text2.substr(j-1,1);
            if (s1 == s2) {
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return dp[text1.length()][text2.length()];
    }

void _1143_test()
{
    string s1 = "abc";
    string s2 = "abc";
    int res1 = longestCommonSubsequence(s1,s2);
    
}
