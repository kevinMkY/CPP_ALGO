//
//  112_路径总和.cpp
//  testC++++
//
//  Created by yekaihua on 2020/12/27.
//

#include "112_路径总和.hpp"
#include "common.h"
//
//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
//
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//给定如下二叉树，以及目标和 sum = 22，
//
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1
//返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/path-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> leafpathsum(TreeNode *root){
    vector<int>res;
    if (!root) {
        return res;
    }
    auto left = root->left;
    auto right = root->right;
    if (!left && !right) {  //当前为🍃
        return {root->val};
    }else{                  //当前不为叶子
        auto leftleafpathsum = leafpathsum(left);
        auto rightleafpathsum = leafpathsum(right);
        res.insert(res.end(), leftleafpathsum.begin(),leftleafpathsum.end());
        res.insert(res.end(), rightleafpathsum.begin(),rightleafpathsum.end());
        auto size = res.size();
        for (int i = 0; i<size; i++) {
            res[i] += root->val;
        }
        return res;
    }
}

//递归一,算出每条路径的和,最后看和在不在结果离
bool hasPathSum1(TreeNode* root, int sum) {
    bool res;
    if (!root) {
        return res;
    }
    vector<int> sumpath = leafpathsum(root);
    for (int i = 0; i<sumpath.size(); i++) {
        if (sum == sumpath[i]) {
            return true;
        }
    }
    return false;
    }

//递归2,从上往下,每下一层就减去当前val,直到叶子结点,看是否满足
bool hasPathSum2(TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    auto left = root->left;
    auto right = root->right;
    if (!left && !right) {  //🍃
        return root->val == sum;
    }else{
        bool res1 = hasPathSum2(root->left,sum-root->val);
        bool res2 = hasPathSum2(root->right,sum-root->val);
        return res1 || res2;
    }
    }

//迭代--利用队列保存跟节点到当前🍃节点的路径和
bool hasPathSum3(TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    
    queue<TreeNode *>myqueue;
    myqueue.push(root);
    queue<int> sumqueue;
    sumqueue.push(root->val);
    while (myqueue.size()) {
        auto node = myqueue.front();
        myqueue.pop();
        auto left = node->left;
        auto right = node->right;
        auto val = node->val;
        auto sumval = sumqueue.front();
        sumqueue.pop();
        if (!left && !right && sumval== sum) {
            return true;
        }
        if (left) {
            myqueue.push(left);
            sumqueue.push(left->val+sumval);
            if (!left->left && !left->right && left->val+sumval == sum) {
                return true;
            }
        }
        if (right) {
            myqueue.push(right);
            sumqueue.push(right->val+sumval);
            if (!right->left && !right->right && right->val+sumval == sum) {
                return true;
            }
        }
    }
    
    return false;
    }

void _112_test()
{
    vector<int> list1 = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,NULL,1};
    int flag1 = 22;
    TreeNode *node1 = initTreeWithNULLVector(list1);
    
    bool res1 = hasPathSum1(node1,flag1);
    bool res2 = hasPathSum2(node1,flag1);
    bool res3 = hasPathSum3(node1,flag1);
    
}
