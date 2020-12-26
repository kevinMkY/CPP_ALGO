//
//  404_左叶子之和.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/24.
//

#include "404_左叶子之和.hpp"
#include "common.h"

//计算给定二叉树的所有左叶子之和。
//
//示例：
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
//
//
//通过次数64,804提交次数115,070
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/sum-of-left-leaves
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int sumleftleaf(TreeNode *root,bool isleft){
    int res = 0;
    if (!root) {
        return res;
    }
    auto val = root->val;
    auto left = root->left;
    auto right = root->right;
    int leftres = sumleftleaf(left,true);
    int rightres = sumleftleaf(right,false);
    if (!left && !right && isleft) {
        res+=val;
    }
    res+=(leftres+rightres);
    return res;
}

//递归
int sumOfLeftLeaves1(TreeNode* root) {
    int res = sumleftleaf(root, false);
    return res;
    }

//迭代
int sumOfLeftLeaves2(TreeNode* root) {

    int res = 0;
    if (!root || (!root->left && !root->right)) {
        return res;
    }
    
    queue<pair<TreeNode *, unsigned long long>>myqueue;
    myqueue.push({root,1});
    while (!myqueue.empty()) {
        auto node = myqueue.front().first;
        auto pos = myqueue.front().second;
        myqueue.pop();
        auto left = node->left;
        auto right = node->right;
        if (left) {
            myqueue.push({left,pos*2-1});
        }
        if (right) {
            myqueue.push({right,pos*2});
        }
        if (pos%2==1 && !left && !right) {
            res+=node->val;
        }
    }
    
    return res;
    }

void _404_test()
{
    vector<int> list1 = {3,9,20,NULL,NULL,15,7};
    vector<int> list2 = {1,2,4,1,NULL,3,-1,5,1,NULL,6,NULL,8};
    
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    
    int res1 = sumOfLeftLeaves1(node2);
    int res2 = sumOfLeftLeaves2(node2);
    
}
