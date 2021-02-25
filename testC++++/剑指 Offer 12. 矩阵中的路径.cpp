//
//  剑指 Offer 12.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/25.
//

#include "剑指 Offer 12. 矩阵中的路径.hpp"
#include "common.h"

bool exist(vector<vector<char>>& board,string word, int i,int j ,int k) {

    int n = (int)board.size();
    vector<char> boardrow = board[0];
    if (i >= n || i<0 ||
        j>=boardrow.size() || j<0 ||
        board[i][j] != word[k])
    {
        return false;
    }
    
    if (k >= word.length() -1) {
        return true;
    }
    
    board[i][j] = '0';
    
    bool res =  exist(board,word, i-1, j, k+1) ||
                exist(board,word, i, j-1, k+1) ||
                exist(board,word, i+1, j, k+1) ||
                exist(board,word, i, j+1, k+1);
    
    board[i][j] = word[k];
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0 || word.length() == 0) {
        return false;
    }
    
    for (int i = 0; i<board.size(); i++) {
        vector<char> boardrow = board[i];
        for (int j = 0; j<boardrow.size(); j++) {
            if (exist(board,word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
    }

void _offer_12_repeat_test()
{
    vector<vector<char>> list1 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    
    string s1 = "ABCCED";
    bool res = exist(list1,s1);
    
}
