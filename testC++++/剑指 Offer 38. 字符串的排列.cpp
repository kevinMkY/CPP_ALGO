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


vector<string> _offer_38_repeat_test_dfs3_res;
void _offer_38_repeat_test_dfs3(
                                string s,
                                int x
                                ){
    if (x == s.length() -1) {
        _offer_38_repeat_test_dfs3_res.push_back(s);
        return;
    }
    map<int, int>mymap;
    for (int i = x; i<s.length(); i++) {
        if (mymap.find(s[i]) != mymap.end()) {
            continue;
        }
        mymap[s[i]]=1;
        swap(s[i],s[x]);
        _offer_38_repeat_test_dfs3(s, x+1);
        swap(s[i],s[x]);
    }
}

vector<string> permutation3(string s) {
    _offer_38_repeat_test_dfs3(s,0);
    return _offer_38_repeat_test_dfs3_res;
}

void permutation3Dfs(vector<string>&res,
                     string &s,
                     int k){
    if (k == s.length()-1) {
        res.push_back(s);
        return;
    }
    
    map<int, int>mymap;
    for (int i = k; i<s.length(); i++) {
        if (mymap.find(s[i])!=mymap.end()) {
            continue;
        }
        mymap[s[i]]++;
        swap(s[i], s[k]);
        permutation3Dfs(res, s, k+1);
        swap(s[i], s[k]);
    }
}

vector<string> permutation4(string s) {
    
    vector<string> res;
    string path;
    permutation3Dfs(res,s,0);
    return res;
}

void _offer_38_repeat_test()
{
//    vector<string>res =  permutation("abc");
    vector<string>res2 =  permutation4("aab");
    
}
