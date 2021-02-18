//
//  669_修剪二叉搜索树.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/21.
//

#import "669_修剪二叉搜索树.hpp"
#import "common.h"

//给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树不应该改变保留在树中的元素的相对结构（即，如果没有被移除，原有的父代子代关系都应当保留）。 可以证明，存在唯一的答案。
//
//所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。
//
//
//
//示例 1：
//
//
//输入：root = [1,0,2], low = 1, high = 2
//输出：[1,null,2]
//示例 2：
//
//
//输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
//输出：[3,2,null,1]
//示例 3：
//
//输入：root = [1], low = 1, high = 2
//输出：[1]
//示例 4：
//
//输入：root = [1,null,2], low = 1, high = 3
//输出：[1,null,2]
//示例 5：
//
//输入：root = [1,null,2], low = 2, high = 4
//输出：[2]
//
//
//提示：
//
//树中节点数在范围 [1, 104] 内
//0 <= Node.val <= 104
//树中每个节点的值都是唯一的
//题目数据保证输入是一棵有效的二叉搜索树
//0 <= low <= high <= 104
//通过次数21,187提交次数31,588
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/trim-a-binary-search-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
TreeNode* trimBST1(TreeNode* root, int low, int high) {

    TreeNode* res = nullptr;
    if (!root) {
        return res;
    }
    int val = root->val;
    auto left = root->left;
    auto right = root->right;
    auto trimleft = trimBST1(left, low, high);
    auto trimright = trimBST1(right, low, high);
    auto trimleftval = -1;
    auto trimrightval = -1;
    if (trimleft) {
        trimleftval = trimleft->val;
    }
    if (trimright) {
        trimrightval = trimright->val;
    }
    if (val >= low && val <= high) {
        root->left = trimleft;
        root->right = trimright;
        res = root;
    }else if (trimleftval >= low && trimleftval <= high){
        res = trimleft;
    }else if (trimrightval >= low && trimrightval <= high){
        res = trimright;
    }
    
    return res;
    }

//迭代
//--->搜索树的特点----》左节点《中节点〈右节点,
//所以中节点《最小,则直接剪掉整个左节点,
//所以中节点》最大,则直接剪掉整个右节点,
TreeNode* trimBST2(TreeNode* root, int low, int high) {

    if (!root) {
        return root;
    }
    
    //先把root规范
    while (root && (root->val < low || root->val > high)) {
        if (root->val < low) {
            root = root->right;
        }
        if (root->val > high) {
            root = root->left;
        }
    }
    auto cur = root;
    //再把left规范
    while (cur) {
        while (cur->left && cur->left->val <low) {
            cur->left = cur->left->right;
        }
        cur = cur->left;
    }
    
    cur = root;
    //再把right规范
    while (cur) {
        while (cur->right && cur->right->val > high) {
            cur->right = cur->right->left;
        }
        cur= cur->right;
    }
    
    return root;
    }

void _669_test()
{
    vector<int> list1 = {3,2,4};
    int flag1 = 3;
    int flag2 = 4;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
//    TreeNode*  res1 = trimBST1(node1,flag1,flag2);
    TreeNode*  res2 = trimBST2(node1,flag1,flag2);
    
}
