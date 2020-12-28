//
//  1379_找出克隆二叉树中的相同节点.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/28.
//

#include "1379_找出克隆二叉树中的相同节点.hpp"
#include "common.h"

TreeNode* getTargetCopy1(TreeNode* original, TreeNode* cloned, TreeNode* target) {

    TreeNode*res = nullptr;
    if (!original || !cloned || !target) {
        return res;
    }
    auto val = cloned->val;
    if (val == target->val) {
        return cloned;
    }
    auto left = cloned->left;
    auto right = cloned->right;
    if (left) {
        auto lefttar = getTargetCopy1(original->left, cloned->left, target);
        if (lefttar) {
            return lefttar;
        }
    }
    if (right) {
        auto righttar = getTargetCopy1(original->right, cloned->right, target);
        if (righttar) {
            return righttar;
        }
    }
    return res;
    }

TreeNode* getTargetCopy2(TreeNode* original, TreeNode* cloned, TreeNode* target) {

    TreeNode*res = nullptr;
    if (!original || !cloned || !target) {
        return res;
    }
    queue<TreeNode *>myqueue;
    myqueue.push(cloned);
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        if (node->val == target->val) {
            return node;
        }
        if (node->left) {
            myqueue.push(node->left);
        }
        if (node->right) {
            myqueue.push(node->right);
        }
    }
    return res;
    }

void _1379_test()
{
    vector<int> list1 = {7,4,3,NULL,NULL,6,19};
    TreeNode* flag1 = new TreeNode(3);
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    TreeNode * res1 = getTargetCopy1(node1,node1,flag1);
    TreeNode * res2 = getTargetCopy2(node1,node1,flag1);
    
}
