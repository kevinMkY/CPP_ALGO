//
//  剑指 Offer 26.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 26. 树的子结构.hpp"
#include "common.h"

//从相同根节点出发,
bool _offer_26_repeat_testisSame(TreeNode* A, TreeNode* B) {
    if (!B) {
        return true;
    }
    if (!A || A->val != B->val) {
        return false;
    }
    bool res1 = _offer_26_repeat_testisSame(A->left,B->left);
    bool res2 = _offer_26_repeat_testisSame(A->right,B->right);
    return res1 && res2;
}

bool _offer_26_repeat_testisSubStructure(TreeNode* A, TreeNode* B) {
    if (!A || !B) {return false;}
    
    bool res1 = _offer_26_repeat_testisSame(A, B);
    bool res2 = _offer_26_repeat_testisSubStructure(A->left, B);
    bool res3 = _offer_26_repeat_testisSubStructure(A->right, B);
    
    return res1 || res2 || res3;
    }

void _offer_26_repeat_test()
{
    vector<int> list3 = {1,2,3,4};
    vector<int> list4 = {3};
    
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node4 = initTreeWithNULLVector(list4);
    
    bool res = _offer_26_repeat_testisSubStructure(node3,node4);
    
}
