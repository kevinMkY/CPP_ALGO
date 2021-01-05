//
//  1325_删除给定值的叶子节点.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/30.
//

#include "1325_删除给定值的叶子节点.hpp"
#include "common.h"

//给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。
//
//注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。
//
//也就是说，你需要重复此过程直到不能继续删除。
//
//
//
//示例 1：
//
//
//
//输入：root = [1,2,3,2,null,2,4], target = 2
//输出：[1,null,3,null,4]
//解释：
//上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
//有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。
//示例 2：
//
//
//
//输入：root = [1,3,3,3,2], target = 3
//输出：[1,3,null,null,2]
//示例 3：
//
//
//
//输入：root = [1,2,null,2,null,2], target = 2
//输出：[1]
//解释：每一步都删除一个绿色的叶子节点（值为 2）。
//示例 4：
//
//输入：root = [1,1,1], target = 1
//输出：[]
//示例 5：
//
//输入：root = [1,2,3], target = 1
//输出：[1,2,3]
//
//
//提示：
//
//1 <= target <= 1000
//每一棵树最多有 3000 个节点。
//每一个节点值的范围是 [1, 1000] 。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/delete-leaves-with-a-given-value
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

bool contanLeafTarget(TreeNode* root, int target) {
 
    if (!root) {
        return false;
    }
    if (!root->left && !root->right && root->val == target) {
        return true;
    }
    bool res1 = contanLeafTarget(root->left, target);
    bool res2 = contanLeafTarget(root->right, target);
    
    return res1 || res2;
}

TreeNode* removeLeafNodes1(TreeNode* root, int target) {

    if (!root) {
        return root;
    }
    
    while (contanLeafTarget(root,target)) {
        stack<TreeNode *>mystack;
        TreeNode *temp = root;
        while (temp || mystack.size()) {
            while (temp) {
                mystack.push(temp);
                auto left = temp->left;
                auto right = temp->right;
                if (left) {
                    auto leftleft = left->left;
                    auto leftright = left->right;
                    if (!leftleft && !leftright && left->val == target) {
                        temp->left = nullptr;
                    }
                }
                if (right) {
                    auto rightleft = right->left;
                    auto rightright = right->right;
                    if (!rightleft && !rightright && right->val == target) {
                        temp->right = nullptr;
                    }
                }
                temp = temp->left;
            }
            temp = mystack.top();
            mystack.pop();
            temp = temp->right;
        }
    }
    
    return root;
    }

TreeNode* removeLeafNodes2(TreeNode* root, int target) {

    if (!root) {
        return root;
    }
    root->left = removeLeafNodes2(root->left, target);
    root->right = removeLeafNodes2(root->right, target);
    if (!root->left && !root->right && root->val== target) {
        return nullptr;
    }
    
    return root;
    }

void _1325_test()
{
    vector<int> list1 = {1,2,3,2,NULL,2,4};
    int flag1 = 2;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list1);
    
    TreeNode* res1 = removeLeafNodes1(node1,flag1);
    TreeNode* res2 = removeLeafNodes2(node2,flag1);
    
}
