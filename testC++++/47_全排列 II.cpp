//
//  47_全排列 II.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "47_全排列 II.hpp"
#include "common.h"

void _47_testdfs(vector<vector<int>>&res,
         vector<int>&nums,
         vector<int>&used,
         vector<int>&path
         ){
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    
    for (int i = 0; i<nums.size(); i++) {
        if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) {
            continue;
        }
        used[i] = true;
        path.push_back(nums[i]);
        _47_testdfs(res, nums,used, path);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    vector<vector<int>>res;
    vector<int>used(nums.size());
    vector<int>path;
    _47_testdfs(res, nums, used, path);
    return res;
    }

void _47_test()
{
    vector<int> nums = {1,1,2};
    vector<vector<int>>res2 = permuteUnique(nums);
    
}
