//
//  283_移动零.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/19.
//

#include "283_移动零.hpp"
#include "common.h"

//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
//示例:
//
//输入: [0,1,0,3,12]
//输出: [1,3,12,0,0]
//说明:
//
//必须在原数组上操作，不能拷贝额外的数组。
//尽量减少操作次数。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/move-zeroes
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//双指针,一个指0,一个遍历非0,交换
void moveZeroes(vector<int>& nums) {
    int n = (int)nums.size();
    if (n < 2) {
        return;
    }
    int zeroIndex = INT_MIN;
    for (int i=0; i<n; i++) {
        if (nums[i] == 0) { //遇到0了
            if (zeroIndex < 0) {
                zeroIndex = i;
            }
        }else{              //遇到非0了
            if (zeroIndex >= 0) {   //前面有0
                nums[zeroIndex] = nums[i];
                nums[i] = 0;
                zeroIndex ++;
            }
        }
    }
}

void _283_test()
{
    //                  {4,0,4,0,4};
    vector<int> list1 = {4,0,0,4,4};
    moveZeroes(list1);
    
}
