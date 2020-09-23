//
//  662_二叉树最大宽度.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#include "662_二叉树最大宽度.hpp"
#include "common.h"

//给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。
//
//每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的NULL节点也计入长度）之间的长度。
//
//示例 1:
//
//输入:
//
//           1
//         /   \
//        3     2
//       / \     \
//      5   3     9
//
//输出: 4
//解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,NULL,9)。
//示例 2:
//
//输入:
//
//          1
//         /
//        3
//       / \
//      5   3
//
//输出: 2
//解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
//示例 3:
//
//输入:
//
//          1
//         / \
//        3   2
//       /
//      5
//
//输出: 2
//解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
//示例 4:
//
//输入:
//
//          1
//         / \
//        3   2
//       /     \
//      5       9
//     /         \
//    6           7
//输出: 8
//解释: 最大值出现在树的第 4 层，宽度为 8 (6,NULL,NULL,NULL,NULL,NULL,NULL,7)。
//注意: 答案在32位有符号整数的表示范围内。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/maximum-width-of-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int widthOfBinaryTree1(TreeNode* root) {
    unsigned long long w = 0;
    if (root == nullptr) {
        return w;
    }

    vector<unsigned long long> levelRes;
    queue<pair<TreeNode *,unsigned long long>> myqueue;
    myqueue.push({root,1});
    unsigned long long size = 1;
    while (!myqueue.empty()) {
        TreeNode *node = myqueue.front().first;
        unsigned long long pos = myqueue.front().second;
        levelRes.push_back(pos);
        myqueue.pop();
        size--;
        if (node->left) {
            myqueue.push({node->left,pos * 2});
        }
        if (node->right) {
            myqueue.push({node->right,pos * 2 + 1});
        }
        if (size == 0) {
            size = myqueue.size();
            unsigned long long curW = levelRes.back() - levelRes.front() + 1;
            w = max(w, curW);
            levelRes = {};
        }
    }
    
    return w;
    }

void _662_test(){
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,3,2,5,3,NULL,9};
//    vector<int> list3 = {0,0,0,NULL,0,0};   //这个地方0与NULL 分不开,与题目不符
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    
    int res1 = widthOfBinaryTree1(node1);
//    int res2 = widthOfBinaryTree1(node2);
    
//    int res3 = maxDepth2(node1);
//    int res4 = maxDepth2(node2);
    
}

