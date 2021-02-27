//
//  46_全排列.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "46_全排列.hpp"
#include "common.h"

//给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//
//示例:
//
//输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//]
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/permutations
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

void dfs(vector<vector<int>>&res,
         vector<int>&nums,
         vector<int>&used,
         vector<int>&path){
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    
    for (int i = 0; i<nums.size(); i++) {
        if (used[i]) {
            continue;
        }
        used[i] = true;
        path.push_back(nums[i]);
        dfs(res, nums, used, path);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    
    vector<vector<int>> res;
    vector<int>used(nums.size());
    vector<int>path;
    dfs(res, nums, used, path);
    return res;
}

void _46_test()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>>res2 = permute(nums);
    
}
