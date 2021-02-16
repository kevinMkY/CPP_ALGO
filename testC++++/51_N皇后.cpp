//
//  51_N皇后.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/4.
//

#include "51_N皇后.hpp"
#include "common.h"

//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
//
//每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//
//
//示例 1：
//
//
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
//示例 2：
//
//输入：n = 1
//输出：[["Q"]]
//
//
//提示：
//
//1 <= n <= 9
//皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/n-queens
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<vector<string>> res;

void show(int maxNum,int places[]){
    vector<string> tempRes;
    for (int row = 0; row < maxNum; row ++ ) {
        string tempString ="";
        for (int col = 0; col < maxNum; col ++ ) {
            if (places[row] == col) {   //代表有
                tempString+="Q";
            }else{
                tempString+=".";
            }
        }
        tempRes.push_back(tempString);
        tempString="";
    }
    res.push_back(tempRes);

}

bool isValid(int row,int curCol,int places[]){
    for (int preRow = 0; preRow<row; preRow++) {
        int preCol = places[preRow];
        if (preCol == curCol) { //相同列
            return false;
        }
        int num1 = abs(curCol-preCol);
        int num2 = row - preRow;
        if (num2 == num1) {     //斜率
            return false;
        }
    }
    return true;
}

void placeQueen(int rowNum,int maxNum,int places[]){
    
    if (rowNum == maxNum) {
        //成功一种方案
        show(maxNum,places);
        return;
    }
    for (int col = 0; col<maxNum; col++) {
        if (isValid(rowNum, col,places)) {
            places[rowNum] = col;
            placeQueen(rowNum+1,maxNum,places);
        }else{
            
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    int places[n];
    placeQueen(0,n,places);
    return res;
    }

void _51_test()
{
    vector<vector<string>> res = solveNQueens(8);
    int size = res.size();
    
}
