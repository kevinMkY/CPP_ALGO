//
//  96_不同的二叉搜索树.cpp
//  testC++++
//
//  Created by yekaihua on 2021/1/5.
//

#include "96_不同的二叉搜索树.hpp"
#include "common.h"

//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
//
//示例:
//
//输入: 3
//输出: 5
//解释:
//给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/unique-binary-search-trees
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<TreeNode *>numtreesarea(int min,int max){
    vector<TreeNode *>res;
    if (min > max) {
        res.push_back(nullptr);
        return res;
    }
    
    return res;
}

vector<TreeNode *>getnumtreesFornum(int n){
    if (n == 0) {
        return {};
    }
    return numtreesarea(1,n);
}

int numTrees1(int n) {
    int res = getnumtreesFornum(n).size();
    return res;
    }

int numTrees2(int n) {
    int res;
    return res;
    }

void _96_test()
{
#warning todo 动态规划
    int flag1 = 3;
    
    
    int res1 = numTrees1(flag1);
    int res2 = numTrees2(flag1);
    
}
