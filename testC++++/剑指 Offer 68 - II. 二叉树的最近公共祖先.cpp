//
//  236.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 68 - II. 二叉树的最近公共祖先.hpp"
#include "common.h"


TreeNode* _offer_68_02_repeat_testlowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr ) { // 如果树为空，直接返回null
        return root;
    }
    // 如果 p和q中有等于 root的，那么它们的最近公共祖先即为root（一个节点也可以是它自己的祖先）
    if (p == root || q == root) {
        
        return root;
    }

    // 递归遍历左子树，只要在左子树中找到了p或q，则先找到谁就返回谁
    TreeNode* l = _offer_68_02_repeat_testlowestCommonAncestor(root->left, p, q);
    // 递归遍历右子树，只要在右子树中找到了p或q，则先找到谁就返回谁
    TreeNode* r = _offer_68_02_repeat_testlowestCommonAncestor(root->right, p, q);
    
    //不在左边,就在右边
    if (!l) {
        return r;
    //不在右边,就在左边
    }else if (!r){
        return l;
    //左右同时有,那就返回root
    }else{
        return root;
    }
}

void _offer_68_02_repeat_test()
{
    vector<int> list3 = {3,5,1,6,2,0,8,NULL,NULL,7,4};
    vector<int> list4 = {1,2,2,3,4,4,3};
    vector<int> list5 = {2,3,3,4,5,5};
    
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node4 = node3->left;
    TreeNode *node5 = node3->right;
    TreeNode*  res1 = _offer_68_02_repeat_testlowestCommonAncestor(node3,node4,node5);
    
}
