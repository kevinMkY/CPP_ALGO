//
//  14_最长公共前缀.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#import "14_最长公共前缀.hpp"
#import "common.h"

//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。
//
//示例 1:
//
//输入: ["flower","flow","flight"]
//输出: "fl"
//示例 2:
//
//输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
//说明:
//
//所有输入只包含小写字母 a-z 。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/longest-common-prefix
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
