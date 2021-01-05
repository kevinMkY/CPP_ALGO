//
//  513_找树左下角的值.cpp
//  testC++++
//
//  Created by yekaihua on 2021/1/4.
//

#include "513_找树左下角的值.hpp"
#include "common.h"

//给定一个二叉树，在树的最后一行找到最左边的值。
//
//示例 1:
//
//输入:
//
//    2
//   / \
//  1   3
//
//输出:
//1
//
//
//示例 2:
//
//输入:
//
//        1
//       / \
//      2   3
//     /   / \
//    4   5   6
//       /
//      7
//
//输出:
//7
//
//
//注意: 您可以假设树（即给定的根节点）不为 NULL。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/find-bottom-left-tree-value
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

TreeNode* depestNode;
int maxDepth;

void findBottomLeaf(TreeNode *root,int &depth){
    if (!root) {
        return;
    }
    auto left = root->left;
    auto right = root->right;
    int tempdepth = depth + 1;
    auto node = root;
    
    if (!left && !right) {
        
    }else{
        int leftdepth = tempdepth;
        int rightdepth = tempdepth;
        findBottomLeaf(left, leftdepth);
        findBottomLeaf(right, rightdepth);
        
    }
    if (tempdepth > maxDepth) {
        depestNode = node;
    }
    maxDepth = max(maxDepth, tempdepth);
    
}

//递归
int findBottomLeftValue1(TreeNode* root) {

    int res = 0;
    if (!root) {
        return res;
    }
    int depth = 1;
    maxDepth = depth;
    depestNode = root;
    findBottomLeaf(root, depth);
    res = depestNode->val;
    return res;
    }

//迭代
int findBottomLeftValue2(TreeNode* root) {

    int res = 0;
    if (!root) {
        return res;
    }
    
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    vector<TreeNode *>row;
    int size = 1;
    TreeNode *last = root;
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        row.push_back(node);
        size--;
        if (node->left) {
            myqueue.push(node->left);
        }
        if (node->right) {
            myqueue.push(node->right);
        }
        if (size == 0) {
            size = myqueue.size();
            last = row.front();
            row = {};
        }
    }
    
    return last->val;
    }



void _513_test()
{
    vector<int> list1 = {2,1,3};
    vector<int> list2 = {1,2,3,4,NULL,5,6,NULL,NULL,7};
    vector<int> list3 = {25,-22,60,NULL,NULL,36};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    TreeNode *node3 = initTreeWithNULLVector(list3);
    
    int res1 = findBottomLeftValue1(node1);
    int res2 = findBottomLeftValue1(node2);
    int res3 = findBottomLeftValue1(node3);
    
}
