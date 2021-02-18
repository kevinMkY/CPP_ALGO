//
//  977_有序数组的平方.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/17.
//

#include "977_有序数组的平方.hpp"
#include "common.h"

//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
//
//
//
//示例 1：
//
//输入：nums = [-4,-1,0,3,10]
//输出：[0,1,9,16,100]
//解释：平方后，数组变为 [16,1,0,9,100]
//排序后，数组变为 [0,1,9,16,100]
//示例 2：
//
//输入：nums = [-7,-3,2,3,11]
//输出：[4,9,9,49,121]
//
//
//提示：
//
//1 <= nums.length <= 104
//-104 <= nums[i] <= 104
//nums 已按 非递减顺序 排序
//
//
//进阶：
//
//请你设计时间复杂度为 O(n) 的算法解决本问题
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//nums = [-4,-1,0,3,10]
//     = [9,1,0,100,14]
//输出：[0,1,9,16,100]

vector<int> sortedSquares(vector<int>& nums) {

    if (nums.size() == 0) {
        return {};
    }
    for (int i = (int)nums.size()-1; i>=0; i--) {
        nums[i] = pow(nums[i], 2);
    }
    sort(nums.begin(), nums.end());
    return nums;
    }

//nums = [-4,-1,0,3,10]
//     = [16,1,0,9,100]
//输出：[0,1,9,16,100]

vector<int> sortedSquares2(vector<int>& nums) {

    if (nums.size() == 0) {
        return {};
    }
    vector<int> pos(nums.size());
    for (int firstIdex = 0,lastIdex = (int)nums.size()-1,posIndex = (int)nums.size()-1; firstIdex<=lastIdex;) {
        int ff = nums[firstIdex] * nums[firstIdex];
        int ll = nums[lastIdex]  * nums[lastIdex];
        if (ff >= ll) {
            pos[posIndex] = ff;
            firstIdex++;
        }else{
            pos[posIndex] = ll;
            lastIdex--;
        }
        posIndex--;
    }
    
    return pos;
    }

void _977_test()
{
    vector<int> list1 = {-6,-5,2,3,10}; //0,9,25,36,100
    vector<int> list2 = {-4,-1,0,3,10}; //0,1,9,16,100
    vector<int> list3 = {-7,-3,2,3,11}; //4,9,9,49,121
    
    vector<int>  res1 = sortedSquares2(list1);
    vector<int>  res2 = sortedSquares2(list2);
    vector<int>  res3 = sortedSquares2(list3);
    
    
}
