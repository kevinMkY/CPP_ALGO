//
//  671_二叉树中第二小的节点.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/28.
//

#include "671_二叉树中第二小的节点.hpp"
#include "common.h"

//给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。
//
//更正式地说，root.val = min(root.left.val, root.right.val) 总成立。
//
//给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
//
//
//
//示例 1：
//
//
//输入：root = [2,2,5,null,null,5,7]
//输出：5
//解释：最小的值是 2 ，第二小的值是 5 。
//示例 2：
//
//
//输入：root = [2,2,2]
//输出：-1
//解释：最小的值是 2, 但是不存在第二小的值。
//
//
//提示：
//
//树中节点数目在范围 [1, 25] 内
//1 <= Node.val <= 231 - 1
//对于树中每个节点 root.val == min(root.left.val, root.right.val)
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int findSecondMinimumValue1ExceptVal(TreeNode* root,int val) {
    int res = val;
    if (!root) {
        return res;
    }
    
    auto left = root->left;
    auto right = root->right;
    auto rootval = root->val;
    if (left && right) {
        auto minleft = findSecondMinimumValue1ExceptVal(left, val);
        auto minright = findSecondMinimumValue1ExceptVal(right, val);
        if (val == minleft) {
            return minright;
        }else if (val == minright){
            return minleft;
        }else{
            return min(minleft, minright);
        }
    }else{
        if (rootval > val) {
            return rootval;
        }else{
            return res;
        }
    }
    
    return res;
}

//递归
int findSecondMinimumValue1(TreeNode* root) {
    int res = -1;
    if (!root) {
        return res;
    }
    res = findSecondMinimumValue1ExceptVal(root, root->val);
    if (res == root->val) {
        return -1;
    }
    return res;
    }

//迭代
int findSecondMinimumValue2(TreeNode* root) {
    int res = -1;
    if (!root) {
        return res;
    }

    queue<TreeNode *> nodeq;
    nodeq.push(root);
    int firstmin = -1;
    while (nodeq.size()) {
        auto node = nodeq.front();
        auto val = node->val;
        nodeq.pop();
        if (firstmin == -1) {
            firstmin = val; //第一次遇到val
        }else if (res == -1 && val != firstmin){
            if (val > firstmin) {
                res = val;
            }else{
                res = firstmin;
                firstmin = val;
            }
        }else if (val < firstmin){
            res = firstmin;
            firstmin = val;
        }else if (val > firstmin && val < res){
            res = val;
        }
        auto left = node->left;
        auto right = node->right;
        
        if (left) {
            nodeq.push(left);
        }
        if (right) {
            nodeq.push(right);
        }
    }
    
    return res;
    }

void _671_test()
{
    vector<int> list1 = {2,2,5,NULL,NULL,5,5};
    vector<int> list2 = {2,2,2};
    vector<int> list3 = {1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1};
    TreeNode *node1 = initTreeWithNULLVector(list1);
    TreeNode *node2 = initTreeWithNULLVector(list2);
    TreeNode *node3 = initTreeWithNULLVector(list3);
    
    int res1 = findSecondMinimumValue1(node1);
    int res2 = findSecondMinimumValue1(node2);
    int res3 = findSecondMinimumValue2(node1);
    int res4 = findSecondMinimumValue2(node2);
    int res5 = findSecondMinimumValue1(node3);
    
}
