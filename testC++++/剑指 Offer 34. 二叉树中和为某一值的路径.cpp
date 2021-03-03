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

void dfs_pathSum3(TreeNode* root, int sum,
                  vector<vector<int>> &res,
                  vector<int>&path){
    if (!root) {
        return;
    }
    
    path.push_back(root->val);
    int target = sum - root->val;
    if (target == 0 && !root->left && !root->right) {
        res.push_back(path);
    }else{
        dfs_pathSum3(root->left, target, res, path);
        dfs_pathSum3(root->right, target, res, path);
    }
    path.pop_back();
}

vector<vector<int>> pathSum3(TreeNode* root, int sum) {
    
    vector<vector<int>> res;
    vector<int>path;
    dfs_pathSum3(root, sum,res,path);
    return res;
}

void _offer_34_repeat_test()
{
    vector<int> list3 = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1};
    vector<int> list4 = {1,2,2,3,4,4,3};
    vector<int> list5 = {2,3,3,4,5,5};
    vector<int> list6 = {1,2};
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node6 = initTreeWithNULLVector(list6);
    vector<vector<int>>res1 = pathSum3(node3,22);
    vector<vector<int>>res2 = pathSum3(node6,11);
    
}
