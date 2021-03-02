//
//  剑指 Offer 27.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 27. 二叉树的镜像.hpp"
#include "common.h"

//递归
TreeNode* _offer_27_repeat_testmirrorTree(TreeNode* root) {

    if (!root) {
        return root;
    }
    
    TreeNode *left = _offer_27_repeat_testmirrorTree(root->right);
    TreeNode *right = _offer_27_repeat_testmirrorTree(root->left);
    root->left =left;
    root->right = right;
    return root;
    }

//遍历
TreeNode* _offer_27_repeat_testmirrorTree2(TreeNode* root) {

    if (!root) {
        return root;
    }
    
    stack<TreeNode *>mystack;
    
    mystack.push(root);
    
    while (mystack.size()) {
        auto node = mystack.top();
        mystack.pop();
        auto left = node->left;
        auto right = node->right;
        node->left = right;
        node->right = left;
        if (left) {
            mystack.push(left);
        }
        if (right) {
            mystack.push(right);
        }
    }
 
    return root;
}


TreeNode* _offer_27_repeat_testmirrorTree3(TreeNode* root) {
    
    if (!root) {
        return root;
    }
    
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        swap(node->left, node->right);
        if (node->left) {
            myqueue.push(node->left);
        }
        if (node->right) {
            myqueue.push(node->right);
        }
    }
    
    return root;
}

void _offer_27_repeat_test()
{
    vector<int> list3 = {1,2,3,4};
    vector<int> list4 = {3};
    
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node4 = initTreeWithNULLVector(list4);
    TreeNode* res = _offer_27_repeat_testmirrorTree3(node3);
    
}
