//
//  剑指 Offer 32 - I.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 32 - I. 从上到下打印二叉树.hpp"
#include "common.h"

//
vector<int> _offer_32_repeat_testlevelOrder(TreeNode* root) {

    if (!root) {
        return {};
    }
    vector<int>res;
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        res.push_back(node->val);
        
        if (node->left) {
            myqueue.push(node->left);
        }
        if (node->right) {
            myqueue.push(node->right);
        }
        
    }
    return res;
    }

/*
 [
   [3],
   [9,20],
   [15,7]
 ]
 
 */

vector<vector<int>> _offer_32_repeat_testlevelOrder2(TreeNode* root) {

    vector<vector<int>>res;
    vector<int>levelres;
    if (!root) {
        return res;
    }
    
    queue<TreeNode *> myqueue;
    myqueue.push(root);
    int size = 1;
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        levelres.push_back(node->val);
        size--;
        if (node->left) {
            myqueue.push(node->left);
        }
        if (node->right) {
            myqueue.push(node->right);
        }
        if (size == 0) {
            res.push_back(levelres);
            levelres = {};
            size = myqueue.size();
        }
    }
    
    return res;
    }

vector<vector<int>> _offer_32_repeat_testlevelOrder3(TreeNode* root) {

    vector<vector<int>>res;
    vector<int>levelres;
    
    if (!root) {
        return res;
    }
    
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    int size = 1;
    int row = 1;
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        size--;
        levelres.push_back(node->val);
        if (node->left) {
            myqueue.push(node->left);
        }
        if (node->right) {
            myqueue.push(node->right);
        }
        if (size == 0) {
            if (row%2==0) {
                reverse(levelres.begin(), levelres.end());
            }
            res.push_back(levelres);
            levelres = {};
            size = myqueue.size();
            row++;
        }
    }
    
    return res;
}

void _offer_32_repeat_test()
{
    vector<int> list3 = {3,9,20,NULL,NULL,15,7};
    vector<int> list4 = {1,2,2,3,4,4,3};
    vector<int> list5 = {2,3,3,4,5,5};
    
    TreeNode *node3 = initTreeWithNULLVector(list3);
//    TreeNode *node4 = initTreeWithNULLVector(list4);
//    TreeNode *node5 = initTreeWithNULLVector(list5);
    
    
    vector<vector<int>>res = _offer_32_repeat_testlevelOrder3(node3);
    
}
