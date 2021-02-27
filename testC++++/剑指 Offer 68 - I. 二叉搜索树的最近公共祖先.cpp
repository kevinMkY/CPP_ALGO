//
//  剑指 Offer 68 - I.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/27.
//

#include "剑指 Offer 68 - I. 二叉搜索树的最近公共祖先.hpp"
#include "common.h"


TreeNode* _offer_68_repeat_testlowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if (!root) {
        return root;
    }
    //记录highval和lowval
    int highval = q->val,lowval = p->val;
    if (p->val > q->val) {
        lowval = q->val;
        highval = p->val;
    }
    
    //从root往下
    auto res = root;
    while (res) {
        int val = res->val;
        //如果当前low<= val <= high,说明找到了
        //val < low,说明2个都在root的右边
        //val > high,说明2个都在root的左边
        if (val >= lowval && val <= highval) {
            break;
        }if (val < lowval) {
            res = res->right;
        } else {
            res = res->left;
        }
    }
    
    return res;
    }

void _offer_68_repeat_test()
{
    vector<int> list3 = {6,2,8,0,4,7,9,NULL,NULL,3,5};
    vector<int> list4 = {1,2,2,3,4,4,3};
    vector<int> list5 = {2,3,3,4,5,5};
    
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node4 = new TreeNode(2);
    TreeNode *node5 = new TreeNode(8);
    TreeNode*  res1 = _offer_68_repeat_testlowestCommonAncestor(node3,node4,node5);
    
}
