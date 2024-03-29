//
//  剑指 Offer 29.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 29. 顺时针打印矩阵.hpp"
#include "common.h"

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    int n = (int)matrix.size();
    if (n == 0) {
        return {};
    }
    int m = (int)matrix[0].size();
    int totalC = n * m;
    
    int l = 0;
    int r = m-1;
    int t = 0;
    int b = n-1;
    
    vector<int>res;
    while (res.size() < totalC) {
        //top横排
        for (int i = l; i<=r; i++) {
            res.push_back(matrix[t][i]);
        }
        t++;
        if (res.size() >= totalC) {
            break;
        }
        //right竖排
        for (int i = t; i<=b; i++) {
            res.push_back(matrix[i][r]);
        }
        r--;
        if (res.size() >= totalC) {
            break;
        }
        //bottom横排
        for (int i = r; i>=l; i--) {
            res.push_back(matrix[b][i]);
        }
        b--;
        if (res.size() >= totalC) {
            break;
        }
        //left竖排
        for (int i = b; i>=t; i--) {
            res.push_back(matrix[i][l]);
        }
        l++;
    }
    
    return res;
    }

vector<int> spiralOrder2(vector<vector<int>>& matrix) {
    
    int rows = matrix.size();
    if (rows == 0) {
        return {};
    }
    int cols = matrix[0].size();
    int l = 0;
    int r = cols-1;
    int t = 0;
    int b = rows-1;
    int total= rows * cols;
    vector<int>res;
    
    while (res.size() < total) {
        for (int x = l; x<=r; x++) {
            res.push_back(matrix[t][x]);
        }
        t++;
        if (res.size() == total) {
            return res;
        }
        for (int y = t; y<=b; y++) {
            res.push_back(matrix[y][r]);
        }
        r--;
        if (res.size() == total) {
            return res;
        }
        for (int x = r; x>=l; x--) {
            res.push_back(matrix[b][x]);
        }
        b--;
        if (res.size() == total) {
            return res;
        }
        for (int y = b; y>=t; y--) {
            res.push_back(matrix[y][l]);
        }
        l++;
    }
    
    
    return res;
}

void _offer_29_repeat_test()
{
    vector<vector<int>> list1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    vector<vector<int>> list2 = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };
    
    vector<vector<int>> list3 = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    
//    vector<int> res  = spiralOrder2(list1);
    vector<int> res2 = spiralOrder2(list3);
    
    
}
