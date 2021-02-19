//
//  66_加一.cpp
//  testC++++
//
//  Created by mm on 2021/2/19.
//

#include "66_加一.hpp"
#include "common.h"

//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//
//
//
//示例 1：
//
//输入：digits = [1,2,3]
//输出：[1,2,4]
//解释：输入数组表示数字 123。
//示例 2：
//
//输入：digits = [4,3,2,1]
//输出：[4,3,2,2]
//解释：输入数组表示数字 4321。
//示例 3：
//
//输入：digits = [0]
//输出：[1]
//
//
//提示：
//
//1 <= digits.length <= 100
//0 <= digits[i] <= 9
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/plus-one
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> plusOne(vector<int>& digits) {

    int n = (int)digits.size();
    if (n == 0) {
        return {};
    }
    
    bool needIncrebite = false;
    int tmp = 1;
    for (int i = n-1; i>=0; i--) {
        if (needIncrebite) {
            tmp++;
            needIncrebite = false;
        }
        needIncrebite = (digits[i] +tmp)/10;
        digits[i] = (digits[i]+tmp)%10;
        tmp = 0;
        if (!needIncrebite) {
            break;
        }
    }
    if (needIncrebite) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
    }

void _66_test()
{
    vector<int> list1 = {1,2,3};
    vector<int> list2 = {0};
    vector<int> list3 = {4,3,2,1};
    vector<int> list4 = {9,9};
    
    vector<int>res = plusOne(list1);
    vector<int>res2 = plusOne(list2);
    vector<int>res3 = plusOne(list3);
    vector<int>res4 = plusOne(list4);

}
