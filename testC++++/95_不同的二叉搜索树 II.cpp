//
//  95_不同的二叉搜索树 II.cpp
//  testC++++
//
//  Created by yekaihua on 2021/1/6.
//

#include "95_不同的二叉搜索树 II.hpp"
#include "common.h"

//给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
//
//
//
//示例：
//
//输入：3
//输出：
//[
//  [1,null,3,2],
//  [3,2,null,1],
//  [3,1,null,null,2],
//  [2,1,3],
//  [1,null,2,null,3]
//]
//解释：
//以上的输出对应以下 5 种不同结构的二叉搜索树：
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//
//
//提示：
//
//0 <= n <= 8
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//构建根节点分别为min---->max的树
vector<TreeNode*> generateTrees1Area(int start,int end) {
    vector<TreeNode*>res;
    if (start > end) {
        res.push_back(nullptr);
        return res;
    }
    
    for (int i = start; i<=end; i++) {
        auto leftres =  generateTrees1Area(start, i-1);
        auto rightres = generateTrees1Area(i+1, end);
        for (auto leftnode : leftres) {
            for (auto rightnode : rightres) {
                auto node = new TreeNode(i);
                node->left = leftnode;
                node->right = rightnode;
                res.push_back(node);
            }
        }
    }
    return res;
}

//递归
vector<TreeNode*> generateTrees1(int n) {
    vector<TreeNode*>res = {};
    if (n <= 0) {
        return res;
    }
    return generateTrees1Area(1, n);
    }

//动态规划
vector<TreeNode*> generateTrees2(int n) {
    vector<TreeNode*>res;
    return res;
    }


void _95_test()
{
#warning todo 动态规划
    int flag1 = 3;
    
    vector<TreeNode*> res1 = generateTrees1(flag1);
    vector<TreeNode*> res2 = generateTrees1(flag1);
    
}
