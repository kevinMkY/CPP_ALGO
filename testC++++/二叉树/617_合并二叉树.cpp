//
//  617_合并二叉树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/17.
//

#include "617_合并二叉树.hpp"
#include "common.h"

//给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
//
//你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
//
//示例 1:
//
//输入:
//    Tree 1                     Tree 2
//          1                         2
//         / \                       / \
//        3   2                     1   3
//       /                           \   \
//      5                             4   7
//输出:
//合并后的树:
//         3
//        / \
//       4   5
//      / \   \
//     5   4   7
//注意: 合并必须从两个树的根节点开始。
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/merge-two-binary-trees
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
TreeNode* mergeTrees1(TreeNode* t1, TreeNode* t2) {

    TreeNode* res;
    if (t1 == nullptr && t2 == nullptr) {
        return res;
    }else if (t1 == nullptr){
        return t2;
    }else if (t2 == nullptr){
        return t1;
    }else{
        int val = t1->val+t2->val;
        TreeNode *left = mergeTrees1(t1->left, t2->left);
        TreeNode *right = mergeTrees1(t1->right, t2->right);
        res = new TreeNode(val,left,right);
    }
    return res;
    }

//迭代---每次将下一批需要连接left-right的点入栈,当前点直接操作连接left,right
TreeNode* mergeTrees2(TreeNode* t1, TreeNode* t2) {

    TreeNode* res;
    if (!t1) {
        return t2;
    }
    if (!t2) {
        return t1;
    }
    
    res = new TreeNode(t1->val+t2->val);
    auto resQueue = queue<TreeNode *>();
    auto queue1 = queue<TreeNode *>();
    auto queue2 = queue<TreeNode *>();
    resQueue.push(res);
    queue1.push(t1);
    queue2.push(t2);
    while (!queue1.empty() || !queue2.empty()) {
        auto node = resQueue.front();
        auto node1 = queue1.front();
        auto node2 = queue2.front();
        resQueue.pop();
        queue1.pop();
        queue2.pop();
        
        auto left1 = node1->left;
        auto left2 = node2->left;
        if (left1 && left2) {
            auto nextleft = new TreeNode(left1->val + left2->val);
            node->left = nextleft;
            resQueue.push(nextleft);
            queue1.push(left1);
            queue2.push(left2);
        }else if (left1){
            node->left = left1;
        }else if (left2){
            node->left = left2;
        }
        
        auto right1 = node1->right;
        auto right2 = node2->right;
        if (right1 && right2) {
            auto nextright = new TreeNode(right1->val + right2->val);
            node->right = nextright;
            resQueue.push(nextright);
            queue1.push(right1);
            queue2.push(right2);
        }else if (right1){
            node->right = right1;
        }else if (right2){
            node->right = right2;
        }
    }
    
    return res;
}


void _617_test(){
    
    vector<int> list1 = {1,3,2,5};
    vector<int> list2 = {2,1,3,NULL,4,NULL,7};
    TreeNode* t1 = initTreeWithNULLVector(list1);
    TreeNode* t2 = initTreeWithNULLVector(list2);

    TreeNode *res1 = mergeTrees1(t1, t2);
    TreeNode *res2 = mergeTrees2(t1, t2);
    
}

