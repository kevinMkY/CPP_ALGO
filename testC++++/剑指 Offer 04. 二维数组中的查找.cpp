//
//  剑指 Offer 04.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "剑指 Offer 04. 二维数组中的查找.hpp"
#include "common.h"

//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//
//
//
//示例:
//
//现有矩阵 matrix 如下：
//
//[
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
//给定 target = 5，返回 true。
//
//给定 target = 20，返回 false。
//
//
//
//限制：
//
//0 <= n <= 1000
//
//0 <= m <= 1000
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

    int row = (int)matrix.size() - 1;
    //先看哪一行
    for (int rowNum = row; rowNum >= 0 ; rowNum --) {
        vector<int> rowv = matrix[rowNum];
        for (int colNum = 0; colNum<rowv.size(); colNum ++) {
            int val = rowv[colNum];
            if (val == target) {
                return true;
            }else if (val > target){
                break;
            }
        }
    }
    
    
    return false;
    }

bool findNumberIn2DArray2(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    if (n == 0) {
        return false;
    }
    int m = matrix[0].size();
    
    int row = 0;
    int col = m-1;
    while (row < n && col >=0) {
        int val = matrix[row][col];
        if (val == target) {
            return true;
        }else if (val < target){
            row++;
        }else{
            col--;
            
        }
    }
    
    return false;
}


void _offer_04_repeat_test()
{
    vector<vector<int>> list1 = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int flag = 20;
    bool res =  findNumberIn2DArray2(list1,flag);
    
}
