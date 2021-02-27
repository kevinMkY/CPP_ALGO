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

//滑动窗口
//
int lengthOfLongestSubstring2(string s) {
    
    int l = (int)s.length();
    if (l < 2) {
        return l;
    }
    
    int left = 0;
    int maxv = 0;
    map<char, int>mymap;
    for (int right = 0; right<l; right++) {
        char c = s[right];
        mymap[c]++;
        while (mymap[c] > 1) {
            mymap[s[left]]--;
            left++;
        }
        maxv = max(maxv, right - left +1);
    }
    
    return maxv;
}


void _offer_48_repeat_test()
{
    int res1 = lengthOfLongestSubstring2("abcabcbb");
    int res2 = lengthOfLongestSubstring2("tmmzuxt");
    int res3 = lengthOfLongestSubstring2("pwwkew");
    int res4 = lengthOfLongestSubstring2("abba");



}
