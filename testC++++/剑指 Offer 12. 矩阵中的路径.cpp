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

//------------------------------------------------------------------------------------

bool _offer_12_repeat_test_dfs_3(vector<vector<char>>& board,
                                 string word,string &path,
                                 int x,int y,int k){
    int n = board.size();
    int m = board[0].size();
    if (k == word.length()) {
        return true;
    }
    if (x < m && x >= 0 && y < n && y >= 0 && board[y][x] == word[k]) {
        path.push_back(board[y][x]);
        board[y][x] = ' ';
        bool res = _offer_12_repeat_test_dfs_3(board, word, path, x+1, y, k+1) ||
                   _offer_12_repeat_test_dfs_3(board, word, path, x-1, y, k+1) ||
                   _offer_12_repeat_test_dfs_3(board, word, path, x, y+1, k+1) ||
                   _offer_12_repeat_test_dfs_3(board, word, path, x, y-1, k+1);
        board[y][x] = word[k];
        path.pop_back();
        return res;
    }
    
    return false;
}

bool exist3(vector<vector<char>>& board, string word) {
    
    int n = board.size();
    if (n == 0) {
        return false;
    }
    int m = board[0].size();
    string path;
    for (int y = 0; y<n; y++) {
        for (int x = 0; x<m; x++) {
            if (_offer_12_repeat_test_dfs_3(board,word,path,x,y,0)) {
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
    bool res = exist3(list1,s1);
    
}
