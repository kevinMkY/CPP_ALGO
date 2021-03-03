//
//  _4_寻找两个正序数组的中位数.cpp
//  testC++++
//
//  Created by yekaihua on 2021/3/2.
//

#include "_4_寻找两个正序数组的中位数.hpp"
#include "common.h"

//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//
//
//
//示例 1：
//
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
//示例 2：
//
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
//示例 3：
//
//输入：nums1 = [0,0], nums2 = [0,0]
//输出：0.00000
//示例 4：
//
//输入：nums1 = [], nums2 = [1]
//输出：1.00000
//示例 5：
//
//输入：nums1 = [2], nums2 = []
//输出：2.00000
//
//
//提示：
//
//nums1.length == m
//nums2.length == n
//0 <= m <= 1000
//0 <= n <= 1000
//1 <= m + n <= 2000
//-106 <= nums1[i], nums2[i] <= 106
//
//
//进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/*
 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         *
 */
double _04_normal_test_getKthMax(vector<int>& nums1, vector<int>& nums2,int k)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int idx1 = 0;
    int idx2 = 0;
    while (true) {
        if (idx1 >= n1) {
            return nums2[idx2 + k - 1];
        }
        if (idx2 >= n2) {
            return nums1[idx1 + k - 1];
        }
        if (k==1) {
            return min(nums1[idx1], nums2[idx2]);
        }
        int newidx1 = min(k/2 - 1 + idx1, n1-1);
        int newidx2 = min(k/2 - 1 + idx2, n2-1);
        int val1 = nums1[newidx1];
        int val2 = nums2[newidx2];
        if (val1 <= val2) {
            k-=newidx1 - idx1 + 1;
            idx1 = newidx1 + 1;
        }else{
            k-=newidx2 - idx2 + 1;
            idx2 = newidx2 + 1;
        }
    }
    return .0f;
}



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int n1 = nums1.size();
    int n2 = nums2.size();
    int totalcount = n1+n2;
    if (totalcount%2==0) {
        return (_04_normal_test_getKthMax(nums1, nums2,(totalcount+1)/2)
               +_04_normal_test_getKthMax(nums1, nums2,(totalcount+2)/2))/2;
    }else{
        return _04_normal_test_getKthMax(nums1, nums2,(totalcount+1)/2);
    }
}


double _04_normal_test_getKthMax3(vector<int>nums1,vector<int>nums2,int k){
    
    int n1 = nums1.size();
    int n2 = nums2.size();
    int l1 = 0;
    int l2 = 0;
    while (true) {
        if (l1 >= n1) {
            return nums2[l2+k-1];
        }
        if (l2 >= n2) {
            return nums1[l1+k-1];
        }
        if (k == 1) {
            return min(nums1[l1], nums2[l2]);
        }
        int newidx1 = min(n1 - 1, l1 + k/2 - 1);
        int newidx2 = min(n2 - 1, l2 + k/2 - 1);
        int val1 = nums1[newidx1];
        int val2 = nums2[newidx2];
        
        if (val1 <= val2) {
            k-=(newidx1-l1+1);
            l1 = newidx1 + 1;
        }else{
            k-=(newidx2-l2+1);
            l2 = newidx2 + 1;
        }
    }
    
    return .0f;
}

double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
    
    int total = nums1.size() + nums2.size();
    if (total % 2 == 0) {
        return (_04_normal_test_getKthMax3(nums1, nums2, (total+1)/2)+_04_normal_test_getKthMax3(nums1, nums2,(total+2)/2))/2;
    }else{
        return _04_normal_test_getKthMax3(nums1, nums2, (total+1)/2);
    }
}

void _04_normal_test()
{
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    double res1 = findMedianSortedArrays3(nums1, nums2);
    
}
