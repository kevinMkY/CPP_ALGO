//
//  496_下一个更大元素 I.cpp
//  testC++++
//
//  Created by ykh on 2020/9/16.
//

#include "496_下一个更大元素 I.hpp"
#include "common.h"
//
//给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
//
//nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。
//
//
//
//示例 1:
//
//输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
//输出: [-1,3,-1]
//解释:
//    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
//    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
//    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
//示例 2:
//
//输入: nums1 = [2,4], nums2 = [1,2,3,4].
//输出: [3,-1]
//解释:
//    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
//    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
//
//
//提示：
//
//nums1和nums2中所有元素是唯一的。
//nums1和nums2 的数组大小都不超过1000。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/next-greater-element-i
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    vector<int> res = {};
    int size1 = nums1.size();
    int size2 = nums2.size();
    bool allow = false;
    for (int i = 0; i<size1; i++) {
        int count1 = nums1[i];
        for (int j = 0; j<size2; j++) {
            int count2 = nums2[j];
            if (allow) {
                if (count2 > count1) {
                    res.push_back(count2);
                    allow = false;
                    break;
                }else if (j == size2 - 1){
                    res.push_back(-1);
                    allow = false;
                    break;
                }
            }
            if (count1 == count2) {
                if (j == size2 - 1) {
                    res.push_back(-1);
                }else{
                    allow = true;
                }
            }
        }
    }
    
    return res;
    }

void _496_test(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    
    vector<int> nums11 = {2,4};
    vector<int> nums22 = {1,2,3,4};
    
    
    vector<int> res1 = nextGreaterElement(nums1, nums2);
    vector<int> res2 = nextGreaterElement(nums11, nums22);

}
