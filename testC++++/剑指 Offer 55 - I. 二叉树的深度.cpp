//
//  剑指 Offer 55 - I.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 55 - I. 二叉树的深度.hpp"
#include "common.h"


int _offer_55_repeat_testmaxDepthdfs(TreeNode *root){
    
    int res = 0;
    if (!root) {
        return res;
    }
    
    int left = _offer_55_repeat_testmaxDepthdfs(root->left);
    int right = _offer_55_repeat_testmaxDepthdfs(root->right);
    res = max(left, right) + 1;
    
    return res;
}

int _offer_55_repeat_testmaxDepth(TreeNode* root) {

    return _offer_55_repeat_testmaxDepthdfs(root);
    }


int _offer_55_repeat_testmaxDepth2(TreeNode* root) {

    if (!root) {
        return 0;
    }
    
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    int size = 1;
    int depth = 0;
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        size --;
        if (node->left) {
            myqueue.push(node->left);
        }
        if (node->right) {
            myqueue.push(node->right);
        }
        if (size == 0) {
            size = myqueue.size();
            depth++;
        }
    }
    
    
    return depth;
    }

void _offer_55_repeat_test()
{
    vector<int> list3 = {3,1,4,NULL,2};
    vector<int> list4 = {1,2,2,3,4,4,3};
    vector<int> list5 = {2,3,3,4,5,5};
    
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node4 = initTreeWithNULLVector(list4);
    TreeNode *node5 = initTreeWithNULLVector(list5);
    int res1 = _offer_55_repeat_testmaxDepth2(node3);
    
}
