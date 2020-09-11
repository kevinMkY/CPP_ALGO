//
//  stringTest.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include "common.h"

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

string longestPalindrome(string s) {
    int totallength = s.length();
    if(totallength == 0){
        return "";
    }else if (totallength == 1){
        return s;
    }else if (totallength == 2){
        if (s.substr(0,1) == s.substr(1,1)) {
            return s;
        }
        return "";
    }else{
        string res;
        int lenghth = 1;
        int index = 0;
        for (int i = 0; i<totallength; i++) {
            string pre = s.substr(index,lenghth);
            string suf = s.substr(totallength-lenghth-index,lenghth);
            if (pre == suf) {
                lenghth++;
            }else{
                index++;
                lenghth = 1;
            }
        }
        
        return res;
    }
}

void _5_test(){
    
    string s = "babad";
    //bug
    string res = longestPalindrome(s);
    
}
