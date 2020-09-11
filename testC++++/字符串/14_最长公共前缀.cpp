//
//  14_最长公共前缀.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include "14_最长公共前缀.hpp"
#include "common.h"

//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//
//示例 1：
//
//输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
//示例 2：
//
//输入: "cbbd"
//输出: "bb"
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/longest-palindromic-substring
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

string longestCommonPrefix(vector<string>& strs)
{
    string res = strs.empty() ? "" : strs[0];
    for (string s : strs){
        while (s.find(res) != 0) res = res.substr(0, res.length() - 1);
    }
    return res;
}

void _14_test(){
    vector<string> strs = {"flower","flow","flight"};
    string res = longestCommonPrefix(strs);
    
}
