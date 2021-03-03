//
//  剑指 Offer 28.cpp
//  testC++++
//
//  Created by yekaihua on 2021/2/26.
//

#include "剑指 Offer 28. 对称的二叉树.hpp"
#include "common.h"

bool _offer_28_repeat_testisSameTree(TreeNode* root1,TreeNode* root2) {
    
    if (!root1 && !root2) {
        return true;
    }else if (!root1 || !root2){
        return false;
    }else if(root1->val != root2->val){
        return false;
    }
    bool res1 = _offer_28_repeat_testisSameTree(root1->left,root2->right);
    bool res2 = _offer_28_repeat_testisSameTree(root1->right,root2->left);
    return res1 && res2;
}

bool _offer_28_repeat_testisSymmetric(TreeNode* root) {

    
    
    return _offer_28_repeat_testisSameTree(root,root);
    }

bool _offer_28_repeat_testisSymmetric2(TreeNode* root) {

    
    if (!root) {
        return true;
    }
    
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    myqueue.push(root);
    
    while (myqueue.size()) {
        auto node1 = myqueue.front();
        myqueue.pop();
        auto node2 = myqueue.front();
        myqueue.pop();
        
        if (!node1 && !node2) {
            continue;
        }else if (!node1 || !node2){
            return false;
        }else{
            if (node1->val != node2->val) {
                return false;
            }
            myqueue.push(node1->left);
            myqueue.push(node2->right);
            myqueue.push(node1->right);
            myqueue.push(node2->left);
        }
    }
    
    return true;
    }

bool _offer_28_repeat_testisSymmetric3(TreeNode* root) {
    
    if (!root) {
        return true;
    }
 
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    myqueue.push(root);
    while (myqueue.size()) {
        auto node1 = myqueue.front();
        myqueue.pop();
        auto node2 = myqueue.front();
        myqueue.pop();
        if (node1->val != node2->val) {
            return false;
        }
        if (node1->left && node2->right) {
            myqueue.push(node1->left);
            myqueue.push(node2->right);
        }else if (!node1->left && !node2->right){
            
        }else{
            return false;
        }
        if (node2->left && node1->right) {
            myqueue.push(node2->left);
            myqueue.push(node1->right);
        }else if (!node2->left && !node1->right){
            
        }else{
            return false;
        }
    }
    
    return true;
}

void _offer_28_repeat_test()
{
    vector<int> list3 = {1,2,3,4};
    vector<int> list4 = {1,2,2,3,4,4,3};
    vector<int> list5 = {2,3,3,4,5,5};
    
    TreeNode *node3 = initTreeWithNULLVector(list3);
    TreeNode *node4 = initTreeWithNULLVector(list4);
    TreeNode *node5 = initTreeWithNULLVector(list5);
    bool res1 = _offer_28_repeat_testisSymmetric3(node3);
    bool res2 = _offer_28_repeat_testisSymmetric3(node4);
    bool res3 = _offer_28_repeat_testisSymmetric3(node5);
    
}
