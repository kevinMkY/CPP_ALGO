//
//  938_二叉搜索树的范围和.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/19.
//

#include "938_二叉搜索树的范围和.hpp"
#include "common.h"

//给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。
//
//
//
//示例 1：
//
//
//输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
//输出：32
//示例 2：
//
//
//输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
//输出：23
//
//
//提示：
//
//树中节点数目在范围 [1, 2 * 104] 内
//1 <= Node.val <= 105
//1 <= low <= high <= 105
//所有 Node.val 互不相同
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/range-sum-of-bst
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
int rangeSumBST1(TreeNode* root, int low, int high) {
    int sum = 0;
    if (root == nullptr) {
        return sum;
    }
    int val = root->val;
    int leftsum = rangeSumBST1(root->left, low, high);
    int rightsum = rangeSumBST1(root->right, low, high);
    sum = (leftsum + rightsum);
    if (low <= val && high >= val) {
        sum += val;
    }
    return sum;
    }

//迭代
int rangeSumBST2(TreeNode* root, int low, int high) {
    int sum = 0;
    if (root == nullptr) {
        return sum;
    }
    
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    
    while (!myqueue.empty()) {
        TreeNode *node = myqueue.front();
        myqueue.pop();
        int val = node->val;
        if (val >= low && val <= high) {
            sum +=val;
        }
        auto left = node->left;
        auto right = node->right;
        if (left) {
            myqueue.push(left);
        }
        if (right) {
            myqueue.push(right);
        }
        
    }
    
    return sum;
    }

void _938_test(){
    vector<int> list1 = {10,5,15,3,7,NULL,18};
    vector<int> list2 = {10,5,15,3,7,13,18,1,NULL,6};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    
    int res1 = rangeSumBST1(node1,7,15);
    int res2 = rangeSumBST1(node2,6,10);
    int res3 = rangeSumBST2(node1,7,15);
    int res4 = rangeSumBST2(node2,6,10);
    
//    int res3 = maxDepth2(node1);
//    int res4 = maxDepth2(node2);

}
