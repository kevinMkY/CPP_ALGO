//
//  1302_层数最深叶子节点的和.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/28.
//

#include "1302_层数最深叶子节点的和.hpp"
#include "common.h"

//给你一棵二叉树，请你返回层数最深的叶子节点的和。
//
//
//
//示例：
//
//
//
//输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
//输出：15
//
//
//提示：
//
//树中节点数目在 1 到 10^4 之间。
//每个节点的值在 1 到 100 之间。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/deepest-leaves-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int deepestNode(TreeNode *root,int &depth){
    if (!root) {
        return 0;
    }
    auto val = root->val;
    int depthleft = depth+1;
    int depthright = depth+1;
    int leftval = deepestNode(root->left, depthleft);
    int rightval = deepestNode(root->right, depthright);
    if (root->left && root->right) {
        if (depthleft == depthright) {
            depth = depthleft;
            return leftval+rightval;
        }else if(depthleft > depthright) {
            depth = depthleft;
            return leftval;
        }else{
            depth = depthright;
            return rightval;
        }
    }else if (root->left){
        depth = depthleft;
        return leftval;
    }else if (root->right){
        depth = depthright;
        return rightval;
    }else{
        return val;
    }
}

int deepestLeavesSum1(TreeNode* root) {
    int res = 0;
    if (!root) {
        return res;
    }
    int depath = 1;
    res = deepestNode(root,depath);
    return res;
    }

int deepestLeavesSum2(TreeNode* root) {
    int res = 0;
    if (!root) {
        return res;
    }
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    int size = 1;
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        size--;
        auto left = node->left;
        auto right = node->right;
        if (left ) {
            myqueue.push(left);
        }
        if (right) {
            myqueue.push(right);
        }
        if (!left && !right) {
            res+=node->val;
        }
        if (size == 0) {
            size = myqueue.size();
            if (size > 0) {
                res = 0;
            }
        }
    }
    return res;
    }

void _1302_test()
{
    vector<int> list1 = {1,2,3,4,5,NULL,6,7,NULL,NULL,NULL,NULL,8};
    
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    int res1 = deepestLeavesSum1(node1);
    int res2 = deepestLeavesSum2(node1);
    
}
