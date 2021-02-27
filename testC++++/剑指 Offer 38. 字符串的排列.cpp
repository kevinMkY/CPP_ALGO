//
//  剑指 Offer 38.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 38. 字符串的排列.hpp"
#include "common.h"

void dfs(string s,
         vector<string>&res,
         vector<int>&used,
         string path){
    if (path.length() == s.length()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i<s.length(); i++) {
        if (used[i] || (i>0 && s[i] == s[i-1] && !used[i-1])) {
            continue;
        }
        used[i] = true;
        path.push_back(s[i]);
        dfs(s, res, used, path);
        path.pop_back();
        used[i] = false;
    }
}

vector<string> permutation(string s) {
    
    sort(s.begin(),s.end());
    vector<string>res;
    vector<int>used(s.length());
    string path;
    dfs(s, res, used, path);
    return res;
}

void _offer_38_repeat_test()
{
//    vector<string>res =  permutation("abc");
    vector<string>res2 =  permutation("bab");
    
}
