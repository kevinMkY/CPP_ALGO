//
//  289_生命游戏.cpp
//  testC++++
//
//  Created by mm on 2021/2/19.
//

#include "289_生命游戏.hpp"
#include "common.h"

//根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
//
//给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
//
//如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
//下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。
//
//
//
//示例 1：
//
//
//输入：board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
//输出：[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
//示例 2：
//
//
//输入：board = [[1,1],[1,0]]
//输出：[[1,1],[1,1]]
//
//
//提示：
//
//m == board.length
//n == board[i].length
//1 <= m, n <= 25
//board[i][j] 为 0 或 1
//
//
//进阶：
//
//你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
//本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/game-of-life
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

bool willdead(vector<vector<int>>& board,int y,int x) {
    int n = (int)board.size();
    int subn = (int)board[0].size();
    
    int count = 0;
    int val = 0;
    if (x>0 && y > 0) {
        val = board[x-1][y-1];;
        count+= val;
    }
    if (y>0) {
        val = board[x][y-1];
        count+= val;
        if (x+1<n) {
            val = board[x+1][y-1];
            count+= val;
        }
    }
    if (x>0) {
        val = board[x-1][y];
        count+= val;
        if (y+1<subn) {
            val = board[x-1][y+1];
            count+= val;
        }
        
    }
    if (y+1<subn) {
        val = board[x][y+1];
        count+= val;
    }
    if (x+1<n) {
        val = board[x+1][y];
        count+= val;
    }
    if (y+1<subn && x+1<n) {
        val = board[x+1][y+1];
        count+= val;
    }
    if (board[x][y] == 1) { //live
        return count == 2 || count == 3;
    }else{
        return count == 3;
    }
}

void gameOfLife(vector<vector<int>>& board) {
    int h = (int)board.size();
    if (h == 0) {
        return;
    }
    int w = (int)board[0].size();
    vector<vector<int>>dp(h,vector<int>(w));
    
    for (int x = 0 ; x<w; x++) {
        for (int y = 0; y<h; y++) {
            bool celldead = willdead(board, x,y);
            dp[y][x] = celldead;
        }
    }
    
    swap(board, dp);
    
    }

//用数组来标记每次运算的8个方向
bool willdead2(vector<vector<int>>& board,int y,int x) {
    int n = (int)board.size();
    int subn = (int)board[0].size();
    int count = 0;
    vector<int> dy = {-1,0,1,-1,1,-1,0,1};
    vector<int> dx = {-1,-1,-1,0,0,1,1,1};
    
    for (int i = 0; i<8; i++) {
        int lastY = y+dy[i];
        int lastX = x+dx[i];
        if (lastX >= 0 && lastX <n && lastY >=0 && lastY < subn) {
            count+=(board[lastX][lastY]&1);
        }
    }
    
    if ((board[x][y]&1) == 1) { //live
        return count == 2 || count == 3;
    }else{
        return count == 3;
    }
}

//位运算
void gameOfLife2(vector<vector<int>>& board) {
    int h = (int)board.size();
    if (h == 0) {
        return;
    }
    int w = (int)board[0].size();
    
    for (int x = 0 ; x<w; x++) {
        for (int y = 0; y<h; y++) {
            bool celldead = willdead2(board, x,y);
            if (celldead) { //live
                board[y][x] = board[y][x] | 2;
            }
        }
    }
    
    for (int x = 0 ; x<w; x++) {
        for (int y = 0; y<h; y++) {
            board[y][x] >>= 1;
        }
    }
    
    printf("");
}


//给原来的01增加状态2，3
//比如原来活现在死，计为2
//比如原来死现在活，计为3


void _289_test()
{
    vector<vector<int>> list1 = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
//        {1,1},
//        {1,0}
    };
    gameOfLife2(list1);
    


}
