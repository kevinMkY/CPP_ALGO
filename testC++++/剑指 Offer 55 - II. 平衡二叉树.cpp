//
//  剑指 Offer 55 - II.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 55 - II. 平衡二叉树.hpp"
#include "common.h"

int _offer_55_02_repeat_testdfs(TreeNode *root){
    
    if (!root) {
        return 0;
    }
    
    int left = _offer_55_02_repeat_testdfs(root->left);
    if (left == -1) {
        return -1;
    }
    int right = _offer_55_02_repeat_testdfs(root->right);
    if (right == -1) {
        return -1;
    }
    int res = max(left, right) + 1;
    return abs(left - right) < 2 ? res : -1;
}

bool _offer_55_02_repeat_testisBalanced(TreeNode* root) {

    if (!root) {
        return true;
    }
    
    return _offer_55_02_repeat_testdfs(root) != -1;
    }

void _offer_55_02_repeat_test()
{
    vector<int> list3 = {3,9,20,NULL,NULL,15,7};
    vector<int> list4 = {1,2,2,3,3,NULL,NULL,4,4};
    vector<int> list5 = {1,2,2,3,NULL,NULL,3,4,NULL,NULL,4};
    
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node4 = initTreeWithNULLVector(list4);
    TreeNode *node5 = initTreeWithNULLVector(list5);
    bool res1 = _offer_55_02_repeat_testisBalanced(node5);
    
}
