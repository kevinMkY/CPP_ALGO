//
//  637_二叉树的层平均值.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/19.
//

#include "637_二叉树的层平均值.hpp"
#include "common.h"

//给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
//
//
//
//示例 1：
//
//输入：
//    3
//   / \
//  9  20
//    /  \
//   15   7
//输出：[3, 14.5, 11]
//解释：
//第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
//
//
//提示：
//
//节点值的范围在32位有符号整数范围内。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
vector<double> averageOfLevels1(TreeNode* root) {

    vector<double> res = {};
    if (root == nullptr) {
        return {};
    }
    auto val = root->val;
    res.push_back(val);
    
    auto left = root->left;
    auto right = root->right;
    auto leftave = averageOfLevels1(left);
    auto rightave = averageOfLevels1(right);
    auto leftsize= leftave.size();
    auto rightsize= rightave.size();
    auto maxsize = max(leftsize, rightsize);
    for (auto i = 0; i<maxsize; i++) {
        if (i<leftsize && i<rightsize) {
            auto leftval = leftave[i];
            auto rightval = rightave[i];
            auto aveval = (leftval + rightval) * 0.5;
            res.push_back(aveval);
        }else if (i<leftsize){
            auto leftval = leftave[i];
            auto aveval = leftval;
            res.push_back(aveval);
        }else if (i<rightsize){
            auto rightval = rightave[i];
            auto aveval = rightval;
            res.push_back(aveval);
        }
    }
    
    return res;
    }

//迭代
vector<double> averageOfLevels2(TreeNode* root) {

    vector<double> res = {};
    if (root == nullptr) {
        return res;
    }
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    int size = 1;
    
    while (!myqueue.empty()) {
        TreeNode *node = myqueue.front();
        myqueue.pop();
        
        size--;
        if (node->left) {
            myqueue.push(node->left);
        }
        if (node->right) {
            myqueue.push(node->right);
        }
        if (size == 0) {
            size = myqueue.size();
            
        }
    }
    return res;
    }

void _637_test()
{
    
    vector<int> list1 = {3,9,20,15,7};
    vector<int> list2 = {3,1,5,0,2,4,6};
    vector<int> list3 = {5,2,-3};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    TreeNode *node3 = initTreeWithNULLVector(list3);
    
//    vector<double> res1 = averageOfLevels1(node1);
//    vector<double> res2 = averageOfLevels1(node2);
    vector<double> res3 = averageOfLevels1(node3);
//    vector<double> res4 = averageOfLevels2(node2);
    
}
