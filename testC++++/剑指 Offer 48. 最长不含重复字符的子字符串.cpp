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
    int left = 0;
    int maxv = 0;
//    vector<int>mymap(128,0);
    map<int, int>mymap;
    for (int i = 0; i<l; i++) {
        char c = s[i];
        mymap[c]++;
        while (mymap[c] >= 2) {
            mymap[s[left]]--;
            left++;
        }
        maxv = max(maxv, i - left + 1);
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
