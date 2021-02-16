//
//  53_最大子序和.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/5.
//

#include "53_最大子序和.hpp"
#include "common.h"

//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//
//
//示例 1：
//
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
//示例 2：
//
//输入：nums = [1]
//输出：1
//示例 3：
//
//输入：nums = [0]
//输出：0
//示例 4：
//
//输入：nums = [-1]
//输出：-1
//示例 5：
//
//输入：nums = [-100000]
//输出：-100000
//
//
//提示：
//
//1 <= nums.length <= 3 * 104
//-105 <= nums[i] <= 105
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/maximum-subarray
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//int maxSubArrayArea(vector<int>& nums,int begin,int end) {
//    if (end - begin < 2) {  //end为size
//        return nums[begin];
//    }
//    int mid = (begin + end) >> 1;
//    int leftMax = maxSubArrayArea(nums, begin, mid);
//    int rightMax = maxSubArrayArea(nums, mid, end);
//    int sideMax = max(leftMax, rightMax);
//
//    int tempLeftSum = 0;
//    int tempLeftMax = INT_MIN;
//    for (int leftbegin = mid-1; leftbegin >= begin; leftbegin--) {
//        tempLeftSum += nums[leftbegin];
//        tempLeftMax = max(tempLeftMax, tempLeftSum);
//    }
//
//    int tempRightSum = 0;
//    int tempRightMax = INT_MIN;
//    for (int rightbegin = mid; rightbegin < end; rightbegin++) {
//        tempRightSum += nums[rightbegin];
//        tempRightMax = max(tempRightMax, tempRightSum);
//    }
//
//    return max(tempLeftMax + tempRightMax, sideMax);
//}
//
//int maxSubArray(vector<int>& nums) {
//    int res = maxSubArrayArea(nums,0,nums.size());
//    return res;
//    }

int maxSubArray1(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int dp[nums.size()];
    int maxv = dp[0] = nums[0];
    for (int i = 1; i<nums.size(); i++) {
        if (dp[i-1] <0) {
            dp[i] = nums[i];
        }else{
            dp[i] = nums[i] + dp[i-1];
        }
        maxv = max(maxv,dp[i]);
    }
    
    return maxv;
    }

void _53_test()
{
    vector<int> list1 = {-2,1,-3,4,-1,2,1,-5,4};
    int res = maxSubArray1(list1);
    
}
