//
//  faceTest_1616_部分排序.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/16.
//

#include "faceTest_1616_部分排序.hpp"
#include "common.h"

//给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。
//
//示例：
//
//输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
//输出： [3,9]
//提示：
//
//0 <= len(array) <= 1000000
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/sub-sort-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> subSort1(vector<int>& array) {

    if (array.size() == 0) {
        return {-1,-1};
    }
    int minIndex = -1;
    int maxNum = INT_MIN;
    //1,2,2,7,4,10
    for (int i = 0; i<array.size(); i++) {
        if (array[i] >= maxNum) {
            maxNum = array[i];
        }else{  //array[i] < maxNum)
            minIndex = i;
        }
    }
    
    int maxIndex = -1;
    int minNum = INT_MAX;
    //1,2,2,7,4,10
    for (int i = (int)array.size()-1; i>=0; i--) {
        if (array[i] <= minNum) {
            minNum = array[i];
        }else{  //array[i] > minNum)
            maxIndex = i;
        }
    }
    return {maxIndex,minIndex};
    }

vector<int> subSort2(vector<int>& array) {

    if (array.size() == 0) {
        return {-1,-1};
    }
    
    int maxNum = array[0];
    int rightIndex = -1;
    vector<int> res;
    //
    //  1,2,5,3,4,10
    for (int i = 1; i<array.size(); i++) {
        if (array[i] >= maxNum) {
            maxNum = array[i];
        }else{
            if (res.size() == 0) {
                res.push_back(i-1);
            }
            
            rightIndex = i;
        }
    }
    if (rightIndex == -1) {
        return {-1,-1};
    }else{
        res.push_back(rightIndex);
        return res;
    }
}

void _faceTest_1616_test()
{
    vector<int> list1 = {1,2,4,7,10,11,7,12,6,7,16,18,19};
//    vector<int> list1 = {    1,2,2,7,4,10};
    vector<int> res = subSort2(list1);
    
}
