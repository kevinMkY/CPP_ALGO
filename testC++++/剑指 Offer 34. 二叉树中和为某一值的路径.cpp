//
//  剑指 Offer 34.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 34. 二叉树中和为某一值的路径.hpp"
#include "common.h"

vector<vector<int>>sumpath;
vector<int>path;

void dfs(TreeNode *root,int target){
    if (root) {
        int val = root->val;
        target-=val;
        path.push_back(val);
        if (target ==0 && !root->left && !root->right ) {
            sumpath.push_back(path);
        }else{
            dfs(root->left, target);
            dfs(root->right, target);
        }
        path.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    
    dfs(root, sum);
    return sumpath;
    }

void _offer_34_repeat_test()
{
    vector<int> list3 = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1};
    vector<int> list4 = {1,2,2,3,4,4,3};
    vector<int> list5 = {2,3,3,4,5,5};
    
    TreeNode *node3 = initTreeWithNULLVector(list3);
    vector<vector<int>>res = pathSum(node3,22);
    
}
