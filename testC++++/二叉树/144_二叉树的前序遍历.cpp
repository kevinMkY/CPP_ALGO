//
//  144_二叉树的前序遍历.cpp
//  testC++++
//
//  Created by ykh on 2020/9/22.
//

#import "144_二叉树的前序遍历.hpp"
#import "common.h"

//给定一个二叉树，返回它的 前序 遍历。
//
// 示例:
//
//输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [1,2,3]
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//递归
vector<int> preorderTraversal1(TreeNode* root) {
    
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    res.push_back(root->val);
    vector<int> resleft = preorderTraversal1(root->left);
    vector<int> resright = preorderTraversal1(root->right);
    res.insert(res.end(), resleft.begin(),resleft.end());
    res.insert(res.end(), resright.begin(),resright.end());
    return res;
    }

//迭代
vector<int> preorderTraversal2(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    stack<TreeNode *> mystack;
    mystack.push(root);
    while (!mystack.empty()) {
        TreeNode *node = mystack.top();
        mystack.pop();
        res.push_back(node->val);
        if (node->right) {
            mystack.push(node->right);
        }
        if (node->left) {
            mystack.push(node->left);
        }
    }
    
    return res;
    }

void _144_test(){
    
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,NULL,2,3};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithVector(list2);
    
    vector<int> res1 = preorderTraversal1(node1);
    vector<int> res2 = preorderTraversal2(node1);
    vector<int> res3 = preorderTraversal1(node2);
    vector<int> res4 = preorderTraversal2(node2);
    
}
