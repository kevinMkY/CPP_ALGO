//
//  107_二叉树的层次遍历 II.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#include "107_二叉树的层次遍历 II.hpp"
#include "common.h"

//给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//
//例如：
//给定二叉树 [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回其自底向上的层次遍历为：
//
//[
//  [15,7],
//  [9,20],
//  [3]
//]
//通过次数100,911提交次数149,327
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<vector<int>> levelOrderBottom1(TreeNode* root) {
    vector<vector<int>> res;
    
    return res;
    }


void _107_test(){
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {3,9,20,NULL,NULL,15,7};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
//    TreeNode *node1 = initTreeWithVector(list1);
    
//    vector<vector<int>>  res1 = levelOrderBottom1(node1);
    vector<vector<int>>  res2 = levelOrderBottom1(node2);
    
    
}
