//
//  剑指 Offer 54.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 54. 二叉搜索树的第k大节点.hpp"
#include "common.h"

void dfs(TreeNode *root,vector<int>&path)
{
    if (!root) {
        return;
    }
    dfs(root->left, path);
    path.push_back(root->val);
    dfs(root->right, path);
}

int _offer_54_repeat_testkthLargest(TreeNode* root, int k) {

    vector<int>path;
    dfs(root, path);
    int n = path.size();
    if (n>0) {
        return path[n-k];
    }
    return 0;
    }


int _offer_54_repeat_testkthLargest2(TreeNode* root, int k) {

    vector<int>path;
    
    if (!root) {
        return 0;
    }
    
    stack<TreeNode *>mystack;
    while (root || mystack.size()) {
        while (root) {
            mystack.push(root);
            root = root->left;
        }
        root = mystack.top();
        mystack.pop();
        path.push_back(root->val);
        root = root->right;
    }
    
    
    return path[path.size()-k];
    }

void _offer_54_repeat_test()
{
    vector<int> list3 = {3,1,4,NULL,2};
    vector<int> list4 = {1,2,2,3,4,4,3};
    vector<int> list5 = {2,3,3,4,5,5};
    
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node4 = initTreeWithNULLVector(list4);
    TreeNode *node5 = initTreeWithNULLVector(list5);
    int res1 = _offer_54_repeat_testkthLargest2(node3,1);
    
}
