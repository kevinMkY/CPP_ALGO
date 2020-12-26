//
//  653_两数之和 IV - 输入 BST.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/24.
//

#include "653_两数之和 IV - 输入 BST.hpp"
#include "common.h"

//给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
//
//案例 1:
//
//输入:
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 9
//
//输出: True
//
//
//案例 2:
//
//输入:
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 28
//
//输出: False
//
//
//通过次数25,261提交次数44,034
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> inorderNodelist(TreeNode* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    
    auto val = root->val;
    auto leftres = inorderNodelist(root->left);
    auto rightres = inorderNodelist(root->right);
    res.insert(res.end(), leftres.begin(),leftres.end());
    res.push_back(val);
    res.insert(res.end(), rightres.begin(),rightres.end());
    
    return res;
    }

bool findTarget1(TreeNode* root, int k) {
    if (!root) {
        return false;
    }
    vector<int> res = inorderNodelist(root);
    auto ressize = res.size();
    for (int i = 0; i<ressize; i++) {
        auto firstval = res[i];
        for (int j = i+1; j<ressize; j++) {
            auto secval = res[j];
            if (firstval + secval == k) {
                return true;
            }
        }
    }
    return false;
    }

bool findTarget2(TreeNode* root, int k) {
    if (!root) {
        return false;
    }
    set<int> set1;
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        auto val = node->val;
        if (set1.count(k-val) > 0) {
            return true;
        }
        set1.insert(val);
        if (node->left) {
            myqueue.push(node->left);
        }
        if (node->right) {
            myqueue.push(node->right);
        }
    }
    return false;
    }

void _653_test()
{
    vector<int> list1 = {5,3,6,2,4,NULL,7};
    int flag1 = 9;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    bool res1 = findTarget1(node1,flag1);
    bool res2 = findTarget2(node1,flag1);
    
    
}
