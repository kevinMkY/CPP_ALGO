//
//  230_二叉搜索树中第K小的元素.cpp
//  testC++++
//
//  Created by yekaihua on 2021/1/4.
//

#include "230_二叉搜索树中第K小的元素.hpp"
#include "common.h"

//给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
//
//说明：
//你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
//
//示例 1:
//
//输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 1
//示例 2:
//
//输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 3
//进阶：
//如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> kthSmallest1inorder(TreeNode *root){
    vector<int>res;
    if (!root) {
        return res;
    }
    stack<TreeNode *>mystack;
    while (root || mystack.size()) {
        while (root) {
            mystack.push(root);
            root = root->left;
        }
        root = mystack.top();
        mystack.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

int kthSmallest1(TreeNode* root, int k) {
        
    int res = 0;
    if (!root) {
        return res;
    }
    vector<int> v1 = kthSmallest1inorder(root);
    if (v1.size() && k-1<v1.size()) {
        res = v1[k-1];
    }
    return res;
    }

int kthSmallest2(TreeNode* root, int k) {
        
    int res = 0;
    if (!root || k == 0) {
        return res;
    }
    
    stack<TreeNode *>mystack;
    while (root || mystack.size()) {
        while (root) {
            mystack.push(root);
            root = root->left;
        }
        root= mystack.top();
        k--;
        if (k == 0) {
            return root->val;
        }
        mystack.pop();
        root = root->right;
        
    }
    
    return res;
    }

void _230_test()
{
    vector<int> list1 = {3,1,4,NULL,2};
    int flag1 = 1;
    vector<int> list2 = {5,3,6,2,4,NULL,NULL,1};
    int flag2 = 3;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    
    int res1 = kthSmallest1(node1,flag1);
    int res2 = kthSmallest2(node2,flag2);
    
}
