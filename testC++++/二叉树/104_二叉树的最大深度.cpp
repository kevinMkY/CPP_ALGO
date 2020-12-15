//
//  104_二叉树的最大深度.cpp
//  testC++++
//
//  Created by ykh on 2020/9/22.
//

#include "104_二叉树的最大深度.hpp"
#include "common.h"

//给定一个二叉树，找出其最大深度。
//
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例：
//给定二叉树 [3,9,20,null,null,15,7]，
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回它的最大深度 3 。
//
//通过次数279,151提交次数371,924
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
int maxDepth1(TreeNode* root) {
    
    int h = 0;
    if (root == nullptr) {
        return h;
    }
    
    int leftH = maxDepth1(root->left);
    int rightH = maxDepth1(root->right);
    int finalyH = max(leftH, rightH);
    return finalyH + 1;
    }

//迭代 -- 用层序遍历较好
int maxDepth2(TreeNode* root) {
    
    int h = 0;
    if (root == nullptr) {
        return h;
    }
    
    queue<TreeNode *> myqueue;
    myqueue.push(root);
    h = 1;
    int size = myqueue.size();
    
    while (!myqueue.empty()) {
        TreeNode *node = myqueue.front();
        myqueue.pop();
        size--;
        if (node->left != nullptr) {
            myqueue.push(node->left);
        }
        if (node->right != nullptr) {
            myqueue.push(node->right);
        }
        if (size == 0) {    //代表本层遍历完毕
            size = myqueue.size();
            if (size != 0) {
                h++;
            }
        }
    }
    
    return h;
    }

void _104_test(){
    
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {3,9,20,NULL,NULL,15,7};    
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
//    TreeNode *node1 = initTreeWithVector(list1);
    
    int res1 = maxDepth1(node1);
    int res2 = maxDepth1(node2);
    
    int res3 = maxDepth2(node1);
    int res4 = maxDepth2(node2);
    
}

