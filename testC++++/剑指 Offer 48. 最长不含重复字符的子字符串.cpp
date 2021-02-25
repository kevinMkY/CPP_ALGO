//
//  剑指 Offer 48.cpp
//  testC++++
//
//  Created by mm on 2021/2/26.
//

#include "剑指 Offer 48. 最长不含重复字符的子字符串.hpp"
#include "common.h"


int lengthOfLongestSubstring(string s) {

    int l = (int)s.length();
    int left = -1;
    int maxv = 0;
    map<char, int>mymap;
    for (int i = 0; i<l; i++) {
        char c = s[i];
        if (mymap.find(c) == mymap.end()) {
            mymap[c] = i;
        }else{
            left = mymap[c];
        }
        maxv = max(maxv, i-left);
    }
    
    return maxv;
    }


void _offer_48_repeat_test()
{

    int res1 = lengthOfLongestSubstring("abcabcbb");
    int res2 = lengthOfLongestSubstring("tmmzuxt");
    int res3 = lengthOfLongestSubstring("pwwkew");
    int res4 = lengthOfLongestSubstring("abba");



}
