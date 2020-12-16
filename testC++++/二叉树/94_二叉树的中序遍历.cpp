//
//  94_二叉树的中序遍历.cpp
//  testC++++
//
//  Created by ykh on 2020/9/22.
//

#include "94_二叉树的中序遍历.hpp"
#include "common.h"

//给定一个二叉树，返回它的中序 遍历。
//
//示例:
//
//输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [1,3,2]
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//递归
vector<int> inorderTraversal1(TreeNode* root) {

    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    //
    vector<int> resleft = inorderTraversal1(root->left);
    res.insert(res.end(), resleft.begin(),resleft.end());
    //
    res.push_back(root->val);
    //
    vector<int> resright = inorderTraversal1(root->right);
    res.insert(res.end(), resright.begin(),resright.end());
    
    return res;
    }

//迭代--先沿着left一直找到最下面那个叶子,找到之前将root(中)一直入站
vector<int> inorderTraversal2(TreeNode* root) {

    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    
    stack<TreeNode *>mystack;
    while (root||!mystack.empty()) {
        while (root) {
            mystack.push(root);
            root = root->left;
        }
        root = mystack.top();
        res.push_back(root->val);
        mystack.pop();
        root = root->right;
    }
    
    return res;
    }

//方法3,迭代,给每个数据标记一下,之前是否已经遍历过
vector<int> inorderTraversal3(TreeNode* root) {

    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    stack<pair<TreeNode *, int>>mystack;
    mystack.push({root,0});
    while (!mystack.empty()) {
        TreeNode *node = mystack.top().first;
        int flag = mystack.top().second;
        mystack.pop();
        if (node == nullptr) {
            continue;
        }
        if (flag == 0) {
            mystack.push({node->right,0});
            mystack.push({node,1});
            mystack.push({node->left,0});
        }else{
            res.push_back(node->val);
        }
    }
    return res;
    }

void _94_test(){
    
    vector<int> list1 = {4,2,7,1,3,6,9};
    vector<int> list2 = {1,NULL,2,3};
    TreeNode *node1 = initTreeWithVector(list1);
    TreeNode *node2 = initTreeWithVector(list2);
    
    vector<int> res1 = inorderTraversal1(node1);
    vector<int> res2 = inorderTraversal1(node2);
    vector<int> res3 = inorderTraversal2(node1);
    vector<int> res4 = inorderTraversal2(node2);
    vector<int> res5 = inorderTraversal3(node1);
    vector<int> res6 = inorderTraversal3(node2);
    
}
