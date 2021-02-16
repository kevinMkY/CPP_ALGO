//
//  300_最长递增子序列.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/13.
//

#include "300_最长递增子序列.hpp"
#include "common.h"

//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//
//子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
//
//
//示例 1：
//
//输入：nums = [10,9,2,5,3,7,101,18]
//输出：4
//解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
//示例 2：
//
//输入：nums = [0,1,0,3,2,3]
//输出：4
//示例 3：
//
//输入：nums = [7,7,7,7,7,7,7]
//输出：1
//
//
//提示：
//
//1 <= nums.length <= 2500
//-104 <= nums[i] <= 104
//
//
//进阶：
//
//你可以设计时间复杂度为 O(n2) 的解决方案吗？
//你能将算法的时间复杂度降低到 O(n log(n)) 吗?
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int lengthOfLIS1(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int dp[nums.size()];
    int maxv = dp[0] = 1;
    for (int i = 1; i<nums.size(); i++) {
        dp[i]=1;
        for (int j = 0; j<i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        maxv = max(maxv,dp[i]);
    }
    return maxv;
    }

void _300_test()
{
    vector<int> list1 = {10,9,2,5,3,7,101,18};
    
    int res1 = lengthOfLIS1(list1);
    
}
