//
//  111_二叉树的最小深度.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/28.
//

#include "111_二叉树的最小深度.hpp"
#include "common.h"

//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//说明：叶子节点是指没有子节点的节点。
//
//
//
//示例 1：
//
//
//输入：root = [3,9,20,null,null,15,7]
//输出：2
//示例 2：
//
//输入：root = [2,null,3,null,4,null,5,null,6]
//输出：5
//
//
//提示：
//
//树中节点数的范围在 [0, 105] 内
//-1000 <= Node.val <= 1000
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int minDepth1(TreeNode* root) {
    int res = 0;
    if (!root) {
        return res;
    }
    auto left = root->left;
    auto right =root->right;
    auto minleft = minDepth1(left);
    auto minright = minDepth1(right);
    if (!left && !right) {  //当前为🍃
        res++;
    }else if (!left){       //当前无左
        res = minright+1;
    }else if (!right){      //当前无右
        res = minleft+1;
    }else{                  //当前左右都有
        res = min(minleft, minright)+1;
    }
    return res;
    }
int minDepth2(TreeNode* root) {
    int res = 0;
    if (!root) {
        return res;
    }
    queue<TreeNode *> nodeq;
    nodeq.push(root);
    res = 1;
    int size = 1;
    while (nodeq.size()) {
        auto node = nodeq.front();
        nodeq.pop();
        size--;
        auto left = node->left;
        auto right =node->right;
        if (!left && !right) {
            return res;
        }
        if (left){
            nodeq.push(left);
        }
        if (right) {
            nodeq.push(right);
        }
        if (size == 0) {
            size = nodeq.size();
            res++;
        }
    }
    return res;
    }

void _111_test()
{
    vector<int> list1 = {3,9,20,NULL,NULL,15,7};
    vector<int> list2 = {2,NULL,3,NULL,4,NULL,5,NULL,6};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    int res1 = minDepth1(node1);
    int res2 = minDepth1(node2);
    int res3 = minDepth2(node1);
    int res4 = minDepth2(node2);
    
}
