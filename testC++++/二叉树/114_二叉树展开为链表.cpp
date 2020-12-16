//
//  114_二叉树展开为链表.cpp
//  testC++++
//
//  Created by ykh on 2020/9/23.
//

#include "114_二叉树展开为链表.hpp"
#include "common.h"

//给定一个二叉树，原地将它展开为一个单链表。
//
//
//
//例如，给定二叉树
//
//    1
//   / \
//  2   5
// / \   \
//3   4   6
//将其展开为：
//
//1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6
//通过次数83,636提交次数117,577
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归--注意要将right拼在left的最后面
void flatten1(TreeNode* root) {
    if (!root) {
        return;
    }
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    flatten1(left);
    flatten1(right);
    root->left = nullptr;
    root->right = left;
    if (left) {
        while (left) {
            if (left->right) {
                left = left->right;
            }else{
                left->right = right;
                left = nullptr;
            }
        }
    }else{
        root->right = right;
    }
}

//迭代
void flatten2(TreeNode* root) {
    if (!root) {
        return;
    }
    stack<TreeNode *>mystack;
    mystack.push(root);
    TreeNode *last = nullptr;
    while (!mystack.empty()) {
        TreeNode *node = mystack.top();
        if (last) {
            last->left = nullptr;
            last->right = node;
        }
        //
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        mystack.pop();
        if (right) {
            mystack.push(right);
        }
        if (left) {
            mystack.push(left);
        }
        
        last = node;
    }
}
void _114_test(){
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,2,5,3,4,NULL,6};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    TreeNode *node3 = initTreeWithNULLVector(list2);
    
//    flatten1(node2);
    flatten2(node3);
    
}

