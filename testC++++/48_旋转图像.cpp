//
//  48_旋转图像.cpp
//  testC++++
//
//  Created by mm on 2021/2/20.
//

#include "48_旋转图像.hpp"
#include "common.h"

//上下 + 对角线
void rotate(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();
    if (n == 0) {
        return;
    }
    
    //先上下翻转
    for (int x = 0; x<(n/2); x++) {
        for (int y = 0; y<n; y++) {
            int tmp = matrix[x][y];
            matrix[x][y] = matrix[n-1-x][y];
            matrix[n-1-x][y] = tmp;
        }
    }
    //对角线反转
    for (int x = 0; x<n; x++) {
        for (int y = x; y<n; y++) {
            if (x==y) {
                continue;
            }
            int tmp = matrix[x][y];
            matrix[x][y] = matrix[y][x];
            matrix[y][x] = tmp;
        }
    }
}


//方法二：原地旋转

void _48_test()
{
    vector<vector<int>> list1 = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    rotate(list1);
    
}
