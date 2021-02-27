//
//  剑指 Offer 50.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 50. 第一个只出现一次的字符.hpp"
#include "common.h"

char firstUniqChar(string s) {

    int l = (int)s.length();
    map<int, int>mymap;
    vector<char>vc;
    for (int right = 0; right < l; right++) {
        char c = s[right];
        mymap[c]++;
        if (mymap[c]==1) {
            vc.push_back(c);
        }
    }
    
    for (int left = 0; left < vc.size(); left++) {
        char c = vc[left];
        if (mymap[c] == 1) {
            return c;
        }
    }
    
    return ' ';
    }

void _offer_50_repeat_test()
{
    char res = firstUniqChar("dddccdbba");
    
}
