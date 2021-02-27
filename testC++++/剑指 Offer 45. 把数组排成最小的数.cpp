//
//  剑指 Offer 45.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 45. 把数组排成最小的数.hpp"
#include "common.h"

string comNum(vector<long>path){
    string s;
    for (int i = 0; i<path.size(); i++) {
        s+=to_string(path[i]);
    }
    return s;
}

void dfs(
         vector<string>&res,
         vector<int>&nums,
         vector<long>&used,
         vector<long>&path
         ){
    if (path.size() == nums.size()) {
        string num =comNum(path);
        res.push_back(num);
        return;
    }
    for (int i = 0; i<nums.size(); i++) {
        if (used[i]) {
            continue;
        }
        used[i]=true;
        path.push_back(nums[i]);
        dfs(res, nums, used, path);
        path.pop_back();
        used[i]=false;
    }
    
}

string minNumber(vector<int>& nums) {
    if (nums.size() == 0) {
        return "";
    }
    
    vector<string>res;
    vector<long>used(nums.size());
    vector<long>path;
    
    dfs(res, nums, used,path);
    sort(res.begin(), res.end());
    
    return res[0];
    }

void _offer_45_repeat_test()
{
    
    vector<int>list1 ={1,2,3,4,5,6,7,8,9,0};
    vector<int>list2 ={999999998,999999997,999999999};
    string s = minNumber(list1);
//    string s = minNumber(list2);
    
}
