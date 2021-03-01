//
//  剑指 Offer 05.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "剑指 Offer 05. 替换空格.hpp"
#include "common.h"

//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
//
//
//
//示例 1：
//
//输入：s = "We are happy."
//输出："We%20are%20happy."
//
//
//限制：
//
//0 <= s 的长度 <= 10000
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

string replaceSpace(string s) {
    int l = (int)s.length();
    if (l == 0) {
        return s;
    }
    string s2;
    for (auto &c : s) {
        if (c == ' ') {
            s2.push_back('%');
            s2.push_back('2');
            s2.push_back('0');
            
        }else{
            s2.push_back(c);
        }
    }
    
    return s2;
    }

string replaceSpace2(string s) {
    int old = (int)s.length();
    if (old == 0) {
        return s;
    }
    int newc = old;
    for (auto &c : s) {
        if (c == ' ') {
            newc+=2;
        }
    }
    
    if (newc == old) {return s;}
        
    s.resize(newc);
    
    for (int i = newc-1 ,j = old-1; j < i;j--, i--) {
        char c = s[j];
        if (c == ' ') {
            s[i] = '0';
            s[i-1] = '2';
            s[i-2] = '%';
            i-=2;
        }else{
            s[i] = s[j];
        }
    }
    
    return s;
}


string replaceSpace3(string s) {
 
    
    int len = s.length();
    if (len < 1) {
        return "";
    }
    int orginindex = len-1;
    for (char c : s) {
        if (c == ' ') {
            len+=2;
        }
    }
    
    s.resize(len);
    for (int i = len-1; i>=0; i--) {
        char c = s[orginindex];
        if (c == ' ') {
            s[i--]='0';
            s[i--]='2';
            s[i]='%';
        }else{
            s[i]=c;
        }
        orginindex--;
    }
    
    
    return s;
    
}

string replaceSpace4(string s) {
 
    int len = s.length();
    if (len == 0) {
        return "";
    }
    
    int newlen = len;
    for (int i = 0; i<len; i++) {
        if (s[i] == ' ') {
            newlen+=2;
        }
    }
    
    int orgindex = len-1;
    s.resize(newlen);
    for (int i = newlen - 1; i>=0; i--) {
        char c = s[orgindex];
        if (c == ' ') {
            s[i--] = '0';
            s[i--] = '2';
            s[i] = '%';
        }else{
            s[i]=s[orgindex];
        }
        orgindex--;
    }
    
    return s;
}

void _offer_05_repeat_test()
{
    string s1 = "We are happy.";
    
    string res = replaceSpace4(s1);
    
}
