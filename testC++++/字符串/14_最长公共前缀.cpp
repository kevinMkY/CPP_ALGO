//
//  14_最长公共前缀.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include "14_最长公共前缀.hpp"
#include "common.h"

//https://leetcode-cn.com/problems/longest-palindromic-substring/solution/

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
