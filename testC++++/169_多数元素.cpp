//
//  169_多数元素.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/19.
//

#include "169_多数元素.hpp"
#include "common.h"

//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
//
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
//
// 
//
//示例 1：
//
//输入：[3,2,3]
//输出：3
//示例 2：
//
//输入：[2,2,1,1,1,2,2]
//输出：2
// 
//
//进阶：
//
//尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/majority-element
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//系统排序
int majorityElement(vector<int>& nums) {
    int n = (int)nums.size();
    if (n==0) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    
    return nums[n/2];
    }

//投票算法
int majorityElement2(vector<int>& nums) {
    int n = (int)nums.size();
    if (n==0) {
        return 0;
    }
    
    int count = 0;
    int target = INT_MIN;
    for (int i = 0; i<n; i++) {
        int val = nums[i];
        if(target == val){
            count++;
        }else{
            if (count == 0) {
                target = val;
                count++;
            }else{
                count--;
            }
        }
    }
    
    return target;
    }


void _169_test()
{
    vector<int> list1 = {2,2,1,1,1,2,2};
    
    int res = majorityElement2(list1);
    
}
