//
//  78_子集.cpp
//  testC++++
//
//  Created by mm on 2021/2/19.
//

#include "78_子集.hpp"
#include "common.h"

//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//
//
//
//示例 1：
//
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//示例 2：
//
//输入：nums = [0]
//输出：[[],[0]]
//
//
//提示：
//
//1 <= nums.length <= 10
//-10 <= nums[i] <= 10
//nums 中的所有元素 互不相同
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/subsets
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<vector<int>> subsets(vector<vector<int>>& nums,int extraNum) {
    int n =(int)nums.size();
    for (int i = 0; i<n; i++) {
        vector<int>levelres = nums[i];
        levelres.push_back(extraNum);
        nums.push_back(levelres);
    }
    nums.push_back({extraNum});
    return nums;
}

vector<vector<int>> subsets(vector<int>& nums) {
    int n = (int)nums.size();
    if (n == 0) {
        return {};
    }
    vector<vector<int>> res{{nums[0]}};
    
    for (int i = 1; i<n; i++) {
        res = subsets(res,nums[i]);
    }
    res.push_back({});
    return res;
    }


void _78_test()
{

    vector<int> list1 = {1,2,3};
    vector<int> list2 = {0};
    vector<vector<int>>res= subsets(list2);
    


}
