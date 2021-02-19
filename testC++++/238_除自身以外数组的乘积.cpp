//
//  238_除自身以外数组的乘积.cpp
//  testC++++
//
//  Created by mm on 2021/2/20.
//

#include "238_除自身以外数组的乘积.hpp"
#include "common.h"


//给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//
//
//
//示例:
//
//输入: [1,2,3,4]
//输出: [24,12,8,6]
//
//
//提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
//
//说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//
//进阶：
//你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/product-of-array-except-self
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//left【i】，记录i左边的数的乘积
//right【i】，记录i右边的数的乘积
//left【i】 * right【i】 = 结果
vector<int> productExceptSelf(vector<int>& nums) {
    int n = (int)nums.size();
    if (n == 0) {
        return {};
    }
    
    vector<int>left(n);
    left[0]=1;
    for (int i = 1; i<n; i++) {
        left[i] = left[i-1]*nums[i-1];
    }
    vector<int>right(n);
    
    
    vector<int>res(n);
    for (int i = n-1; i>=0; i--) {
        if (i==n-1) {
            right[i]=1;
        }else{
            right[i]=right[i+1] * nums[i+1];
        }
        res[i] = left[i] * right[i];
    }
    return res;
   }

//相比上面，left直接输出
//right省略，用临时变量代替
vector<int> productExceptSelf2(vector<int>& nums) {
    int n = (int)nums.size();
    if (n == 0) {
        return {};
    }
    
    vector<int>left(n);
    left[0]=1;
    for (int i = 1; i<n; i++) {
        left[i] = left[i-1]*nums[i-1];
    }
    int tmp = 1;
    int last = tmp;
    for (int i = n-1; i>=0; i--) {
        if (i==n-1) {
            tmp=1;
        }else{
            tmp=last * nums[i+1];
        }
        last = tmp;
        left[i] = left[i] * tmp;
    }
    return left;
   }

void _238_test()
{



    vector<int> list1 = {1,2,3,4};
    vector<int> res= productExceptSelf(list1);
    vector<int> res2= productExceptSelf2(list1);
    


}
