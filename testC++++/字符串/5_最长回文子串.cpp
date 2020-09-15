//
//  stringTest.cpp
//  testC++++
//
//  Created by ykh on 2020/9/9.
//

#include "common.h"

//5. 最长回文子串
//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
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

//https://leetcode-cn.com/problems/longest-palindromic-substring/

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
