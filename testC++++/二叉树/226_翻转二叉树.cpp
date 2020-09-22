//
//  226_翻转二叉树.cpp
//  testC++++
//
//  Created by ykh on 2020/9/22.
//

#include "226_翻转二叉树.hpp"
#include "common.h"

//翻转一棵二叉树。
//
//示例：
//
//输入：
//
//     4
//   /   \
//  2     7
// / \   / \
//1   3 6   9
//输出：
//
//     4
//   /   \
//  7     2
// / \   / \
//9   6 3   1
//备注:
//这个问题是受到 Max Howell 的 原问题 启发的 ：
//
//谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/invert-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//前序
TreeNode* invertTree1(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    TreeNode *tmpNode = root->left;
    root->left = root->right;
    root->right = tmpNode;
    
    invertTree1(root->left);
    invertTree1(root->right);
    return root;
    }

//中序
TreeNode* invertTree2(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    invertTree2(root->left);
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree2(root->left);
    
    return root;
    }

//后序
TreeNode* invertTree3(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    invertTree3(root->left);
    invertTree3(root->right);
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
    return root;
    }

//层序
TreeNode* invertTree4(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    queue<TreeNode *> myqueue;
    
    myqueue.push(root);
    
    while (myqueue.size() > 0) {
        TreeNode *node = myqueue.front();
        myqueue.pop();
        
        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        
        if (node->left != nullptr) {
            myqueue.push(node->left);
        }
        
        if (node->right != nullptr) {
            myqueue.push(node->right);
        }
    }
    
    return root;
    }

void _226_test(){
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithVector(list1);
    TreeNode *node3 = initTreeWithVector(list1);
    TreeNode *node4 = initTreeWithVector(list1);
    TreeNode* res1 = invertTree1(node1);
    TreeNode* res2 = invertTree2(node2);
    TreeNode* res3 = invertTree3(node3);
    TreeNode* res4 = invertTree4(node4);

}
