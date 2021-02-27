//
//  剑指 Offer 67.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 67. 把字符串转换成整数.hpp"
#include "common.h"

int strToInt(string str) {

    int len = (int)str.length();
    if (len == 0) {
        return 0;
    }
    long long res = 0;
    int l = 0;
    //去除空格
    while (str[l] == ' ' && l < len) {
        l++;
    }
    //符号
    bool isUnderZero = false;
    if ((str[l] == '-' || str[l] == '+')  && l < len) {
        isUnderZero = (str[l++] == '-');
    }
    //数字
    for (int i = l; i<len; i++) {
        char c = str[i];
        if (c>='0' && c<='9'){
            if (res * 10 > INT_MAX) {
                return (isUnderZero?INT_MIN:INT_MAX);
            }
            res = res * 10 + (c-'0');
        }else{
            break;
        }
    }
    res = (res == (int)res)?(isUnderZero?(-(int)res):(int)res):(isUnderZero?INT_MIN:INT_MAX);
    return (int)res;
}

void _offer_67_repeat_test()
{
    int res1= strToInt("   -42");
    int res2= strToInt("4193 with words");
    int res3= strToInt("words and 987");
    int res4= strToInt("20000000000000000000");
    
    
    
}
