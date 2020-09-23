//
//  102_二叉树的层序遍历.cpp
//  testC++++
//
//  Created by ykh on 2020/9/22.
//

#include "102_二叉树的层序遍历.hpp"
#include "common.h"

//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
//
//
//
//示例：
//二叉树：[3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回其层次遍历结果：
//
//[
//  [3],
//  [9,20],
//  [15,7]
//]
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//迭代
vector<vector<int>> levelOrder1(TreeNode* root) {

    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }
    
    queue<TreeNode *> myqueue;
    myqueue.push(root);
    int size = 1;
    vector<int> levelRes;
    while (!myqueue.empty()) {
        TreeNode *tmp = myqueue.front();
        myqueue.pop();
        size--;
        levelRes.push_back(tmp->val);
        if (tmp->left) {
            myqueue.push(tmp->left);
        }
        if (tmp->right) {
            myqueue.push(tmp->right);
        }
        if (size == 0) {
            size = myqueue.size();
            res.push_back(levelRes);
            levelRes = {};
        }
    }
    
    return res;
    }

void _102_test(){
    
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {3,9,20,NULL,NULL,15,7};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
//    TreeNode *node1 = initTreeWithVector(list1);
    
    vector<vector<int>> res1 = levelOrder1(node1);
    vector<vector<int>> res2 = levelOrder1(node2);
    
}
