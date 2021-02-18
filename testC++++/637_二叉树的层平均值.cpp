//
//  637_二叉树的层平均值.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/19.
//

#import "637_二叉树的层平均值.hpp"
#import "common.h"

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
vector<pair<double, unsigned long long>> sumLevel(TreeNode* root) {

    vector<pair<double, unsigned long long>> res = {};
    if (root == nullptr) {
        return {};
    }
    auto val = root->val;
    res.push_back({val,1});
    auto left = root->left;
    auto right = root->right;
    vector<pair<double, unsigned long long>> leftres = sumLevel(left);
    vector<pair<double, unsigned long long>> rightres = sumLevel(right);
    auto leftsize = leftres.size();
    auto rightsize = rightres.size();
    auto size = max(leftsize, rightsize);
    for (int i = 0; i<size; i++) {
        if (i<leftsize && i < rightsize) {
            auto leftval = leftres[i].first;
            auto leftcount = leftres[i].second;
            auto rightval = rightres[i].first;
            auto rightcount = rightres[i].second;
            res.push_back({leftval +rightval,leftcount+rightcount});
        }else if (i<leftsize) {
            auto leftval = leftres[i].first;
            auto leftcount = leftres[i].second;
            res.push_back({leftval,leftcount});
        }else if (i<rightsize) {
            auto rightval = rightres[i].first;
            auto rightcount = rightres[i].second;
            res.push_back({rightval,rightcount});
        }
    }
    return res;
    }

vector<double> averageOfLevels1(TreeNode* root) {

    vector<pair<double, unsigned long long>> res = sumLevel(root);
    vector<double> finallyres = {};
    int size = res.size();
    for (int i = 0; i<size; i++) {
        auto val = res[i].first;
        auto count = res[i].second;
        if (count > 0) {
            double rst = val/count;
            finallyres.push_back(rst);
        }else{
            finallyres.push_back(val);
        }
    }
    return finallyres;
    }

//迭代
vector<double> averageOfLevels2(TreeNode* root) {
    vector<double> res = {};
    if (root == nullptr) {
        return res;
    }
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    long long size = 1;
    long long lastsize = size;
    double sumtotal = 0;
    while (!myqueue.empty()) {
        auto node = myqueue.front();
        myqueue.pop();
        size--;
        sumtotal+=node->val;
        auto left = node->left;
        auto right = node->right;
        if (left) {
            myqueue.push(left);
        }
        if (right) {
            myqueue.push(right);
        }
        if (size == 0) {
            double rst = sumtotal/lastsize;
            res.push_back(rst);
            size = myqueue.size();
            lastsize = size;
            sumtotal = 0;
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
    
    vector<double> res1 = averageOfLevels1(node1);
    vector<double> res2 = averageOfLevels1(node2);
    vector<double> res3 = averageOfLevels1(node3);
    vector<double> res4 = averageOfLevels2(node1);
    vector<double> res5 = averageOfLevels2(node2);
    vector<double> res6 = averageOfLevels2(node3);
    
}
